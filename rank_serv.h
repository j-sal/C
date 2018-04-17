#ifndef RANK_SERV_H_INCLUDED
#define RANK_SERV_H_INCLUDED

#include "model.h"

int judgeOrder(const int nStep);
void insertRank(const int nPosition, const Rank srRank);
void saveRanks();
int getRankSize();
void initRanks();
int getRanks(Rank* psrRanks, const int nMaxSize);

/*void prAddRank(const int nStep);*/

#endif // RANK_SERV_H_INCLUDED
