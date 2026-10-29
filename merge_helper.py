# This script loads external DBC files and merges them directly into HyTech's modular JSON library
import json
import os
import cantools


def merge_dbc_to_json(dbc_filepath):
    # Ensure json_lib directories exist
    os.makedirs("json_lib", exist_ok=True)

    # Load existing modular JSON databases
    enum_path = "json_lib/enums.json"
    signal_path = "json_lib/signals.json"
    message_path = "json_lib/messages.json"

    enums_db = json.load(open(enum_path, "r")) if os.path.exists(enum_path) else {}
    signals_db = (
        json.load(open(signal_path, "r")) if os.path.exists(signal_path) else {}
    )
    messages_db = (
        json.load(open(message_path, "r")) if os.path.exists(message_path) else []
    )

    # Load the external DBC file using cantools
    ext_db = cantools.database.load_file(dbc_filepath)

    # Reject conflicts before changing any of the source JSON files. CAN IDs are
    # unique within their standard/extended frame namespace, regardless of name.
    existing_msg_names = {msg["name"] for msg in messages_db}
    existing_msg_ids = {}
    for msg in messages_db:
        frame_id = int(msg["id"], 0) if isinstance(msg["id"], str) else msg["id"]
        existing_msg_ids[(msg.get("is_extended", False), frame_id)] = msg["name"]
    conflicts = []
    incoming_names = set()
    incoming_ids = set()
    incoming_signals = set()
    for msg in ext_db.messages:
        key = (msg.is_extended_frame, msg.frame_id)
        if msg.name in existing_msg_names or msg.name in incoming_names:
            conflicts.append(f"message name {msg.name} already exists")
        if key in existing_msg_ids:
            conflicts.append(
                f"CAN ID {msg.frame_id:#x} ({'extended' if msg.is_extended_frame else 'standard'}) "
                f"is used by {existing_msg_ids[key]} and {msg.name}"
            )
        elif key in incoming_ids:
            conflicts.append(f"CAN ID {msg.frame_id:#x} occurs twice in the import")
        incoming_names.add(msg.name)
        incoming_ids.add(key)
        for sig in msg.signals:
            if sig.name in signals_db or sig.name in incoming_signals:
                conflicts.append(f"signal name {sig.name} already exists")
            incoming_signals.add(sig.name)
    if conflicts:
        raise ValueError("Cannot merge DBC:\n" + "\n".join(conflicts))

    for msg in ext_db.messages:
        msg_signals = []

        for sig in msg.signals:
            # Handle enums/choices if present on the external signal
            enum_ref = None
            if sig.choices:
                enum_name = f"{msg.name}_{sig.name}_choices"
                # Convert choice keys to strings for JSON compatibility
                enums_db[enum_name] = {str(k): v for k, v in sig.choices.items()}
                enum_ref = enum_name

            # Map cantools signal properties to your schema format
            signals_db[sig.name] = {
                "length": sig.length,
                "is_signed": sig.is_signed,
                "is_float": sig.is_float,
                "is_big_endian": (sig.byte_order == "big_endian"),
                "scale": sig.scale,
                "offset": sig.offset,
                "unit": sig.unit if sig.unit else "",
                "min": sig.minimum,
                "max": sig.maximum,
                "enum": enum_ref,
                "description": sig.comment if sig.comment else "",
            }

            msg_signals.append({"name": sig.name, "start_bit": sig.start})

        # Append message if it doesn't already exist in the registry
        if msg.name not in existing_msg_names:
            messages_db.append(
                {
                    "name": msg.name,
                    "id": hex(msg.frame_id),
                    "is_extended": msg.is_extended_frame,
                    "dlc": msg.length,
                    "description": msg.comment if msg.comment else "",
                    "signals": msg_signals,
                }
            )
            existing_msg_names.add(msg.name)
        else:
            print(f"Skipping message {msg.name} (already exists in library)")

    # Save back out to the modular JSON library files
    with open(enum_path, "w") as f:
        json.dump(enums_db, f, indent=2)

    with open(signal_path, "w") as f:
        json.dump(signals_db, f, indent=2)

    with open(message_path, "w") as f:
        json.dump(messages_db, f, indent=2)

    print(f"Successfully merged {dbc_filepath} into JSON files under json_lib/")


if __name__ == "__main__":
    merge_dbc_to_json("imported_dbcs/SpeedBeam_bus1.dbc")
