# ARC-210 Supporting 3D Files — November 12, 2026

**Last updated: November 12, 2026 at 6:26 AM MST (America/Denver)**

**Both master downloads include the v.6 TFT bracket and the v4.2 Channel knob.** Please keep checking [Project Updates](../Docs/Project-Updates.md) for any changes.

**Current STL files — October 30, 2026:** Frequency knob **v10.1** is now available with a larger shaft socket and a successful physical fit test. The other published STL versions remain as listed below. The shaft spacer is **v.5**. Channel **v4.2** and SQL **v1.2** have the same outside size and small side hole, with different shaft holes; both have passed test fitting at **100%**.

**All current knobs reprinted and test-fitted:** I’ve reprinted all nine knobs in their current versions—**5 Frequency v10.1, 2 Mode v4, 1 Channel v4.2, and 1 SQL v1.2—and all passed their test fit.** I’m happy with the fit, and **I don’t expect these knob designs to change again**. Print at **100% scale**. Printer tolerances and shaft sizes vary, so check the fit on your own hardware.

## No access to a 3D printer?

I offer separate 3D-printing help for builders whose lack of printer access is preventing their build. This supplies printed plastic only, not electronic components or a complete kit; buy the other components separately. See [ARC-210 3D-printing help](../Docs/ARC-210-Parts-Offers.md#printed-parts) for the current price, PETG colors, availability, shipping, VAT, and import-charge details.

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
| TFT display bracket | 1 | v.6 |
| Rotary encoder spacer | 6 | v1 |
| SQL shaft support spacer | 1 | v5 |
| **Total** | **17** | |

- [Download the complete master STL](ARC-210-Complete-Print-Set-All-17.stl)
- [Download the complete master 3MF with 17 separate objects](ARC-210-Complete-Print-Set-All-17.3mf)

I printed and fit-tested the earlier 17-part layout at 100% scale. I checked the [v.6 TFT bracket](Deep_Bracket_v.6.stl) separately with the display and a printed Button Matrix board. Both master files include v.6 and contain the same 17 parts. For clearance around the SQL shaft support spacer, swap in the [standalone v6.1 bracket](Deep_Bracket_v.6.1.stl).

The master layout measures approximately **187 × 127 mm**, with at least **8 mm clearance** between parts. It preserves each source part’s geometry and orientation and places every part on Z=0. Print one complete set at **100% scale**. Check your sliced preview, bed size, support needs, and space for brims or skirts. The 3MF uses millimeters and contains geometry only, without printer or filament settings. Individual files and the knob-only layouts remain available below.

**Print settings:** Use a **0.20 mm or finer layer height** for the ARC-210 parts. The knobs print **without supports** in the supplied orientation. The **TFT display mount needs supports**. Check the sliced preview for support needs on the remaining parts. Print the TFT bracket and any other black parts in **flat black (matte) filament**. The shaft adapters will be hidden, but I’d use matte black for those too if you have it handy.

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
| TFT display bracket | 1 | [Deep_Bracket_v.6.1.stl](Deep_Bracket_v.6.1.stl) | Fit-tested bracket with four printed M3 threads. |
| Rotary encoder spacer | 6 | [Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl) | Centers the rotary encoders in the faceplate holes. Print six. |
| SQL On/Off rotary switch shaft support | 1 | [Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl) | Supports the longer shaft used by the SQL On/Off rotary switch; required in all installations. |

## Display bracket

Updated October 30, 2026. I have printed this bracket at **100% scale**, and it passed its test fit.

The current TFT display bracket is [v6.1](Deep_Bracket_v.6.1.stl). I test-printed it and confirmed that it clears the SQL shaft support spacer and all four M3 × 6 mm screws fit. Print at **100% scale with supports**. Use a **0.10 mm layer height** for the printed threads.

**Mount the TFT module upside down (rotated 180°)** so it clears the SQL shaft support spacer. The firmware rotates the image so it reads right side up from the front of the panel.

I redesigned the mount so the TFT screws right into the bracket. Use **four M3 × 6 mm screws** (M3 × 0.5 thread) and snug them up just enough to hold the display. **Don’t overtighten them.** It’s easy to strip the printed threads. The bracket is a tight fit on the Button Matrix PCB, but you’ll still need a little hot glue or silicone adhesive to secure the bracket to the board.

The bracket is 14 mm tall with a 59 × 80 mm upper profile.

## Rotary encoder spacer

Added October 11, 2026. Updated October 30, 2026.

[Rotary_Encoder_Spacer_v.1.stl](Rotary_Encoder_Spacer_v.1.stl)

I use this spacer around the rotary encoder's threaded mounting section because the PC Flights ARC-210 faceplate has 10 mm holes, which are larger than the encoder threads. The spacer fills the gap and centers each encoder in its faceplate hole. Six of these spacers are needed. I have printed and test-fitted them at **100% scale**.

## SQL On/Off rotary switch support spacer v.5

I have printed this spacer at **100% scale**, and it passed its test fit.

[Shaft_Spacer_v.5.stl](Shaft_Spacer_v.5.stl)

Use this spacer in **all installations** to support the **longer shaft used by the SQL On/Off rotary switch**. Fit it whether using the optional switch PCB or wiring directly to the switch’s solder lugs.

**October 22, 2026 — v.5 clearance fix:** The previous shaft spacer had a clearance issue. I corrected it in version 5, then physically test-fitted the spacer and checked that it works. Use v.5 for new prints; v.4 remains available in repository history.

## Estimated build cost

Thinking about building one? The [DIY parts purchasing estimate](../parts/README.md#estimated-build-cost) gives you an idea of the budget, including the faceplate, display, electronics, and PCB fabrication. You’ll source the parts yourself, and I’m sharing the files and guidance to help along the way.

## Questions and community builds

Visit [GitHub Discussions](https://github.com/dgdimick/ARC-210-DCS-Display/discussions) to ask questions, share ideas, and post photos of your builds.
