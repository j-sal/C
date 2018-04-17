#ifndef GAME_SERVICE_H_INCLUDED
#define GAME_SERVICE_H_INCLUDED

#include "model.h"

void initStat();

int getStat(const Point spPoint);

void setStat(const Point spPoint);

int judge(const Point spPoint);

int judgeDraw();

#endif // GAME_SERVICE_H_INCLUDED
