#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers/helpers.h"
#include "structures/hash-map.h"
#include "controllers/controllers.h"

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

void display_features()
{
    printf("--- Opcoes ---\n1 - Inserir concurso\n2 - Buscar concurso\n3 - Remover concurso\n4 - Listar concursos\n5 - Carregar concursos de arquivo\n6 - Apresentar estatisticas\n0 - Sair\n");
}

void process_option(HashMap *hash_map, int option)
{
    // system("clear");
    if (option == 1)
    {
        process_insert_contest(hash_map);
    }
    else if (option == 2)
    {
        process_search_contest(*hash_map);
    }
    else if (option == 3)
    {
        process_delete_contest(hash_map);
    }
    else if (option == 4)
    {
        process_list_contests(*hash_map);
    }
    else if (option == 5)
    {
        process_load_contests_from_file(hash_map);
    }
    else if (option == 0)
    {
        system("clear");
        printf("\xE2\x9C\x85 Sistema encerrado com sucesso!\n");
        exit(0);
    }
    else
    {
        printf("\xE2\x9D\x8C Opcao invalida! Tente novamente\n");
    }
}

int main(void)
{
    char *file_name = "testes.csv";
    char *extra_path = "./data";
    char *file_path = create_file_path(file_name, extra_path);

    LoadContestsFromFileOutput result = load_contests_from_file(file_path);

    Contest *contests = result.contests;
    HashMap hash_map = make_hash_map(10);

    for (int i = 0; i < result.quantity; i++)
    {
        int index = insert_in_hash_map(&hash_map, contests[i]);
    }

    int option = -1;
    // system("clear");

    while (option != 0)
    {
        display_features();
        printf("Escolha uma das opcoes disponiveis: ");
        scanf("%d", &option);
        process_option(&hash_map, option);
        getchar();
    }

    return 0;
}