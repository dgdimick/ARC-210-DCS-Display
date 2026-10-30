# ARC-210 Supporting 3D Files

**Final STLs — October 22, 2026:** The published STL files linked in the tables below are the final versions. The shaft spacer is **v.5**. The SQL ON/OFF knob remains to be designed and printed.

## SQL ON/OFF knob — design pending

The **SQL ON/OFF knob still needs to be designed and 3D printed**. Its finished STL is not yet included in this directory. The final-version notes below apply to the files already published.

## USB cable strain-relief support — design pending

The **USB cable strain-relief support still needs to be designed and 3D printed**. Its finished STL is not yet included in this directory. The support should protect the Teensy's Micro-B connector from cable pulls while allowing the cable to be unplugged and the Teensy removed for service. Physical fit verification is pending.

## Knob Set V3

Updated October 4, 2026.

**Knob Set V3** identifies this collection. Each knob retains its own revision number; the collection number does not reset or replace those numbers.

### Current published knobs

| Knob | Quantity to print | Current STL | Earlier file |
| --- | ---: | --- | --- |
| Frequency | 5 | [Freq_Knob_v.10.stl](Freq_Knob_v.10.stl) | Replaces `Freq Mesh v9.stl` |
| Mode | 2 | [Mode_Knob_v.4.stl](Mode_Knob_v.4.stl) | Supersedes `Mode Mesh v6.stl`, despite its higher filename number |
| Channel | 1 | [Channel_Knob_v.3.stl](Channel_Knob_v.3.stl) | Replaces `Channel Knob v13.stl`, despite its higher filename number |

### Complete eight-knob print layout

Both downloads contain **5 Frequency knobs, 2 Mode knobs, and 1 Channel knob**, using the current files linked above:

- [Download all eight knobs as one STL](ARC-210-Knob-Set-V3-All-8.stl)
- [Download all eight knobs as a 3MF with eight separate objects](ARC-210-Knob-Set-V3-All-8.3mf)

The layout occupies approximately **91 × 42 mm**, with at least **8 mm clearance** between knobs. Both files retain the source geometry at **100% scale**, preserve the original orientation, and place every knob on Z=0. STL dimensions are intended as millimeters; the 3MF explicitly uses millimeters. The 3MF contains geometry and placement only, with no printer, filament, support, or slicer settings. Check the sliced preview and allow extra bed space for brims or skirts. These combined files have not yet been physically print-tested.

The SQL ON/OFF knob is **not included**, because its design is still pending. Individual knob STLs remain available for replacements and fit checks; see the printing and fit notes below before printing the full set.

### If you downloaded an older ZIP

If you downloaded an earlier ZIP, please grab the current knob files from the table above. These files are intended to be used together as Knob Set V3. Some revision numbers look lower than the older filenames, so the table is the best guide to which files to print. Older files may still appear in previously downloaded ZIPs or repository history.

`Channel_Knob_v.3.stl` is the current channel knob for Knob Set V3. Its lower filename number does not mean it is older than `Channel Knob v13.stl`. Use the linked files above to identify the current versions.

### Printing and fit

Use the hardware listed on the main project page. Printer tolerances vary, so try one knob on its shaft before printing the full set. I previously used 106% scaling for the mode and frequency knobs, but your printer and the current files may need a different adjustment. Scaling changes both the outside dimensions and the holes.

## Other STL's that are needed

| Part | Current STL | Purpose |
| --- | --- | --- |
| Display bracket | [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl) | Mounts the TFT display; replaces `3.5-SPI-Display-Bracket-v3.stl`. |
| Rotary encoder spacer | [Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl) | Centers the rotary encoders in the faceplate holes. Print six. |
| SQL On/Off rotary switch shaft support | [Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl) | Supports the longer shaft used by the SQL On/Off rotary switch; required in all installations. |

## Display bracket

Updated October 12, 2026.

The current display bracket is [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl). This file replaces `3.5-SPI-Display-Bracket-v3.stl`, which has been removed from the current branch. Use this replacement for new downloads; the older bracket remains available in repository history.

## Rotary encoder spacer

Added October 11, 2026.

[Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl)

I use this spacer around the rotary encoder's threaded mounting section because the PC Flights ARC-210 faceplate has 10 mm holes, which are larger than the encoder threads. The spacer fills the gap and centers each encoder in its faceplate hole. Six of these spacers are needed.

PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

## SQL On/Off rotary switch support spacer v.5

[Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl)

Use this spacer in **all installations** to support the **longer shaft used by the SQL On/Off rotary switch**. Fit it whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

**October 22, 2026 — v.5 clearance fix:** The previous shaft spacer had a clearance issue. Version 5 corrects it and has now been physically test-fitted and confirmed to fit and work. Use v.5 for new prints; v.4 remains available in repository history.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
