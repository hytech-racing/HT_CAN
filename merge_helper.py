# This script helps with loading and merging dbc files with hytech's pcan symbol file
import cantools
import cantools.database

base_db = cantools.database.load_file('PCAN_project/hytech.sym')
new_db = cantools.database.load_file('imported_dbcs/hv500_can2_map_v25_SID.dbc')
base_db.add_dbc_file('imported_dbcs/hv500_can2_map_v25_SID.dbc')

cantools.database.dump_file(base_db, 'PCAN_project/hytech.sym')
print(f"Merged {len(new_db.messages)} DTI messages into hytech.sym")