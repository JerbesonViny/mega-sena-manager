#include <stdio.h>
#include <stdlib.h>

#include "process-delete-contest.h"

void process_delete_contest(HashMap *hash_map)
{
    int id;

    printf("Informe o id do concurso que vai ser buscado: ");
    scanf("%d", &id);

    SearchOutput searched = search_in_hash_map(*hash_map, id);

    if (!searched.has_value)
    {
        printf("\xE2\x9D\x8C Nao foi possivel apagar o concurso pois ele nao existe!\n");
    }
    else
    {
        int deleted = delete_element_in_hash_map(hash_map, id);

        printf("\xE2\x9C\x85 Concurso apagado com sucesso!\n");
    }
};
