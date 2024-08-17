#include "sort.h"

#include "../integers/integers.h"

void insertion_sort(LuckyNumberIncidence **numbers, int quantity_of_values, SortOrder sort_order)
{
    if (quantity_of_values <= 1)
    {
        return;
    }

    int (*compare_function)(int, int) = sort_order == DESCENDING ? left_values_is_less_than_right_value : left_values_is_greater_than_right_value;

    for (int current_position = 1; current_position < quantity_of_values; current_position++)
    {
        LuckyNumberIncidence *current_value = numbers[current_position];
        int left_position = current_position - 1;

        while (left_position >= 0 && compare_function(numbers[left_position]->incidence, current_value->incidence))
        {
            numbers[left_position + 1] = numbers[left_position];
            --left_position;
        }

        numbers[left_position + 1] = current_value;
    }
}