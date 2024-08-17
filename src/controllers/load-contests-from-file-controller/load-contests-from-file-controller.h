#ifndef PROCESS_LOAD_CONTESTS_FROM_FILE_H
#define PROCESS_LOAD_CONTESTS_FROM_FILE_H

#include "../../structures/hash-map.h"

/**
 * @brief Capta o caminho ao qual o arquivo que contem os concursos que precisam serem carregados.
 *
 * Esta funcao recebe somente a tabela de dispersao como parametro.
 *
 * Tem como responsabilidade obter o caminho do arquivo que contem os concursos que vao ser carregados,
 * tentar carregar e tratar os possiveis erros.
 *
 * @param[in] HashMap*      hash_map: Endereco de memoria da tabela de dispersao.
 */
void load_contests_from_file_controller(HashMap *hash_map);

#endif