#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contest-metrics.h"

int get_incidence_lucky_number_by_number(const HashMap hash_map, int number)
{
    Node **table = hash_map.table;

    int incidence = 0;
    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            int *lucky_numbers = malloc(sizeof(int) * 6);
            memcpy(lucky_numbers, node->value->luckyNumbers, 6 * sizeof(int));

            for (int lucky_number_index = 0; lucky_number_index < 6; lucky_number_index++)
            {
                if (lucky_numbers[lucky_number_index] == number)
                {
                    incidence++;
                }
            }

            free(lucky_numbers);
            node = node->next;
        }
    }

    return incidence;
};
