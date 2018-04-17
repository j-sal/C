#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

enum PointStatus
{
    STATUS_BLANK=-1,
    STATUS_BLACK=0,
    STATUS_WHITE=1
};

typedef struct Point
{
    int row;
    int col;
    int status;
}Point;

typedef struct Rank
{
    char name[64];
    int step;
}Rank;

#endif // MODEL_H_INCLUDED
