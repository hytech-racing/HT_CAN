import re
import json


def parse_sym_to_json(sym_filepath):
    signals_db = {}
    messages_db = []

    with open(sym_filepath, "r") as file:
        content = file.read()

    # --- 1. Parse Signals ---
    # Matches: Sig=name type length [-m] [/u:unit] [/f:factor] [/o:offset] [// comment]
    signal_lines = re.findall(r"^Sig=(.+)$", content, re.MULTILINE)

    for line in signal_lines:
        parts = line.split("//")
        sig_def = parts[0].strip().split()
        comment = parts[1].strip() if len(parts) > 1 else ""

        name = sig_def[0]
        sig_type = sig_def[1]
        length = int(sig_def[2]) if len(sig_def) > 2 and sig_def[2].isdigit() else 1

        is_big_endian = "-m" in sig_def
        is_signed = "signed" in sig_type and "unsigned" not in sig_type

        # Extract modifiers
        scale = 1.0
        offset = 0.0
        unit = ""

        for item in sig_def:
            if item.startswith("/f:"):
                scale = float(item[3:])
            elif item.startswith("/o:"):
                offset = float(item[3:])
            elif item.startswith("/u:"):
                unit = item[3:].replace('"', "")

        signals_db[name] = {
            "length": length,
            "is_signed": is_signed,
            "is_big_endian": is_big_endian,
            "scale": scale,
            "offset": offset,
            "unit": unit,
            "description": comment,
        }

    # --- 2. Parse Messages ---
    # Splits the SENDRECEIVE block into individual message blocks
    sendreceive_block = content.split("{SENDRECEIVE}")[-1]
    message_blocks = re.split(r"\[(.*?)\]", sendreceive_block)[1:]

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

    # --- 3. Export to JSON ---
    with open("signals.json", "w") as f:
        json.dump(signals_db, f, indent=2)

    with open("messages.json", "w") as f:
        json.dump(messages_db, f, indent=2)

    print("Successfully generated signals.json and messages.json")


# Run the parser
parse_sym_to_json("PCAN_project/hytech.sym")
