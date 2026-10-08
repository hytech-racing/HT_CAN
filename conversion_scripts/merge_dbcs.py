"""Merge a generated DBC with protected imported DBCs.

Usage: python conversion_scripts/merge_dbcs.py FIRST.dbc IMPORTED.dbc [...] -o merged.dbc
"""

import argparse
import copy
from itertools import chain
from pathlib import Path

import cantools
from cantools.database import can


def next_free_id(start, used, extended):
    limit = 0x1FFFFFFF if extended else 0x7FF
    # Search above the conflicting ID first, then wrap within the same ID space.
    for candidate in chain(range(start + 1, limit + 1), range(0, start)):
        if (extended, candidate) not in used:
            return candidate
    raise ValueError(f"No free {'extended' if extended else 'standard'} CAN IDs")


def merge(first_path, second_paths):
    first = cantools.database.load_file(first_path, strict=True)
    imports = [(path, cantools.database.load_file(path, strict=True)) for path in second_paths]
    first = copy.deepcopy(first)

    protected_ids = {}
    protected_names = {}
    for path, database in imports:
        for msg in database.messages:
            key = (msg.is_extended_frame, msg.frame_id)
            if key in protected_ids:
                other_path, other_name = protected_ids[key]
                raise ValueError(
                    f"Imported DBC conflict: {other_name} in {other_path} and "
                    f"{msg.name} in {path} both use {msg.frame_id:#x}"
                )
            if msg.name in protected_names:
                raise ValueError(
                    f"Imported DBC message name {msg.name} occurs in both "
                    f"{protected_names[msg.name]} and {path}"
                )
            protected_ids[key] = (path, msg.name)
            protected_names[msg.name] = path

    imported_messages = [msg for _, database in imports for msg in database.messages]
    used = {(m.is_extended_frame, m.frame_id) for m in first.messages + imported_messages}
    all_names = {m.name for m in first.messages + imported_messages}

    for msg in first.messages:
        key = (msg.is_extended_frame, msg.frame_id)
        if key in protected_ids:
            old_id = msg.frame_id
            msg.frame_id = next_free_id(old_id, used, msg.is_extended_frame)
            used.add((msg.is_extended_frame, msg.frame_id))
            second_path, protected_name = protected_ids[key]
            print(
                f"WARNING: {msg.name} in {first_path} moved from {old_id:#x} "
                f"to {msg.frame_id:#x}; {protected_name} in {second_path} keeps {old_id:#x}"
            )
        if msg.name in protected_names:
            old_name = msg.name
            suffix = 1
            while f"{old_name}_from_first_{suffix}" in all_names:
                suffix += 1
            msg.name = f"{old_name}_from_first_{suffix}"
            all_names.add(msg.name)
            print(f"WARNING: message {old_name} in {first_path} renamed to {msg.name}")

    nodes = list(first.nodes)
    node_names = {node.name for node in nodes}
    for _, database in imports:
        for node in database.nodes:
            if node.name not in node_names:
                nodes.append(node)
                node_names.add(node.name)

    dbc_specifics = copy.deepcopy(first.dbc)
    for _, database in imports:
        for name, definition in database.dbc.attribute_definitions.items():
            if name in dbc_specifics.attribute_definitions and dbc_specifics.attribute_definitions[name] != definition:
                raise ValueError(f"Conflicting DBC attribute definition: {name}")
            dbc_specifics.attribute_definitions[name] = definition

    buses = list(first.buses)
    bus_names = {bus.name for bus in buses}
    for _, database in imports:
        for bus in database.buses:
            if bus.name not in bus_names:
                buses.append(bus)
                bus_names.add(bus.name)

    return can.Database(
        messages=first.messages + imported_messages,
        nodes=nodes,
        buses=buses,
        version=first.version,
        dbc_specifics=dbc_specifics,
        strict=True,
        sort_signals=None,
    )


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("first", type=Path, help="DBC whose conflicting IDs may move")
    parser.add_argument("second", type=Path, nargs="+", help="imported DBCs whose IDs remain unchanged")
    parser.add_argument("-o", "--output", type=Path, default=Path("merged.dbc"))
    args = parser.parse_args()
    if args.output.resolve() in {args.first.resolve(), *(path.resolve() for path in args.second)}:
        parser.error("output must differ from both input files")

    merged = merge(args.first, args.second)
    cantools.database.dump_file(merged, args.output, database_format="dbc")
    # Confirm the serialized output still has every message and unique IDs.
    check = cantools.database.load_file(args.output, strict=True)
    if len(check.messages) != len(merged.messages):
        raise RuntimeError("Merged DBC lost messages during serialization")
    print(f"Wrote {len(check.messages)} messages to {args.output}")


if __name__ == "__main__":
    main()
