#ifndef LIST_CONTESTS_CONTROLLER_H
#define LIST_CONTESTS_CONTROLLER_H

#include "../../structures/hash-map.h"

/**
 * @brief Exibe todos os concursos da tabela de dispersao.
 *
 * Esta funcao recebe somente um unico parametro, sendo somente a tabela de dispersao.
 *
 * A mesma navega entre todos os nos da tabela, e exibe cada valor que estiver presente.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @return                  void
 */
void list_contests_controller(const HashMap hash_map);

#endif