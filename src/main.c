#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers/helpers.h"
#include "structures/hash-map.h"
#include "controllers/controllers.h"
#include "usecases/usecases.h"

void display_welcome()
{
    printf("\n========================================================\n          Welcome to the Mega Sena Manager, v1.0\n  Copyright (C) 2024, José Guerra & Jerbeson Rodrigues\n========================================================\n\n");
}

void display_features()
{
    printf("--- Opcoes ---\n1 - Inserir concurso\n2 - Buscar concurso\n3 - Remover concurso\n4 - Listar concursos\n5 - Carregar concursos de arquivo\n6 - Apresentar estatisticas\n0 - Sair\n");
}

void process_option(HashMap *hash_map, int option)
{
    if (option == 1)
    {
        insert_contest_controller(hash_map);
    }
    else if (option == 2)
    {
        search_contest_controller(*hash_map);
    }
    else if (option == 3)
    {
        delete_contest_controller(hash_map);
    }
    else if (option == 4)
    {
        list_contests_controller(*hash_map);
    }
    else if (option == 5)
    {
        load_contests_from_file_controller(hash_map);
    }
    else if (option == 6)
    {
        contest_metrics_controller(*hash_map);
    }
    else if (option == 0)
    {
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
        insert_contest(&hash_map, contests[i]);
    }

    int option = -1;
    // system("clear");

    display_welcome();

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