# HT CAN description
This repository contains the descriptions for all of our CAN messages.

Our CAN network is defined as a **PCAN Symbol file** (`PCAN_project/hytech.sym`). This is source of truth for every message on the bus. It's edited using [PCAN Symbol Editor], which gives a GUI for adding messages, signals, scaling, units, and value tables without hand-writing SYM syntax.

Some devices on the bus ship their own vendor-provided `.dbc` files. Rather than hand-transcribing those into `hytech.sym`, we merge them in automatically as part of CI (see below)

From `hytech.sym`, the GitHub Actions workflow (`.github/workflows/...`) automatically:
1. Merges in any imported vendor DBCs and checks for CAN ID collisions
2. Converts the combined description to `hytech.dbc`
3. Generates a `.proto` definition and HTML documentation from it
4. Generates a C code library (`can_lib.tar.gz`) via `coderdbc`, and a DriveBrain-specific bundle (`drivebrain_can_lib.tar.gz`)
5. Publishes all of the above as a versioned GitHub Release, tagged with the CI run number

# How to update the monorepo to a newer CAN library

1. Go to this repo's [Releases](../../releases) page and find the release you want (each release is tagged with the CI run number that produced it, e.g. `Release-142`).
2. In the monorepo's platformio.ini file, change the release that is being referenced.

# Editing the CAN description

- Open `PCAN_project/hytech.sym` in PCAN Symbol Editor to add or change messages/signals.
- Push your changes on a branch/PR — CI will regenerate `hytech.dbc`, the proto, the C library, and open documentation automatically; you don't need to run any generation steps locally.
- Don't hand-edit the generated `hytech.dbc`, `.proto`, or C library output — they're fully derived from `hytech.sym` (plus imported DBCs) on every CI run and will be overwritten.

## Imported DBCs

Some bus participants provide their own `.dbc` file rather than being defined natively in `hytech.sym`. These are merged into `hytech.sym` at build time, not committed as a merged file.

- `PCAN_project/hytech.sym` in the repo should always stay in its **unmerged**, hand-authored state.
- Imported vendor DBCs live alongside it
- On every push/PR, the `generate-dbc` CI job:
  1. **Checks for CAN ID collisions** (`check_no_duplicate_ids.py`) between `hytech.sym` and the imported DBC, failing the build if any message IDs overlap.
  2. **Merges** the imported DBC into a CI-local copy of `hytech.sym` (`merge_dti.py`).
  3. Converts the merged result to `hytech.dbc`, which flows into the rest of the pipeline (proto, C library, release).

> ⚠️ Never run the merge script locally and commit the resulting `hytech.sym`. The merge is designed to run fresh against a clean, unmerged `hytech.sym` every CI run. Merging twice into the same file will fail, since a message name can't be added twice. If you need to add a new imported DBC, add the file to the repo and update the merge/check scripts to include its path — don't merge it in by hand.