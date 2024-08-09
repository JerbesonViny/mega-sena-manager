#ifndef HASH_MAP_STRUCTURE_H
#define HASH_MAP_STRUCTURE_H

#include "../types/contest.h"

typedef struct Node
{
    int key;
    Contest value;
    struct Node *next;
} Node;

typedef struct HashMap
{
    int quantity_of_elements;
    int quantity_of_spaces;
    Node **table;
} HashMap;

HashMap make_hash_map();
int insert_in_hash_map(HashMap *hash_map, Contest contest);

#endif
