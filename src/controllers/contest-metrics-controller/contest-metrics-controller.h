#ifndef CONTEST_METRICS_CONTROLLER_H
#define CONTEST_METRICS_CONTROLLER_H

#include <stdio.h>

#include "../../services/contest-metrics/contest-metrics.h"

/**
 * @brief Pega a entrada do usuario que informa qual
 * metrica vai ser apresentada e faz a chamada da funcao que efetua o calculo e exibe a metrica em tela.
 *
 * Esta funcao recebe somente um unico parametro, sendo somente a tabela de dispersao.
 *
 * A mesma pega a entrada do usuario, e baseando-se nessa entrada, chama a funcao
 * que calcula as metricas e posteriormente, exibe-as em tela.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @return                  void
 */
void contest_metrics_controller(const HashMap hash_map);

#endif