#include "MenuComsec.h"
#include "MenuState.h"
#include <Display.h>

static bool losDiphaseSelected = false;
static bool secondLosDiphaseSelected = true;
static bool losCvsd12kSelected = false;
static bool secondLosCvsd12kSelected = false;
static bool analogDataSelected = false;
// Keep both 12K entries: they are separate steps in the confirmed MLSK cycle.
static const char* const kg84DataRates[] = {
    "300", "600", "1.2K", "2.4K", "4.8", "6K", "8K", "9.6K",
    "12K", "16K", "19.2K", "12K", "32K", "38.4K", "75"
};
static const unsigned int kg84RateCount =
    sizeof(kg84DataRates) / sizeof(kg84DataRates[0]);
static unsigned int kg84RateIndex = 0;

static void showLosBasebandMenu()
{
    // MORE returns to BASEBAND; MLSK can select DIPHASE on this page.
    losDiphaseSelected = false;
    currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_2;
    showComsecLosMore2Screen(losDiphaseSelected);
}

void menuComsecShowMain()
{
    currentMenuPage = ARC210_MENU_COMSEC;
    showComsecMenuScreen(damaSatcomComsecSelected);
}

bool menuComsecHandleUpper()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_COMSEC:
            return true; // EXIT handled by MenuNavigation
        case ARC210_MENU_COMSEC_LOAD:
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_1:
        case ARC210_MENU_COMSEC_LOS_MORE_2:
        case ARC210_MENU_COMSEC_KG84_RATE:
        case ARC210_MENU_COMSEC_LOS_MORE_3:
        case ARC210_MENU_COMSEC_LOS_MORE_4:
        case ARC210_MENU_COMSEC_LOS_MORE_5:
        case ARC210_MENU_COMSEC_LOS_MORE_6:
        case ARC210_MENU_COMSEC_LOS_MORE_7:
        case ARC210_MENU_COMSEC_LOS_MORE_8:
        case ARC210_MENU_COMSEC_DAMA_MORE:
        case ARC210_MENU_COMSEC_DAMA_DATA:
        case ARC210_MENU_COMSEC_DAMA_RATE_300:
            return true; // LOAD/EXIT handled by MenuNavigation
        default:
            return false;
    }
}

bool menuComsecHandleMiddle()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_COMSEC:
            damaSatcomComsecSelected = !damaSatcomComsecSelected;
            showComsecMenuScreen(damaSatcomComsecSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_1:
            losDataModeIndex = (losDataModeIndex + 1) % 3;
            showComsecLosMore1Screen(currentLosDataModeLabel());
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_5:
            losDataModeIndex = (losDataModeIndex + 1) % 3;
            showComsecLosMore5Screen(currentLosDataModeLabel());
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_8:
            losDataModeIndex = (losDataModeIndex + 1) % 3;
            showComsecLosMore8Screen(currentLosDataModeLabel());
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_2:
            losDiphaseSelected = !losDiphaseSelected;
            showComsecLosMore2Screen(losDiphaseSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_3:
            losCvsd12kSelected = !losCvsd12kSelected;
            showComsecLosMore3Screen(losCvsd12kSelected);
            return true;
        case ARC210_MENU_COMSEC_KG84_RATE:
            kg84RateIndex = (kg84RateIndex + 1) % kg84RateCount;
            showComsecKg84RateScreen(kg84DataRates[kg84RateIndex]);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_6:
            secondLosDiphaseSelected = !secondLosDiphaseSelected;
            showComsecLosMore6Screen(secondLosDiphaseSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_7:
            secondLosCvsd12kSelected = !secondLosCvsd12kSelected;
            showComsecLosMore7Screen(secondLosCvsd12kSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_4:
            analogDataSelected = !analogDataSelected;
            showComsecLosMore4Screen(analogDataSelected);
            return true;
        case ARC210_MENU_COMSEC_LOAD:
        case ARC210_MENU_COMSEC_DAMA_MORE:
        case ARC210_MENU_COMSEC_DAMA_DATA:
        case ARC210_MENU_COMSEC_DAMA_RATE_300:
            return true;
        default:
            return false;
    }
}

bool menuComsecHandleLower()
{
    switch (currentMenuPage)
    {
        case ARC210_MENU_COMSEC:
            losDataModeIndex = 0; // Enter on KY-58 VOICE in either branch.
            if (damaSatcomComsecSelected)
            {
                // DAMA: KY-58 -> DIPHASE -> CVSD -> DIGITAL DATA -> KY-58.
                currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_5;
                showComsecLosMore5Screen(currentLosDataModeLabel());
            }
            else
            {
                // Open the first KY/KG selection.
                currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_1;
                showComsecLosMore1Screen(currentLosDataModeLabel());
            }
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_1:
            // The first KY page under LOS COMSEC opens DIPHASE.
            losDiphaseSelected = true;
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_2;
            showComsecLosMore2Screen(losDiphaseSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_2:
            losCvsd12kSelected = false;
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_3;
            showComsecLosMore3Screen(losCvsd12kSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_3:
            // BASEBAND -> CVSD -> KY-58 VOICE -> BASEBAND.
            losDataModeIndex = 0;
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_8;
            showComsecLosMore8Screen(currentLosDataModeLabel());
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_4:
            if (damaSatcomComsecSelected)
            {
                currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_5;
                showComsecLosMore5Screen(currentLosDataModeLabel());
            }
            else
            {
                currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_1;
                showComsecLosMore1Screen(currentLosDataModeLabel());
            }
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_5:
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_6;
            showComsecLosMore6Screen(secondLosDiphaseSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_6:
            secondLosCvsd12kSelected = false;
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_7;
            showComsecLosMore7Screen(secondLosCvsd12kSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_7:
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_4;
            showComsecLosMore4Screen(analogDataSelected);
            return true;
        case ARC210_MENU_COMSEC_LOS_MORE_8:
            showLosBasebandMenu();
            return true;
        case ARC210_MENU_COMSEC_DAMA_MORE:
            return true; // ANDVT VOICE has no MORE action.
        case ARC210_MENU_COMSEC_DAMA_DATA:
            currentMenuPage=ARC210_MENU_COMSEC_DAMA_RATE_300; showComsecDamaRate300Screen(); return true;
        case ARC210_MENU_COMSEC_DAMA_RATE_300:
            currentMenuPage=ARC210_MENU_COMSEC_DAMA_DATA; showComsecDamaDataScreen(); return true;
        case ARC210_MENU_COMSEC_KG84_RATE:
            currentMenuPage = ARC210_MENU_COMSEC_LOS_MORE_4;
            showComsecLosMore4Screen(analogDataSelected);
            return true;
        case ARC210_MENU_COMSEC_LOAD:
            return true;
        default:
            return false;
    }
}
