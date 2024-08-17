#ifndef PROCESS_DELETE_CONTEST_H
#define PROCESS_DELETE_CONTEST_H

#include "../../structures/hash-map.h"

/**
 * @brief Capta o ID do concurso que deve ser apagado.
 *
 * Esta funcao recebe apenas um unico parametro,
 * sendo somente o endereco de memoria da tabela de dispersao.
 *
 * A mesma tem como responsabilidade captar o ID do concurso que vai ser deleteado.
 * A mesma vai exibir uma mensagem em tela caso o elemento seja ou nao deletado.
 *
 * @param[in] HashMap*      hash_map: Ponteiro que aponta para a tabela de dispersao.
 * @return                  void
 */
void delete_contest_controller(HashMap *hash_map);

#endif