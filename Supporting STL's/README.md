# ARC-210 Supporting 3D Files — October 31, 2026

**Last updated: October 31, 2026 at 1:31 AM MDT (America/Denver)**

**The 17-part set has passed test fitting at 100% scale, with Channel v4.2 separately reprinted and confirmed after the earlier complete-layout test. The combined downloads now include that replacement.** Please keep checking [Project Updates](../Docs/Project-Updates.md) for any changes.

**Current STL files — October 30, 2026:** Frequency knob **v10.1** is now available with a larger shaft socket and a successful physical fit test. The other published STL versions remain as listed below. The shaft spacer is **v.5**. Channel **v4.2** and SQL **v1.2** have the same outside size and small side hole, with different shaft holes; both have passed test fitting at **100%**.

**All current knobs reprinted and test-fitted:** I’ve reprinted all nine knobs in their current versions—**5 Frequency v10.1, 2 Mode v4, 1 Channel v4.2, and 1 SQL v1.2—and all passed their test fit.** I’m happy with the fit, and **I don’t expect these knob designs to change again**. Print at **100% scale**. Printer tolerances and shaft sizes vary, so check the fit on your own hardware.

## No access to a 3D printer?

If you don’t have access to a 3D printer and that is stopping you from building the panel, I’ll send you **one complete 17-part printed set for US$3 (three US dollars), plus shipping and any applicable VAT**. I’ll print the **mounting bracket in black PETG** and the **remaining parts in gray PETG**. I want the lack of a printer to be one less obstacle to building your SIMPIT.

Get in touch through [Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) so we can arrange the set and shipping. See the [printed-parts offer](../parts/README.md#no-access-to-a-3d-printer) for details. Shipping and any applicable VAT are not included in the US$3 price.

## Channel and SQL knobs

[Channel knob v4.2](Channel_Knob_v.4.2.stl) · [SQL knob v1.2](SQL_Knob_v.1.2.stl)

**The Channel and SQL knobs are the same outside size, with the same small side hole; only the shaft holes differ.** Channel v4.2 has the smaller shaft hole; SQL v1.2 retains the larger shaft hole. Channel v4.2 uses the Frequency v10.1 shaft-hole profile (approximately 6.375 mm round diameter), with the Channel socket depth, outside dimensions, and small side hole unchanged. I printed Channel v4.2 at **100% scale** and confirmed the fit. SQL remains v1.2 with its previously tested socket. Print **one Channel v4.2 and one SQL v1.2**, each at 100%; these files are no longer interchangeable.

The SQL shaft support spacer v.5 remains required in all installations.

## USB cable strain-relief support — design pending

I still need to **design and 3D print the USB cable strain-relief support**. Its finished STL is not yet included in this directory. The support should protect the Teensy's Micro-B connector from cable pulls while allowing the cable to be unplugged and the Teensy removed for service. Physical fit verification is pending.

## Complete 17-part print set

**Master downloads checked — October 30, 2026:** I checked the master STL and 3MF and confirmed that both include **Channel v4.2 and SQL v1.2, with all 17 parts at 100% scale**. The knob geometry matches the individual STL downloads, the 3MF uses millimeter units with no scaling applied, and the master STL matches the 17-part 3MF geometry. This is a file check; the replacement Channel v4.2 was physically test-fitted separately from the earlier complete-layout print.

The master downloads include **all required printed parts for one panel**, at **100% scale**:

| Part | Quantity | Version |
| --- | ---: | --- |
| Frequency knob | 5 | v10.1 |
| Mode knob | 2 | v4 |
| Channel knob | 1 | v4.2 |
| SQL ON/OFF knob | 1 | v1.2 |
| Display bracket | 1 | v5 |
| Rotary encoder spacer | 6 | v1 |
| SQL shaft support spacer | 1 | v5 |
| **Total** | **17** | |

- [Download the complete master STL](ARC-210-Complete-Print-Set-All-17.stl)
- [Download the complete master 3MF with 17 separate objects](ARC-210-Complete-Print-Set-All-17.3mf)

**I have printed the complete 17-part layout at 100% scale, and all parts passed test fitting.** I consider the current STL designs final. Please keep checking [Project Updates](../Docs/Project-Updates.md) for changes.

The master layout measures approximately **187 × 117 mm**, with at least **8 mm clearance** between parts. It preserves each source part’s geometry and orientation and places every part on Z=0. Print one complete set at **100% scale**. Check your sliced preview, bed size, support needs, and space for brims or skirts. The 3MF uses millimeters and contains geometry only, without printer or filament settings. Individual files and the knob-only layouts remain available below.

## Knob Set V3

Updated October 30, 2026: frequency v10.1, Channel v4.2, and SQL v1.2 are the current knob versions. The combined nine-knob files include Channel v4.2 and SQL v1.2.

**Knob Set V3** identifies this collection. Each knob retains its own revision number; the collection number does not reset or replace those numbers.

### Current published knobs

| Knob | Quantity to print | Current STL | Earlier file |
| --- | ---: | --- | --- |
| Frequency | 5 | [Freq_Knob_v.10.1.stl](Freq_Knob_v.10.1.stl) | Replaces `Freq_Knob_v.10.stl`; v10 remains available for earlier shaft fits |
| Mode | 2 | [Mode_Knob_v.4.stl](Mode_Knob_v.4.stl) | Supersedes `Mode Mesh v6.stl`, despite its higher filename number |
| Channel | 1 | [Channel_Knob_v.4.2.stl](Channel_Knob_v.4.2.stl) | Replaces `Channel_Knob_v.4.1.stl` |
| SQL ON/OFF | 1 | [SQL_Knob_v.1.2.stl](SQL_Knob_v.1.2.stl) | Same outside size and side hole as Channel; larger shaft hole |

### Complete nine-knob print layout

Both downloads contain **5 Frequency knobs, 2 Mode knobs, 1 Channel knob, and 1 SQL knob**, using the current files linked above:

- [Download all nine knobs as one STL](ARC-210-Knob-Set-V3-All-9.stl)
- [Download all nine knobs as a 3MF with nine separate objects](ARC-210-Knob-Set-V3-All-9.3mf)

The layout occupies approximately **106 × 52 mm**, with at least **8 mm clearance** between knobs. Both files retain the source geometry at **100% scale**, preserve the original orientation, and place every knob on Z=0. STL dimensions are intended as millimeters; the 3MF explicitly uses millimeters. The 3MF contains geometry and placement only, with no printer, filament, support, or slicer settings. Check the sliced preview and allow extra bed space for brims or skirts. The previous complete nine-knob layout passed test fitting, and I separately printed and test-fitted the replacement Channel v4.2 at 100%.

The SQL ON/OFF knob is included: **nine knobs total**, ready to print at **100% scale**. Individual knob STLs remain available for replacements and fit checks; see the printing and fit notes below before printing the full set.

### If you downloaded an older ZIP

If you downloaded an earlier ZIP, please grab the current knob files from the table above. These files are intended to be used together as Knob Set V3. Some revision numbers look lower than the older filenames, so the table is the best guide to which files to print. Older files may still appear in previously downloaded ZIPs or repository history.

`Channel_Knob_v.4.2.stl` replaces v4.1. Earlier files remain available for earlier shaft fits.

### Printing and fit — all current knobs print at 100% with the current hardware

**Print all current knobs at 100% slicer scale:** Frequency v10.1, Mode v4, Channel v4.2, and SQL v1.2. They fit the current hardware listed in the [parts list](../parts/README.md). The previous complete nine-knob layout passed test fitting, and I separately printed and test-fitted the replacement Channel v4.2 at 100%.

Printer tolerances and shaft sizes vary, so check the fit on your own hardware. I recommend printing **one frequency knob first** before printing all five.

The shaft-fit adjustments are already built into the current STL files. The earlier 102%, 103%, and 107% settings discussed during development **do not apply to the current files**. Both combined downloads also print at **100% scale**.

## Other required STLs — included in the master print set

| Part | Quantity to print | Current STL | Purpose |
| --- | ---: | --- | --- |
| Display bracket | 1 | [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl) | Mounts the TFT display; replaces `3.5-SPI-Display-Bracket-v3.stl`. |
| Rotary encoder spacer | 6 | [Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl) | Centers the rotary encoders in the faceplate holes. Print six. |
| SQL On/Off rotary switch shaft support | 1 | [Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl) | Supports the longer shaft used by the SQL On/Off rotary switch; required in all installations. |

## Display bracket

Updated October 30, 2026. I have printed this bracket at **100% scale**, and it passed its test fit.

The current display bracket is [Deep_Bracket_v.5.stl](Deep_Bracket_v.5.stl). This file replaces `3.5-SPI-Display-Bracket-v3.stl`, which has been removed from the current branch. Use this replacement for new downloads; the older bracket remains available in repository history.

**Note:** I’ll probably redesign the display bracket after the PCBs are built. I still don’t like the current mounting method.

## Rotary encoder spacer

Added October 11, 2026. Updated October 30, 2026.

[Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl)

I use this spacer around the rotary encoder's threaded mounting section because the PC Flights ARC-210 faceplate has 10 mm holes, which are larger than the encoder threads. The spacer fills the gap and centers each encoder in its faceplate hole. Six of these spacers are needed. I have printed and test-fitted them at **100% scale**.

PC Flights has supplied me with a drawing file to assist with the Button PCB layout.

## SQL On/Off rotary switch support spacer v.5

I have printed this spacer at **100% scale**, and it passed its test fit.

[Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl)

Use this spacer in **all installations** to support the **longer shaft used by the SQL On/Off rotary switch**. Fit it whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

**October 22, 2026 — v.5 clearance fix:** The previous shaft spacer had a clearance issue. I corrected it in version 5, then physically test-fitted the spacer and checked that it works. Use v.5 for new prints; v.4 remains available in repository history.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

**Building your own panel, or just looking around?** [Introduce yourself in the welcome discussion](https://github.com/dgdimick/ARC-210-DCS-Display/discussions/1) and tell us what you fly. Questions, ideas, and progress photos are all welcome—even if you’re only getting started.

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
