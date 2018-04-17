#include <ctype.h>
#include <stdlib.h>
#include "global.h"
#include "model.h"

int judgeHorizontal(const Point spPoint);
int judgeVertical(const Point spPoint);
int judgeHyperph(const Point spPoint);
int judgeHypoph(const Point spPoint);

int judgeDraw();

int chessStat[15][15];

void initStat()
{
    int i,j;

    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            chessStat[i][j] = STATUS_BLANK;
        }
    }
}
int getStat(const Point spPoint)
{
    return chessStat[spPoint.row][spPoint.col];
}

void setStat(const Point spPoint)
{
    chessStat[spPoint.row][spPoint.col] = spPoint.status;
}



int judge(const Point spPoint)
{
    int nCount;

    chessStat[spPoint.row][spPoint.col] = spPoint.status;

    /*horizontal diagonal*/

    nCount = judgeHorizontal(spPoint);
    if(nCount >= 5)
    {
        return JUDGE_WIN;
    }

    /*vertical diagonal*/
    nCount = judgeVertical(spPoint);
    if(nCount >= 5)
    {
        return JUDGE_WIN;
    }

    /*positive diagonal (Left bott to right upper)*/
    nCount = judgeHyperph(spPoint);
    if(nCount >= 5)
    {
        return JUDGE_WIN;
    }

    /*opposite diagonal (Left upper to right bott)*/
    nCount = judgeHypoph(spPoint);
    if(nCount >= 5)
    {
        return JUDGE_WIN;
    }

    if(judgeDraw() == TRUE)
    {
        return JUDGE_DRAW;
    }

    return JUDGE_PLAY;
}

int judgeHorizontal(const Point spPoint)
{
    int i, j, counter =1;
    int nRow = spPoint.row;
    int nCol = spPoint.col;
    int STANDARD = spPoint.status;

    j = nCol -1;
    i = nRow;

    while(j >= 0)
    {
        if(chessStat[i][j--] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    j = nCol+1;
    while(j <= 14)
    {
        if(chessStat[i][j++] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    return counter;
}

int judgeVertical(const Point spPoint)
{
    int i, j, counter =1;
    int nRow = spPoint.row;
    int nCol = spPoint.col;
    int STANDARD = spPoint.status;

    j = nCol;
    i = nRow -1;

    while(i >= 0)
    {
        if(chessStat[i--][j] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    i = nRow+1;
    while(j <= 14)
    {
        if(chessStat[i++][j] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    return counter;
}

int judgeHyperph(const Point spPoint)
{
    int i, j, counter =1;
    int nRow = spPoint.row;
    int nCol = spPoint.col;
    int STANDARD = spPoint.status;

    j = nCol + 1;
    i = nRow - 1;

    while(i >= 0 && j <= 14)
    {
        if(chessStat[i--][j++] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    i = nRow+1;
    j = nCol -1;

    while(i <= 14 && j >= 0)
    {
        if(chessStat[i++][j--] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    return counter;
}

int judgeHypoph(const Point spPoint)
{
    int i, j, counter =1;
    int nRow = spPoint.row;
    int nCol = spPoint.col;
    int STANDARD = spPoint.status;

    j = nCol - 1;
    i = nRow - 1;

    while(i >= 0 && j <= 0)
    {
        if(chessStat[i--][j--] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    i = nRow +1;
    j = nCol +1;

    while(i <= 14 && j >= 14)
    {
        if(chessStat[i++][j++] == STANDARD)
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    return counter;
}

int judgeDraw()
{
    int i,j;

    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            if(chessStat[i][j] == STATUS_BLANK)
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}
