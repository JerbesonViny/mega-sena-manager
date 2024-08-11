#include <stdlib.h>
#include <stdio.h>

#include "hash-map.h"

int hash(int value, int quantity_of_elements)
{
    return quantity_of_elements != 0 ? value % quantity_of_elements : 0;
}

Contest *make_constest_copy(const Contest constest)
{
    Contest *new_constest = malloc(sizeof(Contest));

    new_constest->id = constest.id;
    new_constest->date = constest.date;
    new_constest->luckyNumbers = constest.luckyNumbers;

    return new_constest;
}

Node *make_node(const Contest constest)
{
    Node *node = malloc(sizeof(Node));
    Contest *new_constest = make_constest_copy(constest);

    node->key = constest.id;
    node->value = new_constest;
    node->next = NULL;

    return node;
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

int insert_in_hash_map(HashMap *hash_map, Contest contest)
{
    if (hash_map->quantity_of_elements / (float)hash_map->quantity_of_spaces >= 7 / 10.0)
    {
        resize_table(hash_map);
    }

    int index = hash(contest.id, hash_map->quantity_of_spaces);

    if (hash_map->table[index] == NULL)
    {
        hash_map->quantity_of_elements++;
        Node *node = make_node(contest);
        hash_map->table[index] = node;
    }
    else
    {
        Node *new_node = make_node(contest);
        Node *last_node = get_last_node(hash_map->table[index]);
        last_node->next = malloc(sizeof(Node *));
        last_node->next = new_node;
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
    int iterations = 0;
    while (node)
    {
        iterations++;
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

void list_elements_on_hash_map(const HashMap hash_map)
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
            Date date = contest->date;
            int *luckyNumbers = contest->luckyNumbers;
            char row[200];

            sprintf(row, "%d", contest->id);
            printf("| %-25s |", row);
            sprintf(row, "%02d/%02d/%d", date.day, date.month, date.year);
            printf("| %-25s |", row);
            sprintf(row, "%d - %d - %d - %d - %d - %d", luckyNumbers[0], luckyNumbers[1], luckyNumbers[2], luckyNumbers[3], luckyNumbers[4], luckyNumbers[5]);
            printf("| %-60s |\n", row);

            node = node->next;
        }
    }
}

int delete_element_in_hash_map(HashMap *hash_map, const int key)
{
    Node **table = hash_map->table;

    int index = hash(key, hash_map->quantity_of_spaces);

    Node *node = table[index];
    Node *previous = NULL;

    while (node)
    {
        if (node->key == key)
        {
            // Na raiz da tabela
            if (node->next == NULL && previous == NULL)
            {
                table[index] = NULL;
                free(node);
            }
            // Na raiz da tabela, mas contem um proximo valor
            else if (previous == NULL && node->next != NULL)
            {
                table[index] = node->next;
                free(node);
            }
            // Ultimo valor da lista encadeada
            else if (node->next == NULL && previous != NULL)
            {
                previous->next = NULL;
                free(node);
            }
            // Em alguma posicao
            else
            {
                previous->next = node->next;
                free(node);
            }

            return 1;
        }

        previous = node;
        node = node->next;
    }

    return 0;
}
