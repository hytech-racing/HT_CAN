# HT_CAN

HyTech's CAN network definition. Every push builds a release with the generated CAN library that the firmware uses.

## Layout

- `json_lib/messages.json` — messages: name, CAN ID, DLC, and which signals they contain
- `json_lib/signals.json` — signal definitions: length, scale, offset, signedness, units
- `json_lib/enums.json` — enum values referenced by signals
- `imported_dbcs/` — third-party DBC files merged into the release as-is
- `conversion_scripts/` — scripts CI uses to turn the JSON into a DBC, proto, and C library

## Adding or Changing a Message

1. Add the signals to `json_lib/signals.json`.
2. Add the message to `json_lib/messages.json`, referencing those signals by name. CAN IDs must be unique.
3. Check it locally:
   ```
   pip install cantools==40.2.2
   python conversion_scripts/json_to_dbc.py
   ```
4. Push. CI creates a release named `<branch>-<run number>`.

## Using a Release

Each release includes `can_lib.tar.gz` (C library), `ht_can.dbc`, `ht_can.proto`, and `python_proto_lib.tar.gz`.

To use it in firmware, point the HT_CAN entry in `platformio.ini` at the release:
```
https://github.com/hytech-racing/HT_CAN/releases/download/<release-name>/can_lib.tar.gz
```
