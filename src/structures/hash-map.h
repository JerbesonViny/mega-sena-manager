#ifndef HASH_MAP_STRUCTURE_H
#define HASH_MAP_STRUCTURE_H

#include "../types/contest.h"

typedef struct Node
{
    int key;
    Contest *value;
    struct Node *next;
} Node;

typedef struct HashMap
{
    int quantity_of_elements;
    int quantity_of_spaces;
    Node **table;
} HashMap;

typedef struct SearchOutput
{
    int has_value;
    Contest *value;
} SearchOutput;

HashMap make_hash_map();
int insert_in_hash_map(HashMap *hash_map, Contest contest);
SearchOutput search_in_hash_map(const HashMap hash_map, int key);
void list_elements_on_hash_map(const HashMap hash_map);
int delete_element_in_hash_map(HashMap *hash_map, const int key);
#endif
