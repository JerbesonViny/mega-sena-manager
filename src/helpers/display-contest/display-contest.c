#include <stdio.h>

#include "display-contest.h"

void display_contest(Contest *contest)
{
    Date date = contest->date;
    int *luckyNumbers = contest->luckyNumbers;
    char row[200];

    sprintf(row, "%d", contest->id);
    printf("| %-25s |", row);
    sprintf(row, "%02d/%02d/%04d", date.day, date.month, date.year);
    printf("| %-25s |", row);
    sprintf(row, "%d - %d - %d - %d - %d - %d", luckyNumbers[0], luckyNumbers[1], luckyNumbers[2], luckyNumbers[3], luckyNumbers[4], luckyNumbers[5]);
    printf("| %-60s |\n", row);
};