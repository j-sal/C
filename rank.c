#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global.h"
#include "model.h"

int wrRankList(Rank* psrRanks, const int nSize)
{
    FILE* pfRankList = NULL;
    int nIndex = 0;

    if((pfRankList = fopen("RankList.dat", "wb")) == NULL)/*check if the file can be opened*/
    {
        return FALSE;
    }

    fprintf(pfRankList, "TOTALCOUNT%d RANKLIST\n", nSize);

    for(nIndex =0; nIndex < nSize; nIndex++)
    {
        Rank* psrRank = &psrRanks[nIndex];

        /*to separate words with ##*/
        fprintf(pfRankList, "%s ## %d\n", psrRanks->name, psrRanks->step);
    }
    fclose(pfRankList);

    return TRUE;
}

Rank parseRank(char* pcBuf)
{
    const char* DELIMS = "##";
    char *pcTmp = NULL;
    Rank srRank;

    pcTmp = strtok(pcBuf, DELIMS);
    if(pcTmp != NULL)
    {
        strcpy(srRank.name, pcTmp);
    }

    pcTmp = strtok(NULL, DELIMS);
    if(pcTmp != NULL)
    {
        srRank.step = atoi(pcTmp);
    }

    return srRank;
}
int rdRankList(Rank* psrRanks, const int nMaxSize)
{
    FILE* pfRankList = NULL;
    int nSize = 0;
    int nIndex = 0;
    char acBuf[128];

    if((pfRankList = fopen("RankList.dat", "rb")) == NULL)
    {
        printf("File can not be read\n");
        return 0;
    }

    fscanf(pfRankList, "TOTALCOUNT%d RANKLIST\n", &nSize);

    for(nIndex = 0; nIndex < nSize || !feof(pfRankList);)
    {

        fscanf(pfRankList, "%s\n", &acBuf);
        if(strlen(acBuf) > 0)
        {
            psrRanks[nIndex] = parseRank(acBuf);
            nIndex++;
        }
    }
    fclose(pfRankList);

    return nSize;
}
