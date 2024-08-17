#include <stdio.h>
#include <stdlib.h>

#include "delete-contest-controller.h"
#include "../../usecases/delete-contest/delete-contest.h"

void delete_contest_controller(HashMap *hash_map)
{
    int id;

    printf("Informe o id do concurso que vai ser buscado: ");
    scanf("%d", &id);

    int deleted = delete_contest(hash_map, id);

    if (!deleted)
    {
        printf("\xE2\x9D\x8C Nao foi possivel apagar o concurso pois ele nao existe!\n");
    }
    else
    {
        printf("\xE2\x9C\x85 Concurso apagado com sucesso!\n");
    }
};
