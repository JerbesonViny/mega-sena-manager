#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers/helpers.h"
#include "structures/hash-map.h"

void display(Contest contest)
{
    printf("<(id=%d, date=<(day=%d, month=%d, year=%d)>, luckyNumbers=[%d,%d,%d,%d,%d,%d])>\n",
           contest.id,
           contest.date.day,
           contest.date.month,
           contest.date.year,
           contest.luckyNumbers[0],
           contest.luckyNumbers[1],
           contest.luckyNumbers[2],
           contest.luckyNumbers[3],
           contest.luckyNumbers[4],
           contest.luckyNumbers[5]);
}

int main(void)
{
    char *file_name = "testes.csv";
    char *extra_path = "./data";
    char *file_path = create_file_path(file_name, extra_path);

    LoadContestsFromFileOutput result = load_contests_from_file(file_path);

    Contest *contests = result.contests;
    HashMap hash_map = make_hash_map(20);

    for (int i = 0; i < result.quantity; i++)
    {
        int index = insert_in_hash_map(&hash_map, contests[i]);
    }

    list_elements_on_hash_map(hash_map);

    return 0;
}