#include <stdio.h>
#include <stdlib.h>

#include "search-contest-controller.h"
#include "../../helpers/display-contest/display-contest.h"

void search_contest_controller(const HashMap hash_map)
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
        printf("| %-25s |", "ID");
        printf("| %-25s |", "Data");
        printf("| %-60s |\n", "Numeros da sorte");

        display_contest(contest);
    }
};
