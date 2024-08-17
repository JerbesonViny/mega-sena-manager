#ifndef INSERT_CONTEST_CONTROLLER_H
#define INSERT_CONTEST_CONTROLLER_H

#include "../../structures/hash-map.h"

/**
 * @brief Capta as entradas do usuario para criar um novo concurso.
 *
 * Esta funcao recebe apenas um unico parametro,
 * sendo somente o endereco de memoria da tabela de dispersao.
 *
 * A mesma tem como responsabilidade captar todos os dados necessarios
 * para criar um concurso. Alem de validar se o id sugerido pelo usuario
 * para identificar o concurso ja nao existe na tabela de dispersao.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 * @return                  void
 */
void insert_contest_controller(HashMap *hash_map);

#endif