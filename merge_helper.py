# This script helps with loading and merging dbc files with hytech's pcan symbol file
import cantools
import cantools.database

base_db = cantools.database.load_file('PCAN_project/hytech.sym')
new_db = cantools.database.load_file('PCAN_project/dti_hv500.dbc')
base_db.add_dbc_file('PCAN_project/dti_hv500.dbc')

cantools.database.dump_file(base_db, 'PCAN_project/hytech.sym')
print(f"Merged {len(new_db.messages)} DTI messages into hytech.sym")