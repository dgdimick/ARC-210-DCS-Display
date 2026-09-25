# Current ARC-210 display font

The current menu-preview firmware uses `SwanseaFontSimple.cpp` and `SwanseaFontSimple.h`, copied from the working ARC210_Display library. These replace the older FreeSans headers previously stored here.

The renderer uses the Swansea28 bitmap glyph table with fractional scaling:

| Display element | Scale |
| --- | --- |
| Menu labels, EXIT, MORE, RT1 and PREV | 1.25× |
| Large frequency and channel/segment numbers | 3× |
| CT / CT-TD key number | 2× |
| Extra-long menu labels | 1× when needed to fit |

These are rendering scales, not point sizes. The files depend on Arduino and ILI9488_t3 and use the display library's global `tft` object; they are not standalone desktop font files or Adafruit GFX font headers.

Users installing the precompiled HEX do not need to install the fonts separately: the font data is already included in the firmware.
