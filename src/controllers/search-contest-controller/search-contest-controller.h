#ifndef SEARCH_CONTEST_CONTROLLER_H
#define SEARCH_CONTEST_CONTROLLER_H

#include "../../structures/hash-map.h"

/**
 * @brief Capta o ID do concurso ao qual o usuario deseja buscar.
 *
 * Esta funcao recebe somente um unico parametro, sendo a tabela de dispersao
 * que contem os concursos armazenados, e que pode ou nao, ter o concurso
 * que o usuario procura.
 *
 * A mesma tem como responsabilidade captar o ID do concurso ao qual se deseja buscar,
 * e posteriormente, fazer a chamada da funcao que busca o concurso na tabela.
 *
 * @param[in] HashMap   hash_map: Tabela de dispersao.
 * @return              void.
 */
void search_contest_controller(const HashMap hash_map);

#endif