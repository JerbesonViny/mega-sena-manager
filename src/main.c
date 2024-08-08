#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers/helpers.h"

int main(void)
{
    char *file_name = "sorteios.csv";
    char *extra_path = "./data";
    char *file_path = create_file_path(file_name, extra_path);

    LoadContestsFromFileOutput result = load_contests_from_file(file_path);

    for (int index = 0; index < result.quantity; index++)
    {
        printf("<(id=%d, date=<(day=%d, month=%d, year=%d)>, luckyNumbers=[%d,%d,%d,%d,%d,%d])>\n",
               result.contests[index].id,
               result.contests[index].date.day,
               result.contests[index].date.month,
               result.contests[index].date.year,
               result.contests[index].luckyNumbers[0],
               result.contests[index].luckyNumbers[1],
               result.contests[index].luckyNumbers[2],
               result.contests[index].luckyNumbers[3],
               result.contests[index].luckyNumbers[4],
               result.contests[index].luckyNumbers[5]);
    }

    free(result.contests);

    return 0;
}