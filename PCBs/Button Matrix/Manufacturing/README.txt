# Button Matrix PCB v3.1 — final design

Released October 27, 2026. Supersedes v3.0; use the v3.1 ZIP for new orders.
The board edges were shortened slightly. Button alignment was confirmed by the builder using the printed fit check.
The source retains the v3.1 silkscreen and has board revision 3.1.
KiCad 10.0.7 checks: zero ERC violations, zero DRC violations, zero unconnected items, zero schematic/PCB mismatches under saved settings.
Two copper layers, 1.6 mm board thickness. Gerber X2: copper, masks, silkscreens, and Edge.Cuts.
Metric Excellon drills: separate PTH/NPTH, absolute origin, unmirrored. Gerbers share this origin.
Verified 130 plated holes and 5 non-plated holes.
Upload Button-Matrix-PCB-v3.1-Gerbers-Drill.zip to the manufacturer; check their outline and drill preview.
Manufactured-board assembly and electrical testing remain pending.

October 30, 2026 — SQL clearance-hole correction:
Removed a redundant approximately 13.376 mm Edge.Cuts circle overlapping H3, the intended 12.000 mm non-plated SQL pass-through. The PCB source and outline Gerber were corrected together; the ZIP was rebuilt. Copper, mask, silkscreen, and drill files are unchanged. Use the 12.000 mm NPTH drill definition at this location; there is no additional routed circle.
This was a targeted source/Gerber correction, not a fresh KiCad export. The included ERC/DRC reports and drill report are historical October 27 results; no fresh KiCad DRC was available for this correction. Verify the manufacturer's preview before ordering.
