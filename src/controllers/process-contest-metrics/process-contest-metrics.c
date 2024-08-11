#include <stdio.h>

#include "process-contest-metrics.h"
#include "../../services/contest-metrics/contest-metrics.h"

void display_metrics_options()
{
    printf("--- Metricas ---\n1 - Incidencia de um numero da sorte\n2 - Top 10 numeros mais sorteados\n3 - Top 10 numeros menos sorteados\n4 - Quantidade de concursos em um determinado ano\n");
}

void process_contest_metrics(const HashMap hash_map)
{
    int number, option = -1, keep_receiving_values = 1;

    display_metrics_options();

    while (keep_receiving_values)
    {
        printf("Informe qual metrica voce seja obter: ");
        scanf("%d", &option);

        if (option == 1)
        {

            printf("Informe o numero que voce deseja obter a quantidade de vezes que ele apareceu: ");
            scanf("%d", &number);

            int incidence = get_incidence_lucky_number_by_number(hash_map, number);

            printf("Quantidade de vezes que esse numero foi sorteado: %d\n", incidence);
            keep_receiving_values = 0;
        }
        else
        {
            printf("\xE2\x9D\x8C Opcao invalida! Tente novamente\n");
        }
    }
}
