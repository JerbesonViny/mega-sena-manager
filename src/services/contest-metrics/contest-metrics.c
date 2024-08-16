#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contest-metrics.h"
#include "../../helpers/nodes/nodes.h"
#include "../../helpers/sort/sort.h"

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
            Contest *contest = (Contest *)node->value;
            memcpy(lucky_numbers, contest->luckyNumbers, 6 * sizeof(int));

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

int get_number_of_contests_in_year(const HashMap hash_map, const int year)
{
    Node **table = hash_map.table;

    int incidence = 0;
    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            Contest *contest = (Contest *)node->value;
            if (contest->date.year == year)
            {
                incidence++;
            }

            node = node->next;
        }
    }

    return incidence;
};

void display_top_ten_lucky_numbers(const HashMap hash_map, SortOrder sort_order)
{
    HashMap contests_incidence = make_hash_map(10);

    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = hash_map.table[index];
        while (node != NULL)
        {
            int *lucky_numbers = malloc(sizeof(int) * 6);
            Contest *contest = (Contest *)node->value;
            memcpy(lucky_numbers, contest->luckyNumbers, 6 * sizeof(int));

            for (int lucky_number_index = 0; lucky_number_index < 6; lucky_number_index++)
            {
                SearchOutput output = search_in_hash_map(contests_incidence, lucky_numbers[lucky_number_index]);

                if (output.has_value)
                {
                    BestLuckyNumber *value = output.value;
                    value->incidence++;
                }
                else
                {
                    BestLuckyNumber lucky_number = {lucky_numbers[lucky_number_index], 1};
                    Node *new_node = make_best_lucky_number_node(lucky_number);
                    insert_in_hash_map(&contests_incidence, new_node, lucky_number.lucky_number);
                }
            }

            node = node->next;
        }
    }

    Node **table = contests_incidence.table;

    int quantity_of_numbers = 0;
    BestLuckyNumber **numbers = malloc(sizeof(BestLuckyNumber **));

    for (int index = 0; index < contests_incidence.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            quantity_of_numbers++;
            BestLuckyNumber *value = node->value;
            numbers[quantity_of_numbers - 1] = malloc(sizeof(BestLuckyNumber));
            numbers[quantity_of_numbers - 1] = value;

            node = node->next;
        }
    }

    insertion_sort(numbers, quantity_of_numbers, sort_order);

    printf("| %-15s |", "Numero da sorte");
    printf("| %-10s |\n", "Incidencia");

    int quantity_of_values_to_display = quantity_of_numbers >= 10 ? 10 : quantity_of_numbers;
    for (int index = 0; index < quantity_of_values_to_display; index++)
    {
        char row[200];

        sprintf(row, "%d", numbers[index]->lucky_number);
        printf("| %-15s |", row);
        sprintf(row, "%d", numbers[index]->incidence);
        printf("| %-10s |\n", row);
    }

    free(numbers);
    free(contests_incidence.table);
};