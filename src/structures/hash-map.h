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
    int quantity_of_elements; /**< Quantidade de elementos na raiz da tabela de dispersao. */
    int quantity_of_spaces;   /**< Quantidade de espacos da tabela de dispersao. */
    Node **table;
} HashMap;

typedef struct SearchOutput
{
    int has_value;
    void *value;
} SearchOutput;

HashMap make_hash_map(int quantity_of_spaces);
/**
 * @brief Insere o no com o novo valor na tabela de dispersao.
 *
 * Esta funcao recebe tres parametros,
 * sendo um ponteiro que aponta para a tabela de dispersao que vai ser modificada, a instancia
 * de um no contendo o novo valor.
 *
 * A mesma tem como responsabilidade adicionar o no da tabela de dispersao que contem o novo valor.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 * @param[in] Node*         new_node: Ponteiro com o novo no que vai ser adicionado na tabela.
 * @param[in] int           key: Chave que vai ser utilizada para busca do elemento na tabela.
 * @return                  int: Posicao da tabela de dispersao que o novo valor foi adicionado.
 */
int insert_in_hash_map(HashMap *hash_map, Node *new_node, int key);
/**
 * @brief Busca valores na tabela de dispersao baseadas em uma chave.
 *
 * Esta funcao recebe dois parametros,
 * sendo a tabela de dispersao que contem valores, e uma chave que vai ser usada para buscar o valor
 * solicitado pelo usuario.
 *
 * A mesma tem como responsabilidade buscar valores na tabela de dispersao baseada em uma chave.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @param[in] int           key: Chave que vai ser utilizada para busca do elemento na tabela.
 * @return                  SearchOutput: Struct que contem dois valores, um informando se o
 * valor foi encontrado e o outro com um ponteiro que contem o valor.
 */
SearchOutput search_in_hash_map(const HashMap hash_map, int key);
/**
 * @brief Deleta valor na tabela de dispersao baseado em uma chave.
 *
 * Esta funcao recebe dois parametros,
 * sendo a tabela de dispersao que contem valores, e uma chave que vai ser usada para apagar o valor
 * que tiver uma chave igual.
 *
 * A mesma tem como responsabilidade deletar um valor na tabela de dispersao baseada em uma chave.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 * @param[in] int           key: Chave que vai ser utilizada para busca do elemento na tabela.
 * @return                  int: Indica se o elemento foi apagado ou nao.
 *
 *
 * @note Se retornar 0, nenhum elemento foi apagado, caso retornar 1, um elemento foi apagado.
 */
int delete_element_in_hash_map(HashMap *hash_map, const int key);
#endif
