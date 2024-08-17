#ifndef HASH_MAP_STRUCTURE_H
#define HASH_MAP_STRUCTURE_H

#include "../types/types.h"

typedef struct Node
{
    int key;
    void *value;
    struct Node *next;
    struct Node *previous;
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

HashMap make_hash_map(int quantity_of_spaces);
/**
 * @brief Insere o no com o concurso na tabela de dispersao.
 *
 * Esta funcao recebe tres parametros,
 * sendo um ponteiro que aponta para a tabela de dispersao que vai ser modificada, a instancia
 * de um no contendo o novo Concurso.
 *
 * A mesma tem como responsabilidade adicionar o no da tabela de dispersao que contem o concurso.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 * @param[in] Node*         new_node: Ponteiro com o novo no que vai ser adicionado na tabela.
 * @param[in] int           key: Chave que vai ser utilizada para busca do elemento na tabela.
 * @return                  int: Posicao da tabela de dispersao que o novo concurso foi adicionado.
 */
int insert_in_hash_map(HashMap *hash_map, Node *new_node, int key);
SearchOutput search_in_hash_map(const HashMap hash_map, int key);
int delete_element_in_hash_map(HashMap *hash_map, const int key);
#endif
