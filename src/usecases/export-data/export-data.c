#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "export-data.h"
#include "../../helpers/files/files.h"

char *convert_contest_to_string(const Contest contest)
{
    char *row = malloc(sizeof(char) * 400);
    Date date = contest.date;
    int *lucky_numbers = contest.luckyNumbers;

    sprintf(row, "%d,%02d/%02d/%04d,%d,%d,%d,%d,%d,%d\n", contest.id, date.day, date.month, date.year, lucky_numbers[0], lucky_numbers[1], lucky_numbers[2], lucky_numbers[3], lucky_numbers[4], lucky_numbers[5]);

    return row;
};

int export_data(const HashMap hash_map, char *file_name)
{
    char file_with_extension[400];
    sprintf(file_with_extension, "%s.%s", file_name, "csv");

    char *file_path = create_file_path(file_with_extension, "data");
    printf("Filepath: %s\n", file_path);
    FILE *file = fopen(file_path, "w");

    if (file == NULL)
    {
        return 0;
    }

    fprintf(file, "%s", "Concurso,Data,bola_1,bola_2,bola_3,bola_4,bola_5,bola_6\n");

    Node **table = hash_map.table;

    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            Contest *contest = node->value;

            char *row = convert_contest_to_string(*contest);
            fprintf(file, "%s", row);
            free(row);

            node = node->next;
        }
    }

    fclose(file);

    return 1;
};
