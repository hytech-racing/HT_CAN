#!/usr/bin/env python
import cantools
from cantools.database import *
import pkg_resources
import sys


class HyTechCANmsg:
    def __init__(self):
        self.can_id_name = ""
        self.can_id_hex = 0x0
        self.sender_name = ""
        self.packing_type = ""
        self.signals = [can.signal.Signal]
# 
def create_field_name(name: str) -> str:
    replaced_text = name.replace(" ", "_")
    replaced_text = replaced_text.replace("(", "")
    replaced_text = replaced_text.replace(")", "")
    return replaced_text

def append_proto_message_from_CAN_message(file, can_msg: can.message.Message):
    # if the msg has a conversion, we know that the value with be a float

    enum_definitions = []

    for sig in can_msg.signals:
        if sig.choices != None and sig.length != 1:
            enum_name = can_msg.name.lower() + "_" + create_field_name(sig.name) + "_enum"
            enum_def = (f"enum {enum_name}")
            enum_def += (f" {{")
            enum_def += ("\n")

            field_name = "test"

            for choice_value, choice_name in sig.choices.items():
                choice_name_enum = create_field_name(str(choice_name).upper())
                enum_def += (f"    {choice_name_enum} = {choice_value};\n")
            enum_def += ("}\n\n")

            enum_definitions.append(enum_def)
        

    for enum_def in enum_definitions:
            file.write(enum_def)


    msgname = can_msg.name
    line = ""
    # type and then name
    file.write("message " + msgname.lower() + " {\n")
    line_index = 0

    for sig in can_msg.signals:
        line_index += 1
        
        if sig.is_float or ((sig.scale is not None) and (sig.scale != 1.0)) or (
            type(sig.conversion)
            is not type(conversion.IdentityConversion(is_float=False))
            and not type(
                conversion.NamedSignalConversion(
                    choices={}, scale=0, offset=0, is_float=False
                )
            )
        ):
            line = (
                "    float "
                + create_field_name(sig.name)
                + " = "
                + str(line_index)
                + ";"
            )

        elif sig.choices != None and sig.length != 1:
            enum_name = f"{can_msg.name.lower()}_{field_name}_enum"
            file.write(f"    {enum_name} {field_name} = {line_index};\n")
            
        elif sig.length == 1:
            line = (
                "    bool "
                + create_field_name(sig.name)
                + " = "
                + str(line_index)
                + ";"
            )

        elif (sig.length > 1 and sig.length <=32):
            line = (
                "    int32 "
                + create_field_name(sig.name)
                + " = "
                + str(line_index)
                + ";"
            )
        elif (sig.length >= 32 and not sig.is_signed):
            line = (
                "    uint64 "
                + create_field_name(sig.name)
                + " = "
                + str(line_index)
                + ";"
            )
        else:
            line = (
                "    int64 "
                + create_field_name(sig.name)
                + " = "
                + str(line_index)
                + ";"
            )
            
        file.write(line + "\n")
    file.write("}\n\n")
    return file

# load dbc file from the package location

if(len (sys.argv) > 1):
    path_to_dbc = sys.argv[1]
else:
    path_to_dbc = os.environ.get('DBC_PATH')
full_path = os.path.join(path_to_dbc, "hytech.dbc")
db = cantools.database.load_file(full_path)
with open("hytech.proto", "w+") as proto_file:
    proto_file.write('syntax = "proto3";\n\n')
    proto_file.write('package hytech;\n\n')
    for msg in db.messages:
        proto_file = append_proto_message_from_CAN_message(proto_file, msg)