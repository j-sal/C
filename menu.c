#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#include "game_service.h"
#include "global.h"
#include "model.h"
#include "rank_serv.h"


void inputPt(Point* pspPoint);
void printChess();
void prWin(const int nColor);
void prDraw();
void prAddRank(const int nStep);

int printMainMenu()
{
    int usrSel=-1;

    printf("\n_________________________________________\n");
    printf("1.Start Game   2.Load Board   3.Rank List\n");
    printf("4.View Rules   5.About Us     0.Exit     \n");
    printf("-----------------------------------------\n");
    printf("\n\nPlease Select an Option: ");

    scanf("%d", &usrSel);
    fflush(stdin);

    return usrSel;
}

void playGame()
{

    int nStep = 0, nResult = JUDGE_PLAY;
    Point spPoint;

    initStat();
    printChess();

    do
    {
        spPoint.status = nStep % 2;

        inputPt(&spPoint);
        setStat(spPoint);
        printChess();
        nStep++;
        nResult = judge(spPoint);
    }while(nResult == JUDGE_PLAY);

    if(nResult == JUDGE_WIN)
    {
        prWin(spPoint.status);
        prAddRank(nStep);
    }
    else if(nResult == JUDGE_DRAW);
    {
        prDraw();
    }
}

void inputPt(Point* pspPoint)
{
    char acPoint[8];
    int nStat = STATUS_BLANK;

    while(TRUE)
    {
        printf("----------------------------------------------\n");
        if(pspPoint->status == 0)
        {
            printf("\nBlack stone move, please input coordinate number (i.e.:A0): \n");
        }
        else if(pspPoint->status == 1)
        {
            printf("\nWhite stone move, please input coordinate number (i.e.:A0): \n");
        }
        scanf("%s", &acPoint);

        pspPoint->col = toupper(acPoint[0]) - 'A';
        pspPoint->row = atoi(&acPoint[1]);

        if(pspPoint->row <0 || pspPoint->row >14 || pspPoint->col <0 || pspPoint->col >14)
        {
            printf("Coordinate Does NOT Exist!\n");

        }

        nStat = getStat(*pspPoint);

        if(nStat != STATUS_BLANK)
        {
            printf("Existing Stone!\n");
        }
        else
        {
            break;
        }
    }
}

void printChess()
{
    int i, j;
    int nStat = -1;
    Point spPoint;

    char cA = 'A';

    printf("\n_____________________________________________\n");

    printf("   ");

    for(i=0; i<15; i++)
    {
        printf("%c  ", cA+i);
    }

    printf("\n");

    for(i=0; i<15; i++)
    {
        printf(" %02d\n", i);
        for(j=0; j<15; j++)
        {
            spPoint.col = j;
            spPoint.row = i;
            nStat = getStat(spPoint);
            if(nStat == STATUS_BLANK)
            {
                printf(CHESS_BLANK);
            }
            else if(nStat == STATUS_BLACK)
            {
                printf(CHESS_BLACK);
            }
            else if(nStat == STATUS_WHITE)
            {
                printf(CHESS_WHITE);
            }
        }
        printf("\n");
    }
}

void initApp()
{
    printf("\n          ++++++++++++++++++\n");
    printf("          +Welcome to Renju+\n");
    printf("          ++++++++++++++++++\n");

    initRanks();
}

void prWin(const int nColor)
{
    if(nColor == 0)
    {
        printf("\n          ++++++++++++++++++\n");
        printf("          +  BLACK WINS!!  +\n");
        printf("          ++++++++++++++++++\n");
    }
    else if(nColor == 1)
    {
        printf("\n          ++++++++++++++++++\n");
        printf("          +  WHITE WINS!!  +\n");
        printf("          ++++++++++++++++++\n");
    }
}

void prDraw()
{
    printf("\n          ++++++++++++++++++\n");
    printf("          +  DRAW  GAME!!  +\n");
    printf("          ++++++++++++++++++\n");
}
void prGameRules()
{
    printf("\n_____________________________________________\n");
    printf("          +    RULES!!    +\n");
    printf("----------------------------------------------\n");
    printf("1.RENJU is a 2-player game competing against each other.\n");
    printf("2.Black moves first, followed by White.\n");
    printf("3.The Board is 15x15.\n");
    printf("4.To Win: Get an UNBROKEN row of 5 stones, either horizontally, vertically or in diagonal.\n");
    printf("5.A Draw will occur if all moves are exhausted without a player achieving 5 consecutive stones.\n");
    printf("6.Columns are LETTERS, Rows are NUMERIC.\n");
    printf("7.To Move the Stone: input row and column of desired position.\n");
    printf("----------------------------------------------\n");
    printf("Press any key to return...");
    getch();
    fflush(stdin);
}

void prAboutUs()
{
    printf("\n_____________________________________________\n");
    printf("          +    About Us!!    +\n");
    printf("----------------------------------------------\n");
    printf("   Project RENJU 1.0 Beta version\n");
    printf("Copyright@Ruankosoft www.ruanko.com\n");
    printf("----------------------------------------------\n");
    printf("Press any key to return...");
    getch();
    fflush(stdin);
}
void exitApp()
{
    saveRanks();

    printf("\n          ++++++++++++++++++\n");
    printf("          ++  Game  Over  ++\n");
    printf("          ++++++++++++++++++\n");
}

void prRankList()
{
    const int nMaxSize = getRankSize();
    int nSize = 0;
    int nIndex = 0;

    Rank* psrRanks = NULL;

    printf("\n----------------------------------------------\n");
    printf("          +    RANK LIST    +\n");
    printf("----------------------------------------------\n");
    printf("rank\t name\t Sum of Moves\n");

    psrRanks = (Rank*)malloc(sizeof(Rank) * nMaxSize);

    memset(psrRanks, 0, sizeof(Rank) * nMaxSize);

    nSize = getRanks(psrRanks, nMaxSize);

    for(nIndex = 0; nIndex < nSize; nIndex++)
    {
        Rank* psrRank = &psrRanks[nIndex];
        printf("%d\t%s\t%d\n", nIndex+1, psrRank->name, psrRank->step);
    }

    free(psrRanks);

    printf("----------------------------------------------\n");
    printf("Press any key to return...");
    getch();
    fflush(stdin);
}
