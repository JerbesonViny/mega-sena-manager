#ifndef CONTEST_METRICS_H
#define CONTEST_METRICS_H

#include "../../types/types.h"
#include "../../structures/hash-map.h"

int get_incidence_lucky_number_by_number(const HashMap hash_map, int number);
int get_number_of_contests_in_year(const HashMap hash_map, const int year);
void display_top_ten_lucky_numbers(const HashMap hash_map, SortOrder sort_order);

#endif