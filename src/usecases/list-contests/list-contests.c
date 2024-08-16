#include <stdio.h>

#include "list-contests.h"

void list_contests(const HashMap hash_map)
{
    printf("| %-10s |", "Index");
    printf("| %-25s |", "ID");
    printf("| %-25s |", "Data");
    printf("| %-60s |\n", "Numeros da sorte");

    Node **table = hash_map.table;

    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            Contest *contest = node->value;
            Date date = contest->date;
            int *luckyNumbers = contest->luckyNumbers;
            char row[200];

            sprintf(row, "%d", index);
            printf("| %-10s |", row);
            sprintf(row, "%d", contest->id);
            printf("| %-25s |", row);
            sprintf(row, "%02d/%02d/%04d", date.day, date.month, date.year);
            printf("| %-25s |", row);
            sprintf(row, "%d - %d - %d - %d - %d - %d", luckyNumbers[0], luckyNumbers[1], luckyNumbers[2], luckyNumbers[3], luckyNumbers[4], luckyNumbers[5]);
            printf("| %-60s |\n", row);

            node = node->next;
        }
    }
}