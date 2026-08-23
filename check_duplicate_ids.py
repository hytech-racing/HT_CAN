# Checks for CAN frame ID collisions between hytech.sym and a imported dbc
# before they get merged together.
import sys
import cantools
import cantools.database

base_db = cantools.database.load_file('PCAN_project/hytech.sym')
new_db = cantools.database.load_file('imported_dbcs/hv500_can2_map_v25_SID.dbc')

base_ids = {m.frame_id: m.name for m in base_db.messages}
new_ids = {m.frame_id: m.name for m in new_db.messages}

collisions = base_ids.keys() & new_ids.keys()
if collisions:
    print("Duplicate CAN IDs found:")
    for frame_id in sorted(collisions):
        print(f"  0x{frame_id:X} ({frame_id}): '{base_ids[frame_id]}' vs '{new_ids[frame_id]}'")
    sys.exit(1)

print("No duplicate IDs found.")