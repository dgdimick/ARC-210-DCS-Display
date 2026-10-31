# Activity timestamps

Whenever `Firmware-and-Hardware-Information.md` changes, refresh its visible **Last updated** date and time in the same commit. Use the actual current time in `America/Denver`, including the correct MST/MDT abbreviation. Keep historical release and test dates unchanged.

Whenever `Bench-Testing-App.md` changes, refresh its visible **Last updated** date and time in the same commit. Use the actual current time in `America/Denver`, including the correct MST/MDT abbreviation. Keep historical release and test dates unchanged.

Whenever `DCS-BIOS.md` changes, refresh its visible **Last updated** date and time in the same commit. Use the actual current time in `America/Denver`, including the correct MST/MDT abbreviation. Also refresh this timestamp when changing the downloadable setup files under `DCS-BIOS/`, so readers can see when the setup materials change. Keep historical release dates unchanged.

When updating `Project-Updates.md` or `Remaining-Work.md`:

- Refresh that page's visible **Last updated** timestamp using the actual current date and time in `America/Denver`, including the correct MST/MDT abbreviation.
- Update the matching timestamp under its section in the root `README.md` in the same commit.
- Include the local date, time, and timezone on new entries added to `Project-Updates.md`.
- Preserve historical dates. Do not invent times for older entries whose times are unknown.
- A documentation edit is not evidence of hardware or firmware progress; describe changes accurately.

- Keep the latest project-update entry visible in the root README, followed by the link to the full history. When adding an update, replace the root README preview with the new entry and retain the existing hardware, firmware, testing, and cost-estimate entries on Project-Updates.md. Adjust relative links for the root README.

# Project update scope

Project-Updates.md is for substantive hardware and firmware changes, version releases, testing milestones, and build cost estimates. Do not add entries for routine documentation or wording changes, page reorganization, equipment lists, community announcements, or future ideas. Keep future ideas on Future-Thoughts.md. A documentation cleanup may refresh the page-maintenance timestamp without creating a new project-update entry or changing a historical milestone date.

# Documentation voice

Write personal build choices, progress, plans, and test experience in Denis’s first-person voice (I/my). Keep technical descriptions and reader-facing build instructions natural; do not turn every specification into a personal statement. Preserve historical dates, technical facts, code examples, licenses, and validation limits during wording edits.
