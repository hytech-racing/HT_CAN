import re
import json
import shlex


def parse_sym_to_json(sym_filepath):
    enums_db = {}
    signals_db = {}
    messages_db = []

    with open(sym_filepath, "r") as file:
        content = file.read()

    # --- 1. Split the File ---
    if "{SENDRECEIVE}" not in content:
        print("Error: '{SENDRECEIVE}' block not found in sym file.")
        return

    signals_block, messages_block = content.split("{SENDRECEIVE}", 1)

    # --- 2. Parse Enums ---
    enum_matches = re.findall(r"^Enum=([^\(]+)\(([^)]+)\)", signals_block, re.MULTILINE)

    for name, values_str in enum_matches:
        name = name.strip()
        values_str = values_str.split("//")[0].strip()

        lexer = shlex.shlex(values_str, posix=True)
        lexer.whitespace = " (),\n\r"
        lexer.whitespace_split = True
        tokens = list(lexer)

        if not tokens:
            continue

        enum_dict = {}
        for token in tokens:
            if "=" in token:
                key, val = token.split("=", 1)
                enum_dict[int(key)] = val.replace('"', "")

        enums_db[name] = enum_dict

    # --- 3. Parse Signals ---
    signal_lines = re.findall(r"^Sig=(.+)$", signals_block, re.MULTILINE)

    for line in signal_lines:
        parts = line.split("//")
        sig_str = parts[0].strip()
        comment = parts[1].strip() if len(parts) > 1 else ""

        try:
            tokens = shlex.split(sig_str)
        except ValueError:
            tokens = sig_str.split()

        if not tokens:
            continue

        name = tokens[0]
        type_str = tokens[1] if len(tokens) > 1 else "unsigned"

        # Initial defaults
        length = 1
        is_signed = False
        is_float = False
        is_big_endian = False
        scale = 1.0
        offset = 0.0
        unit = ""
        min_val = None
        max_val = None
        enum_ref = None

        # Cross-reference the type keyword with known enums
        if type_str in enums_db:
            enum_ref = type_str
        elif type_str == "float":
            length = 32
            is_signed = True
            is_float = True
        elif type_str == "double":
            length = 64
            is_signed = True
            is_float = True
        elif type_str == "signed":
            is_signed = True
        elif type_str == "bit":
            length = 1

        # Check if the next token is an explicit length integer
        idx = 2
        if idx < len(tokens) and tokens[idx].isdigit():
            length = int(tokens[idx])
            idx += 1

        # Parse remaining modifiers sequentially
        for token in tokens[idx:]:
            if token == "-m":
                is_big_endian = True
            elif token.startswith("/f:"):
                scale = float(token[3:])
            elif token.startswith("/o:"):
                offset = float(token[3:])
            elif token.startswith("/u:"):
                unit = token[3:]
            elif token.startswith("/min:"):
                min_val = float(token[5:])
            elif token.startswith("/max:"):
                max_val = float(token[5:])
            elif token.startswith("/e:"):
                enum_ref = token[3:]

        signals_db[name] = {
            "length": length,
            "is_signed": is_signed,
            "is_float": is_float,
            "is_big_endian": is_big_endian,
            "scale": scale,
            "offset": offset,
            "unit": unit,
            "min": min_val,
            "max": max_val,
            "enum": enum_ref,
            "description": comment,
        }

    # --- 4. Parse Messages ---
    message_blocks = re.split(r"\[(.*?)\]", messages_block)[1:]

    for i in range(0, len(message_blocks), 2):
        msg_name = message_blocks[i].strip()
        msg_body = message_blocks[i + 1].strip().split("\n")

        msg_id = ""
        dlc = 8
        is_extended = False
        msg_comment = ""
        msg_signals = []

        for line in msg_body:
            line = line.strip()
            if not line:
                continue

            if line.startswith("ID="):
                id_part = line.split("//")
                id_str = id_part[0].split("=")[1].strip().replace("h", "")
                msg_id = f"0x{id_str}"
                if len(id_part) > 1:
                    msg_comment = id_part[1].strip()
            elif line.startswith("Len="):
                dlc = int(line.split("=")[1])
            elif line.startswith("Type=Extended"):
                is_extended = True
            elif line.startswith("Sig="):
                sig_parts = line.split("=")[1].split()
                sig_name = sig_parts[0]
                start_bit = int(sig_parts[1])
                msg_signals.append({"name": sig_name, "start_bit": start_bit})

        if msg_id:
            messages_db.append(
                {
                    "name": msg_name,
                    "id": msg_id,
                    "is_extended": is_extended,
                    "dlc": dlc,
                    "description": msg_comment,
                    "signals": msg_signals,
                }
            )

    # --- 5. Export to JSON ---
    with open("json_lib/enums.json", "w") as f:
        json.dump(enums_db, f, indent=2)

    with open("json_lib/signals.json", "w") as f:
        json.dump(signals_db, f, indent=2)

    with open("json_lib/messages.json", "w") as f:
        json.dump(messages_db, f, indent=2)

    print("Successfully generated enums.json, signals.json, and messages.json")


if __name__ == "__main__":
    parse_sym_to_json("PCAN_project/hytech.sym")
