#include <stdio.h>
#include <stdlib.h>

#include "../../helpers/helpers.h"
#include "load-contests-from-file-controller.h"
#include "../../usecases/usecases.h"

void load_contests_from_file_controller(HashMap *hash_map)
{
    char file_path[2048] = "";

    printf("Informe o diretorio: ");
    scanf("%s", file_path);

    LoadContestsFromFileOutput result = load_contests_from_file(file_path);

    if (result.quantity == -1)
    {
        printf("\xE2\x9D\x8C Arquivo nao encontrado.\n");
    }
    else
    {
        printf("\xE2\x9C\x85 Arquivo encontrado. ");

        Contest *contests = result.contests;

        HashMap new_hash_map = make_hash_map(10);
        for (int i = 0; i < result.quantity; i++)
        {
            int index = insert_contest(&new_hash_map, contests[i]);
        }

        *hash_map = new_hash_map;

        printf("%d concurso(s) carregado(s)!\n", result.quantity);

        free(result.contests);
    }
};
