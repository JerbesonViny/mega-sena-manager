#include <stdlib.h>

#include "contest.h"

Contest *make_constest_copy(const Contest constest)
{
    Contest *new_constest = malloc(sizeof(Contest));

    new_constest->id = constest.id;
    new_constest->date = constest.date;
    new_constest->luckyNumbers = constest.luckyNumbers;

    return new_constest;
}