import json, cantools, os
from cantools.database import can
from cantools.database.conversion import BaseConversion

# Load Enums and convert JSON string keys to integer keys for cantools
with open("json_lib/enums.json", "r") as f:
    raw_enums = json.load(f)
    global_enums = {
        name: {int(k): v for k, v in choices.items()}
        for name, choices in raw_enums.items()
    }

with open("json_lib/signals.json", "r") as f:
    global_signals = json.load(f)

with open("json_lib/messages.json", "r") as f:
    messages_data = json.load(f)

db_messages = []
for msg in messages_data:
    msg_signals = []
    current_bit = 0
    max_bit = 0

    for sig_ref in msg["signals"]:
        sig_prop = global_signals[sig_ref["name"]]
        length = sig_prop["length"]

        # Automatically calculate start bit sequentially if missing
        if "start_bit" in sig_ref:
            pcan_start = sig_ref["start_bit"]
        else:
            pcan_start = current_bit

        # Advance current_bit for the next signal and update max bounds
        current_bit = pcan_start + length
        if current_bit > max_bit:
            max_bit = current_bit

        is_big_endian = sig_prop.get("is_big_endian", False)
        is_signed = sig_prop.get("is_signed", False)

        # Convert PCAN LSB start bit to DBC MSB start bit for Big Endian signals
        if is_big_endian:
            dbc_start = min(pcan_start + length - 1, (pcan_start // 8) * 8 + 7)
        else:
            dbc_start = pcan_start

        # Fetch enum choices if the signal references one
        enum_ref = sig_prop.get("enum")
        choices = global_enums.get(enum_ref) if enum_ref else None

        # Strip .0 floats back to strict integers to prevent ccoderdbc from generating _ro conversions
        scale_val = sig_prop.get("scale", 1)
        offset_val = sig_prop.get("offset", 0)

        clean_scale = (
            int(scale_val)
            if isinstance(scale_val, float) and scale_val.is_integer()
            else scale_val
        )
        clean_offset = (
            int(offset_val)
            if isinstance(offset_val, float) and offset_val.is_integer()
            else offset_val
        )

        # Calculate theoretical min/max bounds based on bit length
        raw_min = -(2 ** (length - 1)) if is_signed else 0
        raw_max = (2 ** (length - 1)) - 1 if is_signed else (2**length) - 1

        calc_min = (raw_min * clean_scale) + clean_offset
        calc_max = (raw_max * clean_scale) + clean_offset

        # Use explicitly defined limits if they exist, otherwise use the calculated limits
        final_min = sig_prop.get("min") if sig_prop.get("min") is not None else calc_min
        final_max = sig_prop.get("max") if sig_prop.get("max") is not None else calc_max

        # Generate the conversion object for scale, offset, and choices
        conv = BaseConversion.factory(
            scale=clean_scale,
            offset=clean_offset,
            choices=choices,
            is_float=sig_prop.get("is_float", False),
        )

        msg_signals.append(
            can.Signal(
                name=sig_ref["name"],
                start=dbc_start,
                length=length,
                byte_order="big_endian" if is_big_endian else "little_endian",
                is_signed=is_signed,
                conversion=conv,
                minimum=final_min,
                maximum=final_max,
                unit=sig_prop.get("unit", ""),
                comment=sig_prop.get("description", ""),
            )
        )

    # Automatically calculate DLC based on the highest bit used if missing
    if "dlc" in msg:
        calculated_dlc = msg["dlc"]
    else:
        calculated_dlc = (max_bit + 7) // 8

    db_messages.append(
        can.Message(
            frame_id=int(msg["id"], 16) if isinstance(msg["id"], str) else msg["id"],
            name=msg["name"],
            length=calculated_dlc,
            is_extended_frame=msg.get("is_extended", False),
            senders=msg.get("senders", ["ECU"]),
            signals=msg_signals,
            comment=msg.get("description", ""),
        )
    )

release_number = os.getenv("RELEASE_NUMBER", "0")

db = cantools.database.Database(messages=db_messages, version=release_number)
cantools.database.dump_file(db, "ht_can.dbc")
