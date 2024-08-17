#ifndef INSERT_CONTEST_USECASE_H
#define INSERT_CONTEST_USECASE_H

#include "../../types/types.h"
#include "../../structures/hash-map.h"

/**
 * @brief Prepara o no com o concurso e insere na tabela de dispersao.
 *
 * Esta funcao recebe dois parametros,
 * sendo um ponteiro que aponta para a tabela de dispersao e a instancia
 * da struct Concurso.
 *
 * A mesma tem como responsabilidade criar o no da tabela de dispersao que contem o concurso,
 * e posteriormente, adiciona esse concurso na tabela.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 * @param[in] Contest       contest: Instancia da struct Contest.
 * @return                  int: Posicao da tabela de dispersao que o novo concurso foi adicionado.
 */
int insert_contest(HashMap *hash_map, const Contest contest);

#endif