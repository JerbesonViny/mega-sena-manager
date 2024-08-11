#ifndef HASH_MAP_STRUCTURE_H
#define HASH_MAP_STRUCTURE_H

#include "../types/types.h"

typedef struct Node
{
    int key;
    void *value;
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
    void *value;
} SearchOutput;

HashMap make_hash_map();
int insert_in_hash_map(HashMap *hash_map, Node *new_node, int key);
SearchOutput search_in_hash_map(const HashMap hash_map, int key);
int delete_element_in_hash_map(HashMap *hash_map, const int key);
#endif
