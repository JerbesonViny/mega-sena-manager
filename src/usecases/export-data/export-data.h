#ifndef EXPORT_DATA_H
#define EXPORT_DATA_H

#include "../../structures/hash-map.h"

/**
 * @brief Salva os concursos que estao na memoria em um arquivo CSV.
 *
 * Esta funcao recebe dois parametros, a tabela de dispersao e o nome do arquivo que os dados serao exportados.
 *
 * A mesma salva todos os dados da tabela de dispersao em um arquivo CSV.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @param[in] char*         file_name: Nome do arquivo que vai ser criado.
 * @return                  void
 */
int export_data(HashMap hash_map, char *file_name);

#endif