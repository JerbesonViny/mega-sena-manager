#include <stdio.h>

#include "export-data-controller.h"
#include "../../usecases/export-data/export-data.h"

void export_data_controller(const HashMap hash_map)
{
    char file_name[200];

    printf("Informe o nome do arquivo que vai ser salvo com os dados (sem a extensao): ");
    scanf("%s", file_name);

    int exported = export_data(hash_map, file_name);

    if (exported)
    {
        printf("\xE2\x9C\x85 Exportacao concluida com sucesso!\n");
    }
    else
    {
        printf("\xE2\x9D\x8C Nao foi possivel exportar os dados!\n");
    }
};