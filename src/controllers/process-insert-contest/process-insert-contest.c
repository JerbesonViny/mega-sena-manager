#include <stdio.h>
#include <stdlib.h>

#include "process-insert-contest.h"

void process_insert_contest(HashMap *hash_map)
{
    int id, day, month, year,
        first_lucky_number,
        second_lucky_number,
        third_lucky_number,
        fourth_lucky_number,
        fifth_lucky_number,
        sixth_lucky_number;

    int keep_receiving_input = 1;

    while (keep_receiving_input)
    {
        printf("Informe o id do concurso que vai ser inserido: ");
        scanf("%d", &id);

        if (search_in_hash_map(*hash_map, id).has_value)
        {
            printf("Existe um concurso com esse ID! Tente novamente!");
            continue;
        }

        printf("Informe o dia do concurso: ");
        scanf("%d", &day);

        printf("Informe o mes do concurso: ");
        scanf("%d", &month);

        printf("Informe o ano do concurso: ");
        scanf("%d", &year);

        printf("Informe o primeiro numero do concurso: ");
        scanf("%d", &first_lucky_number);

        printf("Informe o segundo numero do concurso: ");
        scanf("%d", &second_lucky_number);

        printf("Informe o terceiro numero do concurso: ");
        scanf("%d", &third_lucky_number);

        printf("Informe o quarto numero do concurso: ");
        scanf("%d", &fourth_lucky_number);

        printf("Informe o quinto numero do concurso: ");
        scanf("%d", &fifth_lucky_number);

        printf("Informe o sexto numero do concurso: ");
        scanf("%d", &sixth_lucky_number);

        Date date = {day, month, year};
        int *lucky_numbers = malloc(sizeof(int) * 6);
        lucky_numbers[0] = first_lucky_number;
        lucky_numbers[1] = second_lucky_number;
        lucky_numbers[2] = third_lucky_number;
        lucky_numbers[3] = fourth_lucky_number;
        lucky_numbers[4] = fifth_lucky_number;
        lucky_numbers[5] = sixth_lucky_number;
        Contest contest = {id,
                           date,
                           lucky_numbers};

        int created = insert_in_hash_map(hash_map, contest);

        if (created)
        {
            printf("\xE2\x9C\x85 Concurso inserido com sucesso!\n");
        }
        else
        {
            printf("\xE2\x9D\x8C Nao foi possivel inserir o concurso!\n");
        }

        keep_receiving_input = 0;
    }
};
