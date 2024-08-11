#include <stdio.h>
#include <stdlib.h>

#include "../../helpers/helpers.h"
#include "process-load-contests-from-file.h"

void process_load_contests_from_file(HashMap *hash_map)
{
    char file_path[2048] = "";

    printf("Informe o diretorio: ");
    scanf("%s", file_path);

    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        printf("\xE2\x9D\x8C Arquivo nao encontrado.\n");
    }
    else
    {
        printf("\xE2\x9C\x85 Arquivo encontrado!\n");
        LoadContestsFromFileOutput result = load_contests_from_file(file_path);
        Contest *contests = result.contests;

        HashMap new_hash_map = make_hash_map(10);
        for (int i = 0; i < result.quantity; i++)
        {
            int index = insert_in_hash_map(&new_hash_map, contests[i]);
        }

        *hash_map = new_hash_map;

        fclose(file);
    }
};
