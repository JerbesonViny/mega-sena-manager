#include <stdio.h>

#include "list-contests.h"
#include "../../helpers/display-contest/display-contest.h"

void list_contests(const HashMap hash_map)
{
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

            display_contest(contest);

            node = node->next;
        }
    }
}