#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contest-metrics.h"
#include "../../helpers/nodes/nodes.h"
#include "../../helpers/sort/sort.h"

/**
 * @brief Retorna a quantidade de vezes que um numero da sorte apareceu em concursos.
 *
 * Esta funcao recebe somente dois parametros, sendo a tabela de dispersao
 * e o numero da sorte que deseja-se obter a incidencia.
 *
 * A mesma retorna quantas vezes esse numero apareceu em concursos.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @param[in] int           number: Numero da sorte que deseja-se obter a incidencia.
 * @return                  int: Incidencia do numero.
 */
int get_incidence_lucky_number_by_number(const HashMap hash_map, int number)
{
    Node **table = hash_map.table;

    int incidence = 0;
    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            int *lucky_numbers = malloc(sizeof(int) * 6);
            Contest *contest = (Contest *)node->value;
            memcpy(lucky_numbers, contest->luckyNumbers, 6 * sizeof(int));

            for (int lucky_number_index = 0; lucky_number_index < 6; lucky_number_index++)
            {
                if (lucky_numbers[lucky_number_index] == number)
                {
                    incidence++;
                }
            }

            free(lucky_numbers);
            node = node->next;
        }
    }

    return incidence;
};

/**
 * @brief Retorna a quantidade de concursos que foram feitos em um determinado ano.
 *
 * Esta funcao recebe somente dois parametros, sendo a tabela de dispersao
 * e o ano que deseja-se obter a quantidade de concursos feitos no mesmo.
 *
 * A mesma retorna quantos concursos foram feitos em um determinado ano.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @param[in] int           year: Ano que vai ser utilizado para saber quantos concursos foram feitos no ano informado.
 * @return                  int: Quantidade de concursos feitos naquele ano.
 */
int get_number_of_contests_in_year(const HashMap hash_map, const int year)
{
    Node **table = hash_map.table;

    int incidence = 0;
    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            Contest *contest = (Contest *)node->value;
            if (contest->date.year == year)
            {
                incidence++;
            }

            node = node->next;
        }
    }

    return incidence;
};

/**
 * @brief Exibe o top dez numeros da sorte.
 *
 * Esta funcao recebe dois parametros, sendo a tabela de dispersao e a ordem que os numeros vao ser ordenados.
 *
 * A mesma exibe os dez melhores ou piores numeros da sorte.
 *
 * @param[in] HashMap       hash_map: Tabela de dispersao.
 * @param[in] SortOrder     sort_order: Ordem que os numeros devem ser ordenados por incidencia.
 * @return                  void
 */
void display_top_ten_lucky_numbers(const HashMap hash_map, SortOrder sort_order)
{
    HashMap contests_incidence = make_hash_map(10);

    /**
     * Adiciona na tabela de dispersao:
     * key: numero da sorte
     * value: quantidade de vezes que o numero da sorte apareceu
     */
    for (int index = 0; index < hash_map.quantity_of_spaces; index++)
    {
        Node *node = hash_map.table[index];
        while (node != NULL)
        {
            int *lucky_numbers = malloc(sizeof(int) * 6);
            Contest *contest = (Contest *)node->value;
            memcpy(lucky_numbers, contest->luckyNumbers, 6 * sizeof(int));

            for (int lucky_number_index = 0; lucky_number_index < 6; lucky_number_index++)
            {
                SearchOutput output = search_in_hash_map(contests_incidence, lucky_numbers[lucky_number_index]);

                if (output.has_value)
                {
                    LuckyNumberIncidence *value = output.value;
                    value->incidence++;
                }
                else
                {
                    LuckyNumberIncidence lucky_number = {lucky_numbers[lucky_number_index], 1};
                    Node *new_node = make_best_lucky_number_node(lucky_number);
                    insert_in_hash_map(&contests_incidence, new_node, lucky_number.lucky_number);
                }
            }

            node = node->next;
        }
    }

    Node **table = contests_incidence.table;

    int quantity_of_numbers = 0;
    LuckyNumberIncidence **numbers = malloc(sizeof(LuckyNumberIncidence **));

    /**
     * Pega os valores da tabela de dispersao e
     * passa para uma lista de incidencia (numero da sorte e incidencia)
     * */
    for (int index = 0; index < contests_incidence.quantity_of_spaces; index++)
    {
        Node *node = table[index];

        while (node)
        {
            quantity_of_numbers++;
            LuckyNumberIncidence *value = node->value;
            numbers[quantity_of_numbers - 1] = malloc(sizeof(LuckyNumberIncidence));
            numbers[quantity_of_numbers - 1] = value;

            node = node->next;
        }
    }

    // ordena os numeros da sorte em ordem crescente ou decrescente baseando-se na incidencia
    insertion_sort(numbers, quantity_of_numbers, sort_order);

    printf("| %-15s |", "Numero da sorte");
    printf("| %-10s |\n", "Incidencia");

    // limita a quantidade de numeros que vao ser exibidos
    int quantity_of_values_to_display = quantity_of_numbers >= 10 ? 10 : quantity_of_numbers;

    // exibe no terminal os top dez numeros da sorte
    for (int index = 0; index < quantity_of_values_to_display; index++)
    {
        char row[200];

        sprintf(row, "%d", numbers[index]->lucky_number);
        printf("| %-15s |", row);
        sprintf(row, "%d", numbers[index]->incidence);
        printf("| %-10s |\n", row);
    }

    free(numbers);
    free(contests_incidence.table);
};