#ifndef CONTEST_TYPE_H
#define CONTEST_TYPE_H

#include "./date.h"

typedef struct Contest
{
    int id;
    Date date;
    int *luckyNumbers;
} Contest;

#endif