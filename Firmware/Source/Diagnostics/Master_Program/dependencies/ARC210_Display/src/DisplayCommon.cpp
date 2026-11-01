#include <Arduino.h>
#include <ILI9488_t3.h>
#include <string.h>

#include "Display.h"
#include "SwanseaFontSimple.h"

// TFT is created in Display.cpp
extern ILI9488_t3 tft;


// ==================================================
// ARC-210 COLOR
// ==================================================
#define ARC210_GREEN ILI9488_GREEN


// ==================================================
// SHARED ARC-210 ELEMENT LAYOUT
//
// Every COMMON displayed element has its X, Y,
// and SCALE defined here once.
//
// Default scale is 1.25f unless an element needs
// a different size.
// ==================================================

static const float DEFAULT_SCALE = 1.25f;


// PREV LABEL
static const int16_t PREV_LABEL_X = 20;
static const int16_t PREV_LABEL_Y = 45;
static const float   PREV_LABEL_SCALE = DEFAULT_SCALE;


// PREVIOUS FREQUENCY
static const int16_t PREV_FREQ_X = 150;
static const int16_t PREV_FREQ_Y = 45;
static const float   PREV_FREQ_SCALE = DEFAULT_SCALE;


// RT1
static const int16_t RT1_X = 390;
static const int16_t RT1_Y = 45;
static const float   RT1_SCALE = DEFAULT_SCALE;


// KY-58
static const int16_t KY58_X = 20;
static const int16_t KY58_Y = 155;
static const float   KY58_SCALE = DEFAULT_SCALE;


// KY-58 STATUS
static const int16_t KY58_STATUS_X = 130;
static const int16_t KY58_STATUS_Y = 155;
static const float   KY58_STATUS_SCALE = DEFAULT_SCALE;


// COMSEC SUBMODE
// PT / CT / CT-TD
static const int16_t COMSEC_X = 20;
static const int16_t COMSEC_Y = 200;
static const float   COMSEC_SCALE = DEFAULT_SCALE;


// AM / FM
static const int16_t MODULATION_X = 345;
static const int16_t MODULATION_Y = 225;
static const float   MODULATION_SCALE = DEFAULT_SCALE;


// PRESET CHANNEL
//
// Channel is always drawn at 3.0f.
// Change X/Y here to move it without touching Display.cpp.
static const int16_t PRESET_CH_VALUE_X = 360;
static const int16_t PRESET_CH_VALUE_Y = 165;
static const float   PRESET_CH_VALUE_SCALE = 3.0f;


// MAIN FREQUENCY
static const int16_t FREQUENCY_X = 160;
static const int16_t FREQUENCY_Y = 300;
static const float   FREQUENCY_SCALE = 3.0f;


// VHF / UHF BAND MODE
static const int16_t BAND_X = 285;
static const int16_t BAND_Y = 155;
static const float   BAND_SCALE = DEFAULT_SCALE;


// XMIT / RECV
static const int16_t XMIT_RECV_X = 220;
static const int16_t XMIT_RECV_Y = 225;
static const float   XMIT_RECV_SCALE = DEFAULT_SCALE;


// GUARD
static const int16_t GUARD_X = 210;
static const int16_t GUARD_Y = 155;
static const float   GUARD_SCALE = DEFAULT_SCALE;


// DAMA
static const int16_t DAMA_X = 185;
static const int16_t DAMA_Y = 45;
static const float   DAMA_SCALE = DEFAULT_SCALE;


// ADF
static const int16_t ADF_X = 185;
static const int16_t ADF_Y = 45;
static const float   ADF_SCALE = DEFAULT_SCALE;


// ==================================================
// CLEAR SWANSEA TEXT AREA
//
// Shared utility used by common and page-specific
// display elements.
//
// The erase box scales with the selected font size.
// ==================================================
void clearSwanseaTextArea(
    int16_t x,
    int16_t baselineY,
    const char* clearText,
    float scale
)
{
    int16_t textWidth =
        getSwanseaTextWidth(
            clearText,
            scale
        );

    const int16_t BASE_HEIGHT = 18;

    int16_t textHeight =
        (int16_t)(BASE_HEIGHT * scale);

    int16_t padding =
        (int16_t)(3 * scale);

    tft.fillRect(
        x - padding,
        baselineY - textHeight - padding,
        textWidth + (padding * 2),
        textHeight + (padding * 2),
        ILI9488_BLACK
    );
}


// ==================================================
// COMMON ELEMENT
// PREV + PREVIOUS FREQUENCY
// ==================================================
void drawPREV(const char* previousFrequency)
{
    drawSwanseaText(
        PREV_LABEL_X,
        PREV_LABEL_Y,
        "PREV",
        PREV_LABEL_SCALE,
        ARC210_GREEN
    );

    const char* textToShow = "---.---";

    if (
        previousFrequency != nullptr &&
        previousFrequency[0] != '\0' &&
        strcmp(previousFrequency, "---.---") != 0
       )
    {
        textToShow = previousFrequency;
    }

    clearSwanseaTextArea(
        PREV_FREQ_X,
        PREV_FREQ_Y,
        "888.888",
        PREV_FREQ_SCALE
    );

    drawSwanseaText(
        PREV_FREQ_X,
        PREV_FREQ_Y,
        textToShow,
        PREV_FREQ_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// LOAD
//
// LOAD uses the exact same top-left position and
// 1.25f scale as the PREV label.
// ==================================================
void drawLoad()
{
    drawSwanseaText(
        PREV_LABEL_X,
        PREV_LABEL_Y,
        "LOAD",
        PREV_LABEL_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// RT1
// ==================================================
void drawRT1()
{
    drawSwanseaText(
        RT1_X,
        RT1_Y,
        "RT1",
        RT1_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// KY-58 LABEL
// ==================================================
void drawKY58()
{
    drawSwanseaText(
        KY58_X,
        KY58_Y,
        "KY-58",
        KY58_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// KY-58 STATUS
// ==================================================
void drawKY58Status(const char* status)
{
    clearSwanseaTextArea(
        KY58_STATUS_X,
        KY58_STATUS_Y,
        "VOICE",
        KY58_STATUS_SCALE
    );

    drawSwanseaText(
        KY58_STATUS_X,
        KY58_STATUS_Y,
        status,
        KY58_STATUS_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// COMSEC SUBMODE
// PT / CT / CT-TD
// ==================================================
void drawComsecSubmode(const char* mode)
{
    clearSwanseaTextArea(
        COMSEC_X,
        COMSEC_Y,
        "CT-TD",
        COMSEC_SCALE
    );

    drawSwanseaText(
        COMSEC_X,
        COMSEC_Y,
        mode,
        COMSEC_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// AM / FM
//
// This is the ONE shared function used to draw
// AM/FM on every screen that displays modulation.
// ==================================================
void drawAMFM(const char* mode)
{
    // AM/FM uses the shared modulation scale.
    // Build the erase box from the actual font size
    // instead of using a fixed hard-coded rectangle.
    const float scale = MODULATION_SCALE;

    int16_t textWidth =
        getSwanseaTextWidth(
            "FM",
            scale
        );

    const int16_t BASE_HEIGHT = 18;

    int16_t textHeight =
        (int16_t)(BASE_HEIGHT * scale);

    int16_t padding =
        (int16_t)(2 * scale);

    tft.fillRect(
        MODULATION_X - padding,
        MODULATION_Y - textHeight - padding,
        textWidth + (padding * 2),
        textHeight + (padding * 2),
        ILI9488_BLACK
    );

    drawSwanseaText(
        MODULATION_X,
        MODULATION_Y,
        mode,
        scale,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// FREQUENCY VALUE
// ==================================================
void drawFrequencyValue(const char* frequency)
{
    clearSwanseaTextArea(
        FREQUENCY_X,
        FREQUENCY_Y,
        "888.888",
        FREQUENCY_SCALE
    );

    drawSwanseaText(
        FREQUENCY_X,
        FREQUENCY_Y,
        frequency,
        FREQUENCY_SCALE,
        ARC210_GREEN
    );
}

// HQ channel digits align with frequency digit columns, not the preset position.
void drawHQLoadNumber(const char* value, bool formatPage)
{
    const float scale = FREQUENCY_SCALE;
    const int16_t x = FREQUENCY_X + getSwanseaTextWidth(formatPage ? "30" : "3", scale);
    const int16_t y = 205;
    tft.fillRect(x - 2, y - 62, 140, 68, ILI9488_BLACK);
    char first[2] = {value[0], '\0'};
    drawSwanseaText(x, y, first, scale, ARC210_GREEN);
    if (value[0] && value[1])
    {
        // 5B straddles the decimal: align the second digit after it.
        const int16_t next = x + getSwanseaTextWidth(formatPage ? "0." : "0", scale);
        drawSwanseaText(next, y, value + 1, scale, ARC210_GREEN);
    }
}




// ==================================================
// COMMON ELEMENT
// VHF / UHF BAND MODE
//
// Derived from the current ARC-210 frequency.
//
// VHF: 30.000 MHz up to (but not including) 225.000
// UHF: 225.000 MHz and above
// ==================================================
void drawBandMode(const char* frequency)
{
    const char* band = "";

    if (
        frequency != nullptr &&
        frequency[0] != '\0' &&
        strcmp(frequency, "---.---") != 0
       )
    {
        float freqMHz = atof(frequency);

        if (freqMHz >= 225.0f)
        {
            band = "UHF";
        }
        else if (freqMHz >= 30.0f)
        {
            band = "VHF";
        }
    }

    clearSwanseaTextArea(
        BAND_X,
        BAND_Y,
        "VHF",
        BAND_SCALE
    );

    drawSwanseaText(
        BAND_X,
        BAND_Y,
        band,
        BAND_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// XMIT / RECV
// ==================================================
void drawXmitRecv(const char* mode)
{
    const char* textToShow = "";

    if (mode != nullptr)
    {
        textToShow = mode;
    }

    clearSwanseaTextArea(
        XMIT_RECV_X,
        XMIT_RECV_Y,
        "RECV",
        XMIT_RECV_SCALE
    );

    drawSwanseaText(
        XMIT_RECV_X,
        XMIT_RECV_Y,
        textToShow,
        XMIT_RECV_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// GUARD
//
// Shows GUARD when the ARC-210 secondary selector
// is in position 5 (243.000) or 6 (121.500).
// Otherwise the field is blank.
// ==================================================
void drawGuard(bool enabled)
{
    clearSwanseaTextArea(
        GUARD_X,
        GUARD_Y,
        "GUARD",
        GUARD_SCALE
    );

    if (!enabled)
    {
        return;
    }

    drawSwanseaText(
        GUARD_X,
        GUARD_Y,
        "GUARD",
        GUARD_SCALE,
        ARC210_GREEN
    );
}



// ==================================================
// COMMON ELEMENT
// PRESET CHANNEL
//
// Channel is always 3.0f.
// Erase only the two-character channel field,
// then draw the new channel value.
// ==================================================
void drawPresetChannel(const char* channel)
{
    // Swansea digits extend 20 pixels above the baseline before scaling.
    const int16_t BASE_HEIGHT = 20;

    int16_t clearWidth =
        getSwanseaTextWidth(
            "88",
            PRESET_CH_VALUE_SCALE
        );

    int16_t clearHeight =
        (int16_t)(BASE_HEIGHT * PRESET_CH_VALUE_SCALE);

    tft.fillRect(
        PRESET_CH_VALUE_X - 1,
        PRESET_CH_VALUE_Y - clearHeight - 1,
        clearWidth + 2,
        clearHeight + 3,
        ILI9488_BLACK
    );

    drawSwanseaText(
        PRESET_CH_VALUE_X,
        PRESET_CH_VALUE_Y,
        channel,
        PRESET_CH_VALUE_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// DAMA
// ==================================================
void drawDAMA()
{
    drawSwanseaText(
        DAMA_X,
        DAMA_Y,
        "DAMA",
        DAMA_SCALE,
        ARC210_GREEN
    );
}


// ==================================================
// COMMON ELEMENT
// ADF
// ==================================================
void drawADF()
{
    drawSwanseaText(
        ADF_X,
        ADF_Y,
        "ADF",
        ADF_SCALE,
        ARC210_GREEN
    );
}
