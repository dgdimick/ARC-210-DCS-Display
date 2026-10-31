#ifndef SWANSEA_FONT_SIMPLE_H
#define SWANSEA_FONT_SIMPLE_H

#include <Arduino.h>


struct SwanseaSimpleGlyph
{
    uint16_t rowOffset;
    uint8_t width;
    uint8_t height;
    uint8_t xAdvance;
    int8_t xOffset;
    int8_t yOffset;
};


extern const uint32_t Swansea28Rows[] PROGMEM;

extern const SwanseaSimpleGlyph
    Swansea28GlyphsSimple[] PROGMEM;


// ==================================================
// DRAW SWANSEA TEXT
// Supports fractional scaling
// ==================================================
void drawSwanseaText(
    int16_t x,
    int16_t baselineY,
    const char* text,
    float scale,
    uint16_t color
);


// ==================================================
// GET TEXT WIDTH
// ==================================================
int16_t getSwanseaTextWidth(
    const char* text,
    float scale
);


#endif