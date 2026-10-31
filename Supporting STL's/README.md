# ARC-210 Supporting 3D Files

**Last updated: October 30, 2026**

**Current STL files — October 30, 2026:** Frequency knob **v10.1** is now available with a larger shaft socket and a successful physical fit test. The other published STL versions remain as listed below. The shaft spacer is **v.5**. Channel **v4.1** and SQL **v1.2** are now available and use the same tested geometry, printed at **100%**.

**All current knobs reprinted and test-fitted:** I’ve reprinted all nine knobs in their current versions—**5 Frequency v10.1, 2 Mode v4, 1 Channel v4.1, and 1 SQL v1.2—and all passed their test fit.** I’m happy with the fit, and **I don’t expect these knob designs to change again**. Print at **100% scale**. Printer tolerances and shaft sizes vary, so check the fit on your own hardware.

## Channel and SQL knobs

[Channel knob v4.1](Channel_Knob_v.4.1.stl) · [SQL knob v1.2](SQL_Knob_v.1.2.stl)

**The Channel and SQL knobs are the same knob design.** Channel v4.1 and SQL v1.2 contain identical geometry; I’ve kept separate filenames to make their uses clear. Print **two copies of either file at 100% scale** for one panel: one Channel and one SQL. I printed SQL v1.2 at 100% and checked its fit. The small side hole remains unchanged. Check the fit on each shaft before final assembly.

The SQL shaft support spacer v.5 remains required in all installations.

## USB cable strain-relief support — design pending

I still need to **design and 3D print the USB cable strain-relief support**. Its finished STL is not yet included in this directory. The support should protect the Teensy's Micro-B connector from cable pulls while allowing the cable to be unplugged and the Teensy removed for service. Physical fit verification is pending.

## Knob Set V3

Updated October 30, 2026: frequency v10.1, Channel v4.1, and SQL v1.2 are the current knob versions. The combined nine-knob files include Channel v4.1 and SQL v1.2.

**Knob Set V3** identifies this collection. Each knob retains its own revision number; the collection number does not reset or replace those numbers.

### Current published knobs

| Knob | Quantity to print | Current STL | Earlier file |
| --- | ---: | --- | --- |
| Frequency | 5 | [Freq_Knob_v.10.1.stl](Freq_Knob_v.10.1.stl) | Replaces `Freq_Knob_v.10.stl`; v10 remains available for earlier shaft fits |
| Mode | 2 | [Mode_Knob_v.4.stl](Mode_Knob_v.4.stl) | Supersedes `Mode Mesh v6.stl`, despite its higher filename number |
| Channel | 1 | [Channel_Knob_v.4.1.stl](Channel_Knob_v.4.1.stl) | Replaces `Channel_Knob_v.4.stl` |
| SQL ON/OFF | 1 | [SQL_Knob_v.1.2.stl](SQL_Knob_v.1.2.stl) | Same Knob as Channel |

### Complete nine-knob print layout

Both downloads contain **5 Frequency knobs, 2 Mode knobs, 1 Channel knob, and 1 SQL knob**, using the current files linked above:

- [Download all nine knobs as one STL](ARC-210-Knob-Set-V3-All-9.stl)
- [Download all nine knobs as a 3MF with nine separate objects](ARC-210-Knob-Set-V3-All-9.3mf)

The layout occupies approximately **106 × 52 mm**, with at least **8 mm clearance** between knobs. Both files retain the source geometry at **100% scale**, preserve the original orientation, and place every knob on Z=0. STL dimensions are intended as millimeters; the 3MF explicitly uses millimeters. The 3MF contains geometry and placement only, with no printer, filament, support, or slicer settings. Check the sliced preview and allow extra bed space for brims or skirts. I have printed the complete nine-knob layout, and all nine knobs passed their test fit.

The SQL ON/OFF knob is included: **nine knobs total**, ready to print at **100% scale**. Individual knob STLs remain available for replacements and fit checks; see the printing and fit notes below before printing the full set.

### If you downloaded an older ZIP

If you downloaded an earlier ZIP, please grab the current knob files from the table above. These files are intended to be used together as Knob Set V3. Some revision numbers look lower than the older filenames, so the table is the best guide to which files to print. Older files may still appear in previously downloaded ZIPs or repository history.

`Channel_Knob_v.4.1.stl` replaces v4. Earlier files remain available for earlier shaft fits.

### Printing and fit

Use the hardware listed on the main project page. **I’ve printed frequency knob v10.1 and checked that it fits my encoder shaft. Print v10.1 at 100% slicer scale.** I enlarged only the shaft socket to 102% of v10’s original XY size; the outside dimensions and height remain unchanged. The nominal round socket diameter is now approximately **6.375 mm**, up from **6.25 mm**, with the same **8 mm socket depth**.

I recommend printing **one frequency knob first and checking its shaft fit** before printing all five. Printer tolerances and shaft sizes vary. For the older [v10 STL](Freq_Knob_v.10.stl), I found **103% whole-knob scaling** gave the best fit; that enlarges both the socket and the outside of the knob. That older setting does not apply to v10.1.

The combined STL and 3MF now contain **five v10.1 frequency knobs** at 100% scale. I have printed the complete nine-knob layout, and all nine knobs passed their test fit. The mode knobs remain v4. Channel v4.1 and SQL v1.2 print at 100%; the shaft socket now matches the Mode v4 socket cross-section (approximately 7.30 mm round diameter, with its D-flat), retaining the SQL socket’s 14 mm depth. The outside diameter, height, and small radial hole retain their original dimensions.

## Other required STLs

| Part | Current STL | Purpose |
| --- | --- | --- |
| Display bracket | [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl) | Mounts the TFT display; replaces `3.5-SPI-Display-Bracket-v3.stl`. |
| Rotary encoder spacer | [Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl) | Centers the rotary encoders in the faceplate holes. Print six. |
| SQL On/Off rotary switch shaft support | [Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl) | Supports the longer shaft used by the SQL On/Off rotary switch; required in all installations. |

## Display bracket

Updated October 30, 2026.

The current display bracket is [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl). This file replaces `3.5-SPI-Display-Bracket-v3.stl`, which has been removed from the current branch. Use this replacement for new downloads; the older bracket remains available in repository history.

**Note:** I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

## Rotary encoder spacer

Added October 11, 2026. Updated October 30, 2026.

[Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl)

I use this spacer around the rotary encoder's threaded mounting section because the PC Flights ARC-210 faceplate has 10 mm holes, which are larger than the encoder threads. The spacer fills the gap and centers each encoder in its faceplate hole. Six of these spacers are needed.

PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

## SQL On/Off rotary switch support spacer v.5

[Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl)

Use this spacer in **all installations** to support the **longer shaft used by the SQL On/Off rotary switch**. Fit it whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

**October 22, 2026 — v.5 clearance fix:** The previous shaft spacer had a clearance issue. I corrected it in version 5, then physically test-fitted the spacer and checked that it works. Use v.5 for new prints; v.4 remains available in repository history.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
