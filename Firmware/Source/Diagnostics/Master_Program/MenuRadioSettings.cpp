#include "MenuRadioSettings.h"
#include "MenuState.h"
#include <Display.h>

static bool isExitLoadPage()
{
    return currentMenuPage == ARC210_MENU_RADIO_ID_NUMBERS ||
           currentMenuPage == ARC210_MENU_RADIO_PRESET_26_30 ||
           currentMenuPage == ARC210_MENU_RADIO_DAMA_CHANNELS ||
           currentMenuPage == ARC210_MENU_RADIO_BEEP_ENABLE ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_WIDEBAND ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_188_144 ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_SYNCHRONOUS ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_ASYNC ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_EXTERNAL_CLOCK ||
           currentMenuPage == ARC210_MENU_RADIO_USER_DATA_INTERNAL_CLOCK ||
           currentMenuPage == ARC210_MENU_RADIO_ENTER_KEY_ENABLE;
}

bool menuRadioHandleUpper()
{
    if (isExitLoadPage())
    {
        return true; // LOAD/EXIT handled by MenuNavigation
    }
    if (currentMenuPage == ARC210_MENU_RADIO_SWITCH_TEST)
        return true; // plain EXIT handled by MenuNavigation

    switch (currentMenuPage)
    {
        case ARC210_MENU_RADIO_SETTINGS:
        case ARC210_MENU_RADIO_MORE_1:
        case ARC210_MENU_RADIO_MORE_2:
        case ARC210_MENU_RADIO_MORE_3:
        case ARC210_MENU_RADIO_MORE_4:
        case ARC210_MENU_RADIO_MORE_5:
        case ARC210_MENU_RADIO_MORE_6:
            return true; // plain EXIT handled by MenuNavigation
        default:
            return false;
    }
}

bool menuRadioHandleMiddle()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_RADIO_SETTINGS:
            currentMenuPage=ARC210_MENU_RADIO_ID_NUMBERS; showRadioIdNumbersScreen(); return true;
        case ARC210_MENU_RADIO_MORE_1:
    // PRESET CH. 26-30 opens on HALF DUPLEX. Each following
    // Middle LSK press alternates HALF DUPLEX and SATCOM ONLY.
    radioPresetHalfDuplex=true; currentMenuPage=ARC210_MENU_RADIO_PRESET_26_30; showRadioPreset2630Screen(radioPresetHalfDuplex); return true;
        case ARC210_MENU_RADIO_MORE_2:
            // DAMA CHANNELS opens on 31-40. Each following Middle LSK press
            // alternates between 31-40 and 41-50.
            radioDama41To50=false; currentMenuPage=ARC210_MENU_RADIO_DAMA_CHANNELS; showRadioDamaChannelsScreen(radioDama41To50); return true;
        case ARC210_MENU_RADIO_MORE_3:
            // BEEP ENABLE opens on BEEP DISABLE. Each following Middle LSK
            // press alternates between BEEP DISABLE and BEEP ENABLED.
            radioBeepDisabled=true; currentMenuPage=ARC210_MENU_RADIO_BEEP_ENABLE; showRadioBeepEnableScreen(radioBeepDisabled); return true;
        case ARC210_MENU_RADIO_MORE_4:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_WIDEBAND; showRadioUserDataWidebandScreen(); return true;
        case ARC210_MENU_RADIO_MORE_5:
            currentMenuPage=ARC210_MENU_RADIO_SWITCH_TEST;
            showRadioSwitchTestScreen();
            return true;
        case ARC210_MENU_RADIO_MORE_6:
            radioEnterDisabled=false; currentMenuPage=ARC210_MENU_RADIO_ENTER_KEY_ENABLE; showRadioEnterKeyScreen(radioEnterDisabled); return true;
        case ARC210_MENU_RADIO_ID_NUMBERS:
            return true;
        case ARC210_MENU_RADIO_PRESET_26_30:
            radioPresetHalfDuplex=!radioPresetHalfDuplex; showRadioPreset2630Screen(radioPresetHalfDuplex); return true;
        case ARC210_MENU_RADIO_DAMA_CHANNELS:
            radioDama41To50=!radioDama41To50; showRadioDamaChannelsScreen(radioDama41To50); return true;
        case ARC210_MENU_RADIO_BEEP_ENABLE:
            radioBeepDisabled=!radioBeepDisabled; showRadioBeepEnableScreen(radioBeepDisabled); return true;
        case ARC210_MENU_RADIO_USER_DATA_WIDEBAND:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_188_144; showRadioUserData188144Screen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_188_144:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_WIDEBAND; showRadioUserDataWidebandScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_SYNCHRONOUS:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_ASYNC; showRadioUserDataAsyncScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_ASYNC:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_EXTERNAL_CLOCK; showRadioUserDataExternalClockScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_EXTERNAL_CLOCK:
        case ARC210_MENU_RADIO_USER_DATA_INTERNAL_CLOCK:
            return true;
        case ARC210_MENU_RADIO_SWITCH_TEST:
            return true;
        case ARC210_MENU_RADIO_ENTER_KEY_ENABLE:
            radioEnterDisabled=!radioEnterDisabled; showRadioEnterKeyScreen(radioEnterDisabled); return true;
        default:
            return false;
    }
}

bool menuRadioShowMenuTest()
{
    if (currentMenuPage != ARC210_MENU_RADIO_SWITCH_TEST) return false;
    showRadioSwitchTestMenuScreen();
    return true;
}

bool menuRadioShowXmtRcvTest()
{
    if (currentMenuPage != ARC210_MENU_RADIO_SWITCH_TEST) return false;
    showRadioSwitchTestXmtRcvScreen();
    return true;
}

bool menuRadioHandleLower()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_RADIO_SETTINGS:
            currentMenuPage=ARC210_MENU_RADIO_MORE_1; showRadioMore1Screen(); return true;
        case ARC210_MENU_RADIO_MORE_1:
            currentMenuPage=ARC210_MENU_RADIO_MORE_2; showRadioMore2Screen(); return true;
        case ARC210_MENU_RADIO_MORE_2:
            currentMenuPage=ARC210_MENU_RADIO_MORE_3; showRadioMore3Screen(); return true;
        case ARC210_MENU_RADIO_MORE_3:
            currentMenuPage=ARC210_MENU_RADIO_MORE_4; showRadioMore4Screen(); return true;
        case ARC210_MENU_RADIO_MORE_4:
            currentMenuPage=ARC210_MENU_RADIO_MORE_5; showRadioMore5Screen(); return true;
        case ARC210_MENU_RADIO_MORE_5:
            currentMenuPage=ARC210_MENU_RADIO_MORE_6; showRadioMore6Screen(); return true;
        case ARC210_MENU_RADIO_MORE_6:
            currentMenuPage=ARC210_MENU_RADIO_SETTINGS; showRadioSettingsScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_WIDEBAND:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_SYNCHRONOUS; showRadioUserDataSynchronousScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_188_144:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_SYNCHRONOUS; showRadioUserDataSynchronousScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_SYNCHRONOUS:
        case ARC210_MENU_RADIO_USER_DATA_ASYNC:
        case ARC210_MENU_RADIO_USER_DATA_EXTERNAL_CLOCK:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_INTERNAL_CLOCK; showRadioUserDataInternalClockScreen(); return true;
        case ARC210_MENU_RADIO_USER_DATA_INTERNAL_CLOCK:
            currentMenuPage=ARC210_MENU_RADIO_USER_DATA_WIDEBAND; showRadioUserDataWidebandScreen(); return true;
        case ARC210_MENU_RADIO_ID_NUMBERS:
        case ARC210_MENU_RADIO_PRESET_26_30:
        case ARC210_MENU_RADIO_DAMA_CHANNELS:
        case ARC210_MENU_RADIO_BEEP_ENABLE:
        case ARC210_MENU_RADIO_ENTER_KEY_ENABLE:
            return true;
        case ARC210_MENU_RADIO_SWITCH_TEST:
            showRadioSwitchTestScreen();
            return true;
        default:
            return false;
    }
}
