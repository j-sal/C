#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    initApp();

    int usrSel=-1;

    while(usrSel != 0)
    {
        usrSel = printMainMenu();

        switch(usrSel)
        {
        case 1:
            {
                printf("\n            Start a Game\n");
                playGame();

            }
            break;
        case 2:
            printf("\n            Load the Board\n");
            break;
        case 3:
            {
                printf("\n            See the Rank List\n");
                prRankList();
            }
            break;
        case 4:
            {
                printf("\n            View the Rules\n");
                prGameRules();
            }
            break;
        case 5:
            {
                printf("\n              About Us\n");
                prAboutUs();
            }
            break;
        case 0:
            printf("\n           Exit the Program\n");
            break;
        default:
            break;
        }
    }
    exitApp();
    return 0;
}

