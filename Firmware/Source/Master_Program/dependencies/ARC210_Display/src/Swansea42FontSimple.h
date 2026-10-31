#ifndef SWANSEA_42_FONT_SIMPLE_H
#define SWANSEA_42_FONT_SIMPLE_H

#include <Arduino.h>

struct Swansea42SimpleGlyph
{
    uint16_t rowOffset;
    uint8_t width;
    uint8_t height;
    uint8_t xAdvance;
    int8_t xOffset;
    int8_t yOffset;
};

extern const uint64_t Swansea42Rows[] PROGMEM;
extern const Swansea42SimpleGlyph Swansea42GlyphsSimple[] PROGMEM;

void drawSwansea42Text(
    int16_t x,
    int16_t baselineY,
    const char* text,
    uint16_t color
);

int16_t getSwansea42TextWidth(const char* text);

#endif
