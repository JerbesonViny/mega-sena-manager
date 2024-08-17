#ifndef EXPORT_DATA_CONTROLLER_H
#define EXPORT_DATA_CONTROLLER_H

#include "../../structures/hash-map.h"

/**
 * @brief Capta o nome do arquivo ao qual os concursos serao salvos.
 *
 * Esta funcao recebe somente um unico parametro, sendo somente a tabela de dispersao.
 *
 * A mesma capta o nome do arquivo que vai ser criado com os concursos.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @return                  void
 */
void export_data_controller(const HashMap HashMap);

#endif