#include <stdlib.h>
#include <stdio.h>

#include "hash-map.h"

int hash(int value, int quantity_of_elements)
{
    return quantity_of_elements != 0 ? value % quantity_of_elements : 0;
}

Node **make_table(int quantity_of_spaces)
{
    Node **table = malloc(sizeof(Node **) * quantity_of_spaces);

    for (int index = 0; index < quantity_of_spaces; index++)
    {
        table[index] = malloc(sizeof(Node *));
        table[index] = NULL;
    }

    return table;
}

HashMap make_hash_map(int quantity_of_spaces)
{
    HashMap hash_map;

    hash_map.quantity_of_elements = 0;
    hash_map.quantity_of_spaces = quantity_of_spaces;
    hash_map.table = make_table(quantity_of_spaces);

    return hash_map;
}

void copy_values_from_hash_map_to_new_table(HashMap *hash_map, Node **new_table, int new_quantity_of_spaces)
{
    for (int i = 0; i < hash_map->quantity_of_spaces; i++)
    {
        Node *node = hash_map->table[i];

        while (node)
        {
            Node *next = node->next;
            int new_index = hash(node->key, new_quantity_of_spaces);
            node->next = new_table[new_index];
            new_table[new_index] = node;
            node = next;
        }
    }
}

void resize_table(HashMap *hash_map)
{
    int new_quantity_of_spaces = hash_map->quantity_of_spaces * 2;
    Node **new_table = make_table(new_quantity_of_spaces);
    copy_values_from_hash_map_to_new_table(hash_map, new_table, new_quantity_of_spaces);

    free(hash_map->table);
    hash_map->table = new_table;
    hash_map->quantity_of_spaces = new_quantity_of_spaces;
}

Node *get_last_node(Node *current_node)
{
    Node *value = current_node;

    while (value->next != NULL)
    {
        value = value->next;
    }

    return value;
}

Node *get_node_by_key(Node *current_node, int key)
{
    Node *node = current_node;

    while (node != NULL)
    {
        if (node->key == key)
        {
            return node;
        }

        node = node->next;
    }

    return NULL;
}

int insert_in_hash_map(HashMap *hash_map, Node *new_node, int key)
{
    if (hash_map->quantity_of_elements / (float)hash_map->quantity_of_spaces >= 7 / 10.0)
    {
        resize_table(hash_map);
    }

    int index = hash(key, hash_map->quantity_of_spaces);
    Node *node_filtered_by_key = get_node_by_key(hash_map->table[index], new_node->key);

    if (hash_map->table[index] == NULL)
    {
        hash_map->quantity_of_elements++;
        hash_map->table[index] = new_node;
    }
    else if (node_filtered_by_key != NULL)
    {
        node_filtered_by_key->value = new_node->value;
    }
    else
    {
        Node *last_node = get_last_node(hash_map->table[index]);
        last_node->next = malloc(sizeof(Node *));
        new_node->previous = malloc(sizeof(Node *));
        last_node->next = new_node;
        new_node->previous = last_node;
    }

    return index;
}

SearchOutput search_in_hash_map(const HashMap hash_map, int key)
{
    SearchOutput output = {0, NULL};

    int index = hash(key, hash_map.quantity_of_spaces);

    if (hash_map.table[index] == NULL)
    {
        return output;
    }

    Node *node = hash_map.table[index];
    while (node)
    {
        // verificando se a chave do no atual bate com a chave buscada
        if (node->key == key)
        {
            output.has_value = 1;
            output.value = node->value;
            return output;
        }

        node = node->next;
    }

    return output;
}

int delete_element_in_hash_map(HashMap *hash_map, const int key)
{
    Node **table = hash_map->table;

    int index = hash(key, hash_map->quantity_of_spaces);

    Node *node = table[index];

    while (node)
    {
        if (node->key == key)
        {
            // Na raiz da tabela
            if (node->next == NULL && node->previous == NULL)
            {
                table[index] = NULL;
                hash_map->quantity_of_elements--;
            }
            // Na raiz da tabela, mas contem um proximo valor
            else if (node->previous == NULL && node->next != NULL)
            {
                table[index] = node->next;
                node->next->previous = NULL;
                free(node);
            }
            // Ultimo valor da lista encadeada
            else if (node->next == NULL && node->previous != NULL)
            {
                node->previous->next = NULL;
                free(node);
            }
            // Em alguma posicao
            else
            {
                node->previous->next = node->next;
                node->next->previous = node->previous;
                free(node);
            }

            return 1;
        }

        node = node->next;
    }

    return 0;
}
