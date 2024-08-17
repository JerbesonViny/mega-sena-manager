#ifndef LOAD_CONTESTS_FROM_FILE_USECASE_H
#define LOAD_CONTESTS_FROM_FILE_USECASE_H

#include "../../types/contest.h"

typedef struct LoadContestsFromFileOutput
{
    int quantity;
    Contest *contests;
} LoadContestsFromFileOutput;

/**
 * @brief Capta o caminho ao qual o arquivo que contem os concursos que precisam serem carregados.
 *
 * Esta funcao recebe somente o caminho do arquivo que vai ser carregado como parametro.
 *
 * Tem como responsabilidade tentar carregar os concursos do arquivo.
 *
 * @param[in] char*      file_path: Caminho do arquivo que vai ser carregado.
 * @return               LoadContestsFromFileOutput: Struct com dois campos, um indicando quantos
 * valores foram carregados e o outro com os valores. Caso o arquivo nao tenha sido encontrado, o campo que indica
 * quantos valores foram carregados vai ser igual a -1 e os valores serao iguais a nulo.
 *
 * @note A operacao vai ser considera como bem sucedida se o campo de quantidade nao for igual a -1 e os valores diferentes de nulo.
 */
LoadContestsFromFileOutput load_contests_from_file(char *file_path);

#endif