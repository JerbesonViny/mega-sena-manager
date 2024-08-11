#include <stdio.h>
#include <stdlib.h>

#include "process-search-contest.h"

void process_search_contest(const HashMap hash_map)
{
    int id;

    printf("Informe o id do concurso que vai ser buscado: ");
    scanf("%d", &id);

    SearchOutput searched = search_in_hash_map(hash_map, id);

    if (!searched.has_value)
    {
        printf("\xE2\x9D\x8C Concurso nao encontrado!\n");
    }
    else
    {
        printf("\xE2\x9C\x85 Concurso encontrado!\n");

        Contest *contest = (Contest *)searched.value;
        Date date = contest->date;
        int *lucky_numbers = malloc(sizeof(int) * 6);
        lucky_numbers = contest->luckyNumbers;

        printf("| %-25s |", "ID");
        printf("| %-25s |", "Data");
        printf("| %-60s |\n", "Numeros da sorte");

        char row[200];

        sprintf(row, "%d", contest->id);
        printf("| %-25s |", row);
        sprintf(row, "%02d/%02d/%d", date.day, date.month, date.year);
        printf("| %-25s |", row);
        sprintf(row, "%d - %d - %d - %d - %d - %d", lucky_numbers[0], lucky_numbers[1], lucky_numbers[2], lucky_numbers[3], lucky_numbers[4], lucky_numbers[5]);
        printf("| %-60s |\n", row);
    }
};
