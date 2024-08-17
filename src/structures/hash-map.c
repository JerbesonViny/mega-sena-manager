#include <stdlib.h>
#include <stdio.h>

#include "hash-map.h"

int hash(int value, int quantity_of_spaces)
{
    return quantity_of_spaces != 0 ? value % quantity_of_spaces : 0;
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
            Node *next = node->next;                                 // faz uma copia do proximo valor
            int new_index = hash(node->key, new_quantity_of_spaces); // gera um novo hash para o valor atual
            node->next = new_table[new_index];
            new_table[new_index] = node; // adiciona o valor atual na nova tabela
            node = next;                 // avanca para o proximo valor
        }
    }
}

void resize_table(HashMap *hash_map)
{
    // dobra o tamanho da tabela
    int new_quantity_of_spaces = hash_map->quantity_of_spaces * 2;
    Node **new_table = make_table(new_quantity_of_spaces);

    // copia todos os valores da tabela atual para a nova tabela, reposicionando cada um deles
    copy_values_from_hash_map_to_new_table(hash_map, new_table, new_quantity_of_spaces);

    free(hash_map->table);
    hash_map->table = new_table;
    hash_map->quantity_of_spaces = new_quantity_of_spaces;
}

/**
 * @brief Pega o ultimo no em uma lista encadeada.
 *
 * Esta funcao um parametro,
 * sendo a lista encadeada com seus nos.
 *
 * A mesma tem como responsabilidade retornar o ultimo no de uma lista encadeada.
 *
 * @param[in] Node*         current_node: No atual.
 * @return                  Node*: Ponteiro com o no.
 */
Node *get_last_node(Node *current_node)
{
    Node *value = current_node;

    while (value->next != NULL)
    {
        value = value->next;
    }

    return value;
}

/**
 * @brief Busca em uma lista encadeada por um no que tenha uma chave igual a chave que foi passada.
 *
 * Esta funcao recebe dois parametros,
 * sendo a lista encadeada com seus nos, e uma chave que vai ser usada para buscar um no
 * que tenha uma chave igual.
 *
 * A mesma tem como responsabilidade buscar um no na lista encadeada baseada em uma chave.
 *
 * @param[in] Node*         current_node: No atual.
 * @param[in] int           key: Chave que vai ser utilizada para busca do elemento na tabela.
 * @return                  Node*: Ponteiro com o no
 *
 *
 * @note Se retornar NULL, nao existe um no com essa chave informada.
 */
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
    // verifica se a tabela tem setenta por cento dos espacos preenchidos
    if (hash_map->quantity_of_elements / (float)hash_map->quantity_of_spaces >= 7 / 10.0)
    {
        // reestrutura a tabela, aumentando seu tamanho e movendo os valores criados anteriormente
        resize_table(hash_map);
    }

    int index = hash(key, hash_map->quantity_of_spaces);
    Node *node_filtered_by_key = get_node_by_key(hash_map->table[index], new_node->key);

    // Se nao existir nenhum elemento, nessa posicao, na raiz da tabela de dispersao
    if (hash_map->table[index] == NULL)
    {
        hash_map->quantity_of_elements++;
        hash_map->table[index] = new_node;
    }
    // Se existe um outro elemento com a mesma chave do novo no
    else if (node_filtered_by_key != NULL)
    {
        node_filtered_by_key->value = new_node->value; // substituir o valor anterior pelo novo
    }
    /**
     * Se existe um valor na raiz, nessa posicao, mas nenhum com a mesma chave que o novo no.
     * Adicionar o novo no na ultima posicao da lista duplamente encadeada
     *
     * Encadeamento (chaining)
     * */
    else
    {
        // pega o ultimo no, na tabela de dispersao, nessa posicao
        Node *last_node = get_last_node(hash_map->table[index]);
        last_node->next = malloc(sizeof(Node *));
        new_node->previous = malloc(sizeof(Node *));
        last_node->next = new_node;     // adiciona o novo valor na ultima posicao da lista duplamente encadeada
        new_node->previous = last_node; // faz o novo valor apontar para o anterior
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
        // Caso exista um no com a mesma chave passada pelo usuario
        if (node->key == key)
        {
            // Na raiz da tabela, sem um valor subsequente e precedente
            if (node->next == NULL && node->previous == NULL)
            {
                table[index] = NULL;
                hash_map->quantity_of_elements--;
            }
            // Na raiz da tabela, sem um valor precedente, mas contem um valor subsequente
            else if (node->previous == NULL && node->next != NULL)
            {
                table[index] = node->next;   // move o proximo valor para a raiz da tabela
                node->next->previous = NULL; // modifica o valor movido para que ele aponte para nulo, visto agora ele se encontra na raiz da tabela
                free(node);
            }
            // Ultimo valor da lista encadeada
            else if (node->next == NULL && node->previous != NULL)
            {
                node->previous->next = NULL; // faz o penultimo elemento deixar de apontar para o ultimo
                free(node);
            }
            // Em alguma posicao, exceto as anteriormente testadas
            else
            {
                node->previous->next = node->next;     // faz o valor anterior ao atual apontar para o posterior ao atual
                node->next->previous = node->previous; // faz o valor posterior ao atual apontar para o anterior ao atual
                free(node);
            }

            return 1;
        }

        node = node->next;
    }

    return 0;
}
