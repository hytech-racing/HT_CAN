#!/usr/bin/env python3
"""Re-apply CAN FD flags to the DBC generated from hytech.sym.

hytech.sym marks FD messages correctly (Type=FD Standard, Bit Rate Switch), but
cantools' sym parser has no FD support: it accepts only ID, Len, Mux, CycleTime,
Timeout, MinInterval, Color, Sig, Var and Type, and never sets is_fd. A message's
Len does survive, so a 64 byte FD message arrives in the DBC as a 64 byte
*classical* frame, which is malformed.

This script runs after 'cantools convert' and restores what was dropped.

Usage: mark_canfd.py <in.dbc> <out.dbc>
"""

import sys

import cantools
from cantools.database.can.attribute import Attribute
from cantools.database.can.attribute_definition import AttributeDefinition

# Messages marked "FD Standard" / "FD Extended" in hytech.sym. Keep in sync by
# hand; cantools gives us no way to read the flag back out of the sym.
FD_MESSAGES = [
    "FD_TEST",
]

# Legal CAN FD payload sizes. coderdbc generates code for any length, so an
# illegal one is not caught until the controller pads the frame and the receiver
# reads trailing garbage.
VALID_FD_LENGTHS = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64}


def main(argv):
    if len(argv) != 3:
        print(__doc__, file=sys.stderr)
        return 2

    in_path, out_path = argv[1:]
    db = cantools.database.load_file(in_path)
    messages = {message.name: message for message in db.messages}

    unknown = [name for name in FD_MESSAGES if name not in messages]
    if unknown:
        print(f"mark_canfd: ERROR not in the DBC: {', '.join(unknown)}",
              file=sys.stderr)
        return 1

    for name in FD_MESSAGES:
        length = messages[name].length
        if length not in VALID_FD_LENGTHS:
            print(f"mark_canfd: ERROR {name} has Len={length}, not a legal CAN "
                  f"FD DLC (0-8, 12, 16, 20, 24, 32, 48, 64)", file=sys.stderr)
            return 1

    # Declaring the network FD capable is what makes cantools' DBC writer emit
    # the VFrameFormat and CANFD_BRS attribute definitions at all. Frame format
    # stays per message, so anything not in FD_MESSAGES remains classical.
    bus_type = AttributeDefinition("BusType", default_value="", kind=None,
                                   type_name="STRING")
    db.dbc.attribute_definitions["BusType"] = bus_type
    db.dbc.attributes["BusType"] = Attribute("CAN FD", bus_type)

    for name in FD_MESSAGES:
        messages[name]._is_fd = True  # cantools exposes no public setter
        print(f"mark_canfd: {name} -> CAN FD, {messages[name].length} bytes")

    with open(out_path, "w") as out_file:
        out_file.write(db.as_dbc_string())

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
