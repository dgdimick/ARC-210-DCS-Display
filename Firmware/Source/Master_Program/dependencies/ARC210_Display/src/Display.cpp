#include <Arduino.h>
#include <SPI.h>
#include <ILI9488_t3.h>
#include <string.h>

#include "Display.h"
#include "FirmwareInfo.h"
#include "SplashImage.h"
#include "SwanseaFontSimple.h"
#include "Swansea42FontSimple.h"


// ==================================================
// TFT PINS
// ==================================================
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

ILI9488_t3 tft = ILI9488_t3(
    TFT_CS,
    TFT_DC,
    TFT_RST
);


// ==================================================
// ARC-210 COLOR
// ==================================================
#define ARC210_GREEN ILI9488_GREEN


// ==================================================
// SHARED UTILITY FROM DisplayCommon.cpp
// ==================================================
void clearSwanseaTextArea(
    int16_t x,
    int16_t baselineY,
    const char* clearText,
    float scale
);


// ==================================================
// PRESET-ONLY LAYOUT
//
// These values only affect the PRESET page.
// Common element positions are in DisplayCommon.cpp.
// ==================================================

static const float DEFAULT_SCALE = 1.25f;


// ==================================================
// STATIC GUARD PAGE HEADER LAYOUT
//
// These positions affect ONLY the two fixed GUARD
// screens. MAN and PRESET layouts are untouched.
//
// VHF/UHF uses the old PREV location.
// GUARD is centered automatically on the top row.
// RT1 stays at its normal shared position.
// ==================================================
static const int16_t GUARD_BAND_X = 20;
static const int16_t GUARD_BAND_Y = 45;
static const float   GUARD_BAND_SCALE = DEFAULT_SCALE;

static const int16_t GUARD_HEADER_Y = 45;
static const float   GUARD_HEADER_SCALE = DEFAULT_SCALE;



// ENCRYPTION NUMBER
static const int16_t ENCRYPTION_X = 30;
static const int16_t ENCRYPTION_Y = 285;
static const float   ENCRYPTION_SCALE = 2.0f;


// ==================================================
// DISPLAY PAGE TRACKING
// ==================================================
enum DisplayPage
{
    PAGE_NONE,
    PAGE_INFO,
    PAGE_BOOT,
    PAGE_INITIALIZING,
    PAGE_FREQUENCY,
    PAGE_PRESET,
    PAGE_GUARD_243,
    PAGE_GUARD_121,
    PAGE_MENU,
    PAGE_HQ_MENUS,
    PAGE_OPER_DATE_LOAD,
    PAGE_VERIFY_WOD_MWOD,
    PAGE_HQ_WOD_LOAD,
    PAGE_HQ_WOD_ERASE,
    PAGE_HQ_FMT_LOAD,
    PAGE_HQ_MORE_1,
    PAGE_HQ_MORE_2,
    PAGE_HQ_MORE_3,
    PAGE_HQ_MORE_4,
    PAGE_HQ_MORE_5,
    PAGE_HQ_MORE_6,
    PAGE_HQ_MORE_7,
    PAGE_HQ_MORE_8,
    PAGE_HQ_MORE_9,
    PAGE_HQ_MORE_10,
    PAGE_HQ_MORE_11,
    PAGE_HQ_MORE_12,
    PAGE_HQ_MORE_13,
    PAGE_HQ_MORE_14,
    PAGE_HQ_MORE_15,
    PAGE_HQ_MORE_16,
    PAGE_HQ_MORE_17,
    PAGE_HQ_MORE_18,
    PAGE_COMSEC,
    PAGE_COMSEC_LOAD,
    PAGE_COMSEC_LOS_MORE_1,
    PAGE_COMSEC_LOS_MORE_2,
    PAGE_COMSEC_LOS_MORE_3,
    PAGE_COMSEC_LOS_MORE_4,
    PAGE_COMSEC_LOS_MORE_5,
    PAGE_COMSEC_LOS_MORE_6,
    PAGE_COMSEC_LOS_MORE_7,
    PAGE_COMSEC_LOS_MORE_8,
    PAGE_COMSEC_KG84_RATE,
    PAGE_COMSEC_DAMA_MORE,
    PAGE_COMSEC_DAMA_DATA,
    PAGE_COMSEC_DAMA_RATE_300,
    PAGE_RADIO_SETTINGS,
    PAGE_RADIO_MORE_1,
    PAGE_RADIO_MORE_2,
    PAGE_RADIO_MORE_3,
    PAGE_RADIO_MORE_4,
    PAGE_RADIO_MORE_5,
    PAGE_RADIO_MORE_6,
    PAGE_RADIO_ID_NUMBERS,
    PAGE_RADIO_PRESET_26_30,
    PAGE_RADIO_DAMA_CHANNELS,
    PAGE_RADIO_BEEP_ENABLE,
    PAGE_RADIO_USER_DATA_WIDEBAND,
    PAGE_RADIO_USER_DATA_188_144,
    PAGE_RADIO_USER_DATA_SYNCHRONOUS,
    PAGE_RADIO_USER_DATA_ASYNC,
    PAGE_RADIO_USER_DATA_EXTERNAL_CLOCK,
    PAGE_RADIO_USER_DATA_INTERNAL_CLOCK,
    PAGE_RADIO_SWITCH_TEST,
    PAGE_RADIO_ENTER_KEY_ENABLE,
    PAGE_UNAVAILABLE
};

DisplayPage currentPage = PAGE_NONE;
static bool displayFrameBufferEnabled = false;
static bool displayRefreshPending = false;


// ==================================================
// PRESENT COMPLETED FRAME
// ==================================================
void refreshDisplay()
{
    displayRefreshPending = true;
}

void flushDisplay()
{
    if (displayRefreshPending && displayFrameBufferEnabled)
    {
        tft.updateScreen();
    }
    displayRefreshPending = false;
}


// ==================================================
// INITIALIZE DISPLAY
// ==================================================
void initializeDisplay()
{
    tft.begin();
    tft.setRotation(1);
    displayFrameBufferEnabled = (tft.useFrameBuffer(true) != 0);
    blankScreen();
}


// ==================================================
// BLANK SCREEN
// ==================================================
void blankScreen()
{
    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_NONE;
    refreshDisplay();
}


// ==================================================
// FIRMWARE INFORMATION / SPLASH SCREEN
//
// This replaces only the initial black waiting page.
// It does not change any ARC-210 boot timing.
// ==================================================
static void drawSplashWireframe()
{
    for (uint16_t y = 0; y < ARC210_SPLASH_HEIGHT; ++y)
    {
        uint16_t x = 0;

        while (x < ARC210_SPLASH_WIDTH)
        {
            uint32_t byteIndex =
                ((uint32_t)y * ARC210_SPLASH_BYTES_PER_ROW) + (x >> 3);

            uint8_t pixelByte = pgm_read_byte(&arc210SplashBitmap[byteIndex]);
            uint8_t pixelMask = 0x80 >> (x & 7);

            if ((pixelByte & pixelMask) == 0)
            {
                ++x;
                continue;
            }

            uint16_t runStart = x;

            do
            {
                ++x;

                if (x >= ARC210_SPLASH_WIDTH)
                {
                    break;
                }

                byteIndex =
                    ((uint32_t)y * ARC210_SPLASH_BYTES_PER_ROW) + (x >> 3);

                pixelByte = pgm_read_byte(&arc210SplashBitmap[byteIndex]);
                pixelMask = 0x80 >> (x & 7);

            } while ((pixelByte & pixelMask) != 0);

            tft.drawFastHLine(
                runStart,
                y,
                x - runStart,
                ARC210_GREEN
            );
        }
    }
}


static void drawCenteredSplashText(
    int16_t baselineY,
    const char* text,
    float scale
)
{
    int16_t textWidth = getSwanseaTextWidth(text, scale);
    int16_t textX = (480 - textWidth) / 2;

    drawSwanseaText(
        textX,
        baselineY,
        text,
        scale,
        ARC210_GREEN
    );
}


void showInfoScreen()
{
    if (currentPage == PAGE_INFO)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_INFO;

    drawSplashWireframe();

    drawCenteredSplashText(208, "ARC-210 RADIO PANEL", 0.9f);
    drawCenteredSplashText(232, ARC210_VERSION_LABEL, 0.8f);
    drawCenteredSplashText(256, ARC210_AIRCRAFT_LABEL, 0.8f);
    drawCenteredSplashText(280, "github.com/dgdimick", 0.8f);
    drawCenteredSplashText(306, "dgdimick@gmail.com", 0.8f);

    refreshDisplay();
}


// ==================================================
// INITIALIZING SCREEN
// ==================================================
void showInitializingScreen()
{
    if (currentPage == PAGE_INITIALIZING)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_INITIALIZING;

    drawSwanseaText(
        125,
        140,
        "INITIALIZING",
        1.25f,
        ARC210_GREEN
    );

    drawRT1();
    refreshDisplay();
}


// ==================================================
// UNAVAILABLE SCREEN
// ==================================================
void showUnavailableScreen()
{
    if (currentPage == PAGE_UNAVAILABLE)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_UNAVAILABLE;

    drawUnavailableText();
    refreshDisplay();
}


// ==================================================
// ARC-210 MENU HELPERS
//
// Every menu page uses the same three left-side FSK
// locations and always shows RT1 in the upper-right.
// ==================================================
static float menuScaleForText(const char* text)
{
    if (text == nullptr || text[0] == '\0')
    {
        return DEFAULT_SCALE;
    }

    // Keep long "-- Not Defined" labels on one line.
    if (getSwanseaTextWidth(text, DEFAULT_SCALE) > 440)
    {
        return 1.0f;
    }

    return DEFAULT_SCALE;
}

static void drawMenuLine(
    int16_t baselineY,
    const char* line1,
    const char* line2 = nullptr
)
{
    float scale = menuScaleForText(line1);

    drawSwanseaText(
        20,
        baselineY,
        line1,
        scale,
        ARC210_GREEN
    );

    if (line2 != nullptr && line2[0] != '\0')
    {
        drawSwanseaText(
            20,
            baselineY + 28,
            line2,
            menuScaleForText(line2),
            ARC210_GREEN
        );
    }
}

static void showThreeItemMenu(
    DisplayPage page,
    const char* upper1,
    const char* upper2,
    const char* middle1,
    const char* middle2,
    const char* lower1,
    const char* lower2
)
{
    if (currentPage == page)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = page;

    drawMenuLine(45, upper1, upper2);
    drawMenuLine(155, middle1, middle2);
    drawMenuLine(265, lower1, lower2);
    drawRT1();
    refreshDisplay();
}


// ==================================================
// MAIN MENU
// ==================================================
void showMenuScreen()
{
    showThreeItemMenu(
        PAGE_MENU,
        "HQ MENUS", nullptr,
        "COMSEC", nullptr,
        "RADIO SETTINGS", nullptr
    );
}


// ==================================================
// HQ MENUS
// ==================================================
void showHQMenusScreen()
{
    showThreeItemMenu(
        PAGE_HQ_MENUS,
        "EXIT", nullptr,
        "OPER. DATE LOAD", nullptr,
        "MORE", nullptr
    );
}


// ==================================================
// OPER. DATE LOAD
// ==================================================
static char operDateValue[3] = "--";
static char hqFrequencyValue[8] = "---.---";

void setOperDateValue(const char* value)
{
    // Empty indications occur while other cockpit pages are displayed.
    const char* start = value;
    while (*start == ' ') ++start;
    if (*start < '0' || *start > '9') return;
    const int day = atoi(start);
    // This export also carries WOD/HQII segment identifiers, not only dates.
    if (day < 0 || day > 99) return;
    snprintf(operDateValue, sizeof(operDateValue), "%d", day);
    if (currentPage == PAGE_OPER_DATE_LOAD || currentPage == PAGE_VERIFY_WOD_MWOD ||
        currentPage == PAGE_HQ_WOD_LOAD || currentPage == PAGE_HQ_FMT_LOAD)
    {
        if (currentPage == PAGE_HQ_WOD_LOAD || currentPage == PAGE_HQ_FMT_LOAD)
            drawHQLoadNumber(operDateValue, currentPage == PAGE_HQ_FMT_LOAD);
        else
            drawPresetChannel(operDateValue);
        refreshDisplay();
    }
}

void showOperDateLoadScreen()
{
    showThreeItemMenu(
        PAGE_OPER_DATE_LOAD,
        "EXIT", nullptr,
        "LOAD", nullptr,
        "OPER. DATE", nullptr
    );
    drawPresetChannel(operDateValue);
    refreshDisplay();
}


// ==================================================
// VERIFY WOD/MWOD
// One-line label as requested.
// ==================================================
void showVerifyWodMwodScreen()
{
    showThreeItemMenu(
        PAGE_VERIFY_WOD_MWOD,
        "EXIT", nullptr,
        "VERIFY", "WOD/MWOD",
        "", nullptr
    );
    drawPresetChannel(operDateValue);
    refreshDisplay();
}

void setHQFrequencyValue(const char* value)
{
    bool digit = false;
    for (unsigned int i=0; i<7 && value[i]; ++i)
        if (value[i]>='0' && value[i]<='9') digit=true;
    if (!digit) return;
    strncpy(hqFrequencyValue, value, 7);
    hqFrequencyValue[7]='\0';
    if (currentPage == PAGE_HQ_WOD_LOAD || currentPage == PAGE_HQ_FMT_LOAD)
    {
        drawFrequencyValue(hqFrequencyValue);
        refreshDisplay();
    }
}

void showHQWodLoadScreen()
{
    showThreeItemMenu(PAGE_HQ_WOD_LOAD, "EXIT", nullptr,
        "LOAD", "WOD", "", nullptr);
    drawHQLoadNumber(operDateValue, false);
    drawFrequencyValue(hqFrequencyValue);
    refreshDisplay();
}

void showHQFmtLoadScreen()
{
    showThreeItemMenu(PAGE_HQ_FMT_LOAD, "EXIT", nullptr,
        "LOAD", "HQII FMT", "", nullptr);
    drawHQLoadNumber(operDateValue, true);
    drawFrequencyValue(hqFrequencyValue);
    refreshDisplay();
}

void showHQWodEraseScreen()
{
    showThreeItemMenu(PAGE_HQ_WOD_ERASE, "EXIT/NO", nullptr,
        "", nullptr, "YES", nullptr);
    const char* lines[] = {"ARE YOU SURE", "YOU WANT TO", "ERASE WODS?"};
    for (int i=0; i<3; ++i)
    {
        const int16_t x=(480-getSwanseaTextWidth(lines[i], DEFAULT_SCALE))/2;
        drawSwanseaText(x, 140+i*28, lines[i], DEFAULT_SCALE, ARC210_GREEN);
    }
    refreshDisplay();
}


// ==================================================
// HQ MORE CHAIN
// Repeated OPER. DATE LOAD and VERIFY WOD/MWOD items
// are navigation links back to the existing pages.
// Undefined function pages are explicitly marked.
// ==================================================
void showHQMore1Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_1,
        "EXIT", nullptr,
        "VERIFY WOD/MWOD", nullptr,
        "MORE", nullptr);
}

void showHQMore2Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_2,
        "EXIT", nullptr,
        "WOD LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore3Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_3,
        "EXIT", nullptr,
        "WOD ERASE", nullptr,
        "MORE", nullptr);
}

void showHQMore4Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_4,
        "EXIT", nullptr,
        "HQ II FMT", nullptr,
        "MORE", nullptr);
}

void showHQMore5Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_5,
        "EXIT", nullptr,
        "OPER. DATE LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore6Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_6,
        "EXIT", nullptr,
        "VERIFY WOD/MWOD", nullptr,
        "MORE", nullptr);
}

void showHQMore7Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_7,
        "EXIT", nullptr,
        "WOD LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore8Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_8,
        "EXIT", nullptr,
        "WOD ERASE", nullptr,
        "MORE", nullptr);
}

void showHQMore9Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_9,
        "EXIT", nullptr,
        "HQ II FMT", nullptr,
        "MORE", nullptr);
}

void showHQMore10Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_10,
        "EXIT", nullptr,
        "OPER. DATE LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore11Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_11,
        "EXIT", nullptr,
        "VERIFY WOD/MWOD", nullptr,
        "MORE", nullptr);
}

void showHQMore12Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_12,
        "EXIT", nullptr,
        "WOD LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore13Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_13,
        "EXIT", nullptr,
        "MOD ERASE -- Not Defined", nullptr,
        "MORE", nullptr);
}

void showHQMore14Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_14,
        "EXIT", nullptr,
        "HQ II INIT -- Not Defined", nullptr,
        "MORE", nullptr);
}

// Loop section after HQ II INIT.
void showHQMore15Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_15,
        "EXIT", nullptr,
        "OPER. DATE LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore16Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_16,
        "EXIT", nullptr,
        "VERIFY WOD/MWOD", nullptr,
        "MORE", nullptr);
}

void showHQMore17Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_17,
        "EXIT", nullptr,
        "WOD LOAD", nullptr,
        "MORE", nullptr);
}

void showHQMore18Screen()
{
    showThreeItemMenu(PAGE_HQ_MORE_18,
        "EXIT", nullptr,
        "MOD ERASE -- Not Defined", nullptr,
        "MORE", nullptr);
}



// ==================================================
// COMSEC MAIN MENU
// Middle LSK alternates LOS COMSEC and DAMA/SATCOM COMSEC.
// Lower LSK opens the MORE branch for the selected mode.
// ==================================================
void showComsecMenuScreen(bool damaSatcomSelected)
{
    // LOS and DAMA/SATCOM share the same logical page.
    // Force a redraw so Middle LSK immediately updates the label.
    currentPage = PAGE_NONE;

    showThreeItemMenu(
        PAGE_COMSEC,
        "EXIT", nullptr,
        damaSatcomSelected ? "DAMA/SATCOM COMSEC" : "LOS COMSEC", nullptr,
        "MORE", nullptr
    );
}


// ==================================================
// COMSEC LOAD PLACEHOLDER
// EXIT/LOAD opens this page. The actual LOAD screen has
// not been defined yet.
// ==================================================
void showComsecLoadScreen(bool dama)
{
    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_COMSEC_LOAD;
    const char* lines[] = {dama ? "DAMA" : "LOS", "COMSEC", "PARAMETERS", "UPDATED"};
    for (int i = 0; i < 4; ++i)
    {
        const int16_t x = (480 - getSwanseaTextWidth(lines[i], DEFAULT_SCALE)) / 2;
        drawSwanseaText(x, 120 + i * 28, lines[i], DEFAULT_SCALE, ARC210_GREEN);
    }
    drawRT1();
    refreshDisplay();
}


// ==================================================
// LOS COMSEC MORE CHAIN
//
// MORE sequence:
// KY-58 DATA -> BASEBAND -> DATA RATE: 16K ->
// DIGITAL DATA -> KY-58 DATA -> BASEBAND ->
// then loop back to the earlier BASEBAND page.
//
// EXIT/LOAD opens the LOAD placeholder page.
// ==================================================
void showComsecLosMore1Screen(const char* dataMode)
{
    // The middle LSK cycles KY-58 DATA / KG-84 DATA / KY-58 VOICE.
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_1,
        "EXIT/LOAD", nullptr,
        dataMode, nullptr,
        "MORE", nullptr);
}

void showComsecLosMore2Screen(bool diphase)
{
    // Redraw when MLSK changes the selection on this same page.
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_2,
        "EXIT/LOAD", nullptr,
        diphase ? "DIPHASE" : "BASEBAND", nullptr,
        "MORE", nullptr);
}

void showComsecLosMore3Screen(bool cvsd12k)
{
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_3,
        "EXIT/LOAD", nullptr,
        cvsd12k ? "CVSD  12K" : "CVSD  16K", nullptr,
        "MORE", nullptr);
}

void showComsecLosMore4Screen(bool analogData)
{
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_4,
        "EXIT/LOAD", nullptr,
        analogData ? "ANALOG DATA" : "DIGITAL DATA", nullptr,
        "MORE", nullptr);
}

void showComsecLosMore5Screen(const char* dataMode)
{
    // Same three-state data-mode cycle as the first KY-58 DATA page.
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_5,
        "EXIT/LOAD", nullptr,
        dataMode, nullptr,
        "MORE", nullptr);
}

void showComsecLosMore6Screen(bool diphase)
{
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_6,
        "EXIT/LOAD", nullptr,
        diphase ? "DIPHASE" : "BASEBAND", nullptr,
        "MORE", nullptr);
}

// The second CVSD page follows the second BASEBAND page.
void showComsecLosMore7Screen(bool cvsd12k)
{
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_7,
        "EXIT/LOAD", nullptr,
        cvsd12k ? "CVSD  12K" : "CVSD  16K", nullptr,
        "MORE", nullptr);
}

void showComsecLosMore8Screen(const char* dataMode)
{
    currentPage = PAGE_NONE;
    showThreeItemMenu(PAGE_COMSEC_LOS_MORE_8,
        "EXIT/LOAD", nullptr,
        dataMode, nullptr,
        "MORE", nullptr);
}


// ==================================================
// DAMA/SATCOM COMSEC MORE CHAIN
// ANDVT VOICE -> ANDVT DATA -> DATA RATE: 300 ->
// loop back to ANDVT DATA.
// ==================================================
void showComsecDamaMoreScreen()
{
    showThreeItemMenu(PAGE_COMSEC_DAMA_MORE,
        "EXIT/LOAD", nullptr,
        "ANDVT VOICE", nullptr,
        "", nullptr);
}

void showComsecDamaDataScreen()
{
    showThreeItemMenu(PAGE_COMSEC_DAMA_DATA,
        "EXIT/LOAD", nullptr,
        "ANDVT DATA", nullptr,
        "MORE", nullptr);
}

void showComsecDamaRate300Screen()
{
    showThreeItemMenu(PAGE_COMSEC_DAMA_RATE_300,
        "EXIT/LOAD", nullptr,
        "DATA RATE: 300", nullptr,
        "MORE", nullptr);
}

void showComsecKg84RateScreen(const char* rate)
{
    char label[24];
    snprintf(label, sizeof(label), "DATA RATE: %s", rate);
    currentPage = PAGE_NONE; // Refresh the value on the same menu page.
    showThreeItemMenu(PAGE_COMSEC_KG84_RATE,
        "EXIT/LOAD", nullptr,
        label, nullptr,
        "MORE", nullptr);
}


// ==================================================
// RADIO SETTINGS
// ==================================================
void showRadioSettingsScreen()
{
    showThreeItemMenu(
        PAGE_RADIO_SETTINGS,
        "EXIT", nullptr,
        "RADIO ID NUMBERS", nullptr,
        "MORE", nullptr
    );
}


// ==================================================
// RADIO SETTINGS MORE CHAIN
// PRESET -> DAMA -> BEEP -> USER DATA PORT ->
// SWITCH TEST -> ENTER KEY ENABLE -> RADIO SETTINGS.
// Page 6 MORE returns to the main RADIO SETTINGS page.
// ==================================================
void showRadioMore1Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_1,
        "EXIT", nullptr,
        "PRESET CH. 26-30", nullptr,
        "MORE", nullptr);
}

void showRadioMore2Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_2,
        "EXIT", nullptr,
        "DAMA CHANNELS", nullptr,
        "MORE", nullptr);
}

void showRadioMore3Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_3,
        "EXIT", nullptr,
        "BEEP ENABLE", nullptr,
        "MORE", nullptr);
}

void showRadioMore4Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_4,
        "EXIT", nullptr,
        "USER DATA PORT", nullptr,
        "MORE", nullptr);
}

void showRadioMore5Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_5,
        "EXIT", nullptr,
        "SWITCH TEST", nullptr,
        "MORE", nullptr);
}

void showRadioMore6Screen()
{
    showThreeItemMenu(PAGE_RADIO_MORE_6,
        "EXIT", nullptr,
        "ENTER KEY ENABLE", nullptr,
        "MORE", nullptr);
}


// ==================================================
// RADIO SETTINGS SUBMENUS
// ==================================================
void showRadioIdNumbersScreen()
{
    showThreeItemMenu(PAGE_RADIO_ID_NUMBERS,
        "EXIT/LOAD", nullptr,
        "RT1:  1", nullptr,
        "", nullptr);
}

void showRadioPreset2630Screen(bool halfDuplex)
{
    // SATCOM ONLY and HALF DUPLEX use the same logical menu page. Force the
    // page to redraw so a Middle LSK press visibly changes the selection.
    currentPage = PAGE_NONE;

    showThreeItemMenu(PAGE_RADIO_PRESET_26_30,
        "EXIT/LOAD", nullptr,
        halfDuplex ? "HALF DUPLEX" : "SATCOM ONLY", nullptr,
        "", nullptr);
}

void showRadioDamaChannelsScreen(bool ch41To50)
{
    // Both choices share one logical page, so a changed selection must redraw.
    currentPage = PAGE_NONE;

    showThreeItemMenu(PAGE_RADIO_DAMA_CHANNELS,
        "EXIT/LOAD", nullptr,
        ch41To50 ? "DAMA CH. 41-50" : "DAMA CH. 31-40", nullptr,
        "", nullptr);
}

void showRadioBeepEnableScreen(bool disabled)
{
    // Both choices share one logical page, so a changed selection must redraw.
    currentPage = PAGE_NONE;

    showThreeItemMenu(PAGE_RADIO_BEEP_ENABLE,
        "EXIT/LOAD", nullptr,
        disabled ? "BEEP DISABLE" : "BEEP ENABLED", nullptr,
        "", nullptr);
}

void showRadioUserDataWidebandScreen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_WIDEBAND,
        "EXIT/LOAD", nullptr,
        "WIDEBAND", nullptr,
        "MORE", nullptr);
}

void showRadioUserData188144Screen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_188_144,
        "EXIT/LOAD", nullptr,
        "188-144", nullptr,
        "MORE", nullptr);
}

void showRadioUserDataSynchronousScreen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_SYNCHRONOUS,
        "EXIT/LOAD", nullptr,
        "SYNCHRONOUS", nullptr,
        "MORE", nullptr);
}

void showRadioUserDataAsyncScreen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_ASYNC,
        "EXIT/LOAD", nullptr,
        "ASYNCHRONOUS", nullptr,
        "MORE", nullptr);
}

void showRadioUserDataExternalClockScreen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_EXTERNAL_CLOCK,
        "EXIT/LOAD", nullptr,
        "EXTERNAL CLOCK", nullptr,
        "MORE", nullptr);
}

void showRadioUserDataInternalClockScreen()
{
    showThreeItemMenu(PAGE_RADIO_USER_DATA_INTERNAL_CLOCK,
        "EXIT", nullptr,
        "INTERNAL CLOCK", nullptr,
        "MORE", nullptr);
}

static void drawRadioSwitchTestScreen(const char* lowerLine)
{
    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_RADIO_SWITCH_TEST;

    drawSwanseaText(20, 45, "EXIT", DEFAULT_SCALE, ARC210_GREEN);
    drawRT1();

    drawSwanseaText(20, 145, "LIGHT", DEFAULT_SCALE, ARC210_GREEN);
    drawSwanseaText(20, 179, "TEST", DEFAULT_SCALE, ARC210_GREEN);

    const float rightScale = DEFAULT_SCALE;
    // Align the E in MODE with the 3 in the RT part number's final 038.
    const int16_t rightEdge = 150 +
        getSwanseaTextWidth("984-1528-03", DEFAULT_SCALE);
    const int16_t modeWidth = getSwanseaTextWidth("TEST MODE", rightScale);
    // Center the heading over TEST MODE, as on the radio display.
    drawSwanseaText(
        rightEdge - modeWidth +
            (modeWidth - getSwanseaTextWidth("SWITCH", rightScale)) / 2,
        145,
        "SWITCH",
        rightScale,
        ARC210_GREEN
    );
    drawSwanseaText(
        rightEdge - getSwanseaTextWidth("TEST MODE", rightScale),
        179,
        "TEST MODE",
        rightScale,
        ARC210_GREEN
    );
    // Use the same font size throughout all three test screens. Keep the
    // part number in its own column and the status directly beneath it.
    drawSwanseaText(20, 245, "RT:", DEFAULT_SCALE, ARC210_GREEN);
    drawSwanseaText(150, 245, "984-1528-038", DEFAULT_SCALE, ARC210_GREEN);
    if (strncmp(lowerLine, "RCV: ", 5) == 0)
    {
        drawSwanseaText(20, 279, "RCV:", DEFAULT_SCALE, ARC210_GREEN);
        drawSwanseaText(150, 279, lowerLine + 5, DEFAULT_SCALE, ARC210_GREEN);
    }
    else
    {
        drawSwanseaText(20, 279, lowerLine, DEFAULT_SCALE, ARC210_GREEN);
    }

    refreshDisplay();
}

void showRadioSwitchTestScreen()
{
    drawRadioSwitchTestScreen("RCV: 984-1541-007");
}

void showRadioSwitchTestMenuScreen()
{
    drawRadioSwitchTestScreen("MENU TIME");
}

void showRadioSwitchTestXmtRcvScreen()
{
    drawRadioSwitchTestScreen("XMT/RCV SEND");
}

void showRadioEnterKeyScreen(bool disabled)
{
    // Both choices share one logical page, so a changed selection must redraw.
    currentPage = PAGE_NONE;

    showThreeItemMenu(PAGE_RADIO_ENTER_KEY_ENABLE,
        "EXIT/LOAD", nullptr,
        disabled ? "ENTER KEY DISABLED" : "ENTER KEY ENABLED", nullptr,
        "", nullptr);
}


// ==================================================
// COMMON STATIC RADIO ELEMENTS
//
// All of these functions are implemented in
// DisplayCommon.cpp.
// ==================================================
void drawCommonRadioElements()
{
    drawRT1();
    drawKY58();
    drawKY58Status("VOICE");
}


// ==================================================
// PRESET-ONLY ELEMENT
// ENCRYPTION NUMBER
// ==================================================
void drawEncryptionNumber(unsigned int encryptionNumber)
{
    char value[3];

    snprintf(
        value,
        sizeof(value),
        "%u",
        encryptionNumber
    );

    // Clear only the actual encryption-number text area.
    // Use the maximum expected two-character width so a shorter
    // new value completely removes the previous value.
    const int16_t BASE_HEIGHT = 18;

    int16_t clearWidth =
        getSwanseaTextWidth(
            "88",
            ENCRYPTION_SCALE
        );

    int16_t clearHeight =
        (int16_t)(BASE_HEIGHT * ENCRYPTION_SCALE);

    tft.fillRect(
        ENCRYPTION_X,
        ENCRYPTION_Y - clearHeight,
        clearWidth,
        clearHeight + 2,
        ILI9488_BLACK
    );

    drawSwanseaText(
        ENCRYPTION_X,
        ENCRYPTION_Y,
        value,
        ENCRYPTION_SCALE,
        ARC210_GREEN
    );
}

static char radioKyLabel[2] = "";

void setRadioKyLabel(const char* label)
{
    radioKyLabel[0] = label[0];
    radioKyLabel[1] = '\0';
}

static void drawRadioKyLabel(const char* comsecSubmode)
{
    // Cover the full Swansea glyph height, including pixels above the old
    // 18-pixel clearing box and below the baseline.
    const int16_t ascent = (int16_t)(28 * ENCRYPTION_SCALE) + 2;
    const int16_t descent = (int16_t)(8 * ENCRYPTION_SCALE) + 2;
    tft.fillRect(ENCRYPTION_X - 2, ENCRYPTION_Y - ascent,
        getSwanseaTextWidth("88", ENCRYPTION_SCALE) + 4,
        ascent + descent, ILI9488_BLACK);
    if (strcmp(comsecSubmode, "CT") == 0 || strcmp(comsecSubmode, "CT-TD") == 0)
        drawSwanseaText(ENCRYPTION_X, ENCRYPTION_Y, radioKyLabel,
            ENCRYPTION_SCALE, ARC210_GREEN);
}


// ==================================================
// COMMON ELEMENT
// UNAVAILABLE
// ==================================================
void drawUnavailableText()
{
    const char* text = "UNAVAILABLE";
    float scale = 1.50f;

    int16_t textWidth =
        getSwanseaTextWidth(
            text,
            scale
        );

    int16_t textX =
        (480 - textWidth) / 2;

    drawSwanseaText(
        textX,
        165,
        text,
        scale,
        ARC210_GREEN
    );
}


// ==================================================
// POWER-UP SCREEN
// ==================================================
void showPowerUpScreen()
{
    if (currentPage == PAGE_BOOT)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_BOOT;

    const char* title = "POWER UP LOADER";
    float titleScale = 1.25f;

    int16_t titleWidth =
        getSwanseaTextWidth(
            title,
            titleScale
        );

    int16_t titleX =
        (480 - titleWidth) / 2;

    drawSwanseaText(
        titleX,
        55,
        title,
        titleScale,
        ARC210_GREEN
    );

    drawSwanseaText(
        20,
        165,
        "VER: 984-1541-007",
        1.25f,
        ARC210_GREEN
    );

    drawSwanseaText(
        20,
        295,
        "CHECKING PAGE 1",
        1.25f,
        ARC210_GREEN
    );

    refreshDisplay();
}




// ==================================================
// STATIC GUARD PAGE HEADER
//
// Left side : VHF / UHF
// Center    : GUARD
// Right side: RT1
//
// This header is unique to the fixed GUARD pages.
// ==================================================
void drawStaticGuardHeader(const char* band)
{
    // VHF / UHF in the old PREV location
    drawSwanseaText(
        GUARD_BAND_X,
        GUARD_BAND_Y,
        band,
        GUARD_BAND_SCALE,
        ARC210_GREEN
    );

    // Center GUARD on the 480-pixel display
    const char* guardText = "GUARD";

    int16_t guardWidth =
        getSwanseaTextWidth(
            guardText,
            GUARD_HEADER_SCALE
        );

    int16_t guardX =
        (480 - guardWidth) / 2;

    drawSwanseaText(
        guardX,
        GUARD_HEADER_Y,
        guardText,
        GUARD_HEADER_SCALE,
        ARC210_GREEN
    );

    // Keep RT1 in its normal common location
    drawRT1();
}


// ==================================================
// STATIC GUARD SCREEN - 243.000 MHz
//
// Selected by ARC210_SEC_SW position 5.
//
// This page does NOT depend on DCS-BIOS frequency,
// modulation, COMSEC, or XMIT/RECV display strings.
// The secondary selector position alone determines
// the contents of this page.
// ==================================================
void showGuard243Screen(const char* modulation)
{
    if (currentPage == PAGE_GUARD_243)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_GUARD_243;

    // GUARD-only top row
    drawStaticGuardHeader("UHF");

    // Reuse the PRESET body layout
    drawKY58();
    drawKY58Status("VOICE");
    drawFrequencyValue("243.000");
    refreshDisplay();
}


// ==================================================
// STATIC GUARD SCREEN - 121.500 MHz
//
// Selected by ARC210_SEC_SW position 6.
//
// This page does NOT depend on DCS-BIOS frequency,
// modulation, COMSEC, or XMIT/RECV display strings.
// The secondary selector position alone determines
// the contents of this page.
// ==================================================
void showGuard121Screen(const char* modulation)
{
    if (currentPage == PAGE_GUARD_121)
    {
        return;
    }

    tft.fillScreen(ILI9488_BLACK);
    currentPage = PAGE_GUARD_121;

    // GUARD-only top row
    drawStaticGuardHeader("VHF");

    // Reuse the PRESET body layout
    drawKY58();
    drawKY58Status("VOICE");
    drawFrequencyValue("121.500");
    refreshDisplay();
}


// ==================================================
// SHARED MAN / PRESET RADIO BODY
//
// MAN and PRESET use this exact same drawing path for:
//   COMSEC submode
//   AM / FM
//   Frequency
//
// This keeps the AM/FM rendering identical between
// the MAN and PRESET screens.
// ==================================================
void drawNormalRadioBody(
    const char* frequency,
    const char* modulation,
    const char* comsecSubmode
)
{
    drawComsecSubmode(comsecSubmode);
    drawAMFM(modulation);
    drawFrequencyValue(frequency);
}


// ==================================================
// NORMAL FREQUENCY SCREEN
// ==================================================
void showFrequencyScreen(
    const char* frequency,
    const char* modulation,
    const char* previousFrequency,
    const char* comsecSubmode
)
{
    if (currentPage != PAGE_FREQUENCY)
    {
        tft.fillScreen(ILI9488_BLACK);
        currentPage = PAGE_FREQUENCY;

        drawCommonRadioElements();
    }

    drawPREV(previousFrequency);

    drawNormalRadioBody(
        frequency,
        modulation,
        comsecSubmode
    );

    drawRadioKyLabel(comsecSubmode);

    refreshDisplay();
}


// ==================================================
// PRESET SCREEN
// ==================================================
void showPresetScreen(
    const char* activeChannel,
    const char* frequency,
    const char* modulation,
    const char* comsecSubmode,
    unsigned int encryptionNumber
)
{
    if (currentPage != PAGE_PRESET)
    {
        tft.fillScreen(ILI9488_BLACK);
        currentPage = PAGE_PRESET;

        drawCommonRadioElements();
    }

    // Shared body items
    drawComsecSubmode(comsecSubmode);
    drawFrequencyValue(frequency);

    // Preset-only items

    // AM/FM uses the shared global routine
    drawAMFM(modulation);

    // Draw channel last so no later preset field can erase it.
    drawPresetChannel(activeChannel);
    drawRadioKyLabel(comsecSubmode);
    refreshDisplay();
}
