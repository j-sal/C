#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "rank.h"


Rank asrRanks[10];
int nRankSize = 0;

int judgeOrder(const int nStep)
{
    int nIndex = 0;

    while(nIndex < nRankSize)
    {
        if(asrRanks[nIndex].step > nStep)
        {
            break;
        }
        nIndex++;
    }

    return nIndex + 1;
}

void insertRank(const int nPosition, const Rank srRank)
{
    int nIndex = nRankSize;

    if(nPosition < 9)
    {
        while(nIndex > nPosition)
        {
            asrRanks[nIndex] = asrRanks[nIndex - 1];
            nIndex--;
        }
    }

    asrRanks[nPosition] = srRank;

    if(nRankSize < 10)
    {
        nRankSize++;
    }
}

void saveRanks()
{
    wrRankList(asrRanks, nRankSize);
}

int getRankSize()
{
    return nRankSize;

}

int getRanks(Rank* psrRanks, const int nMaxSize)
{
    int nIndex;

    for(nIndex = 0; nIndex < nRankSize && nIndex < nMaxSize; nIndex++)
    {
        psrRanks[nIndex] = asrRanks[nIndex];
    }

    return nIndex;
}

void initRanks()
{
    nRankSize = rdRankList(asrRanks, 10);
}

void prAddRank(const int nStep)
{
    char acName[64];
    Rank srRank;
    int nOrder = 0;

    nOrder = judgeOrder(nStep);

    if(nOrder <= 10)
    {
        printf("      CONGRATS! YOU WON BY %d STEPS\n", nStep);
        printf("----------------------------------------------\n");
        printf("Please type in your name: ");

        scanf("%s", &acName);
        strcpy(srRank.name, acName);
        srRank.step = nStep;

        insertRank(nOrder -1, srRank);
    }
}
