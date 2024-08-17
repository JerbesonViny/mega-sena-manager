#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "load-contests-from-file.h"

/**
 * @brief Converte uma string com os valores do concurso em um concurso.
 *
 * Esta funcao recebe somente uma linha com os valores do concurso.
 *
 * Tem como responsabilidade converter a string com os valores do concurso em um concurso.
 *
 * @param[in] char[2048]        line: String com os valores do concurso.
 * @return                      Contest: Concurso.
 *
 * @note A funcao vai executar com sucesso somente se os valores no arquivo estiverem separados por ",".
 */
Contest line_string_to_contest(char line[2048])
{
    char *token = strtok(line, ",");
    int id = atoi(token);

    token = strtok(NULL, ",");
    char *date = token;

    token = strtok(NULL, ",");
    int firstNumber = atoi(token);

    token = strtok(NULL, ",");
    int secondNumber = atoi(token);

    token = strtok(NULL, ",");
    int thirdNumber = atoi(token);

    token = strtok(NULL, ",");
    int fourthNumber = atoi(token);

    token = strtok(NULL, ",");
    int fifthNumber = atoi(token);

    token = strtok(NULL, ",");
    int sixthNumber = atoi(token);

    char *tk = strtok(date, "-");
    int day = atoi(tk);

    tk = strtok(NULL, "-");
    int month = atoi(tk);

    tk = strtok(NULL, "-");
    int year = atoi(tk);

    int *luckyNumbers = malloc(sizeof(int) * 6);

    luckyNumbers[0] = firstNumber;
    luckyNumbers[1] = secondNumber;
    luckyNumbers[2] = thirdNumber;
    luckyNumbers[3] = fourthNumber;
    luckyNumbers[4] = fifthNumber;
    luckyNumbers[5] = sixthNumber;

    Date dt = {day, month, year};
    Contest contest = {
        id,
        dt,
        luckyNumbers};

    return contest;
}

LoadContestsFromFileOutput load_contests_from_file(char *file_path)
{
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        LoadContestsFromFileOutput response = {-1, NULL};

        return response;
    }

    char line[1024];
    fgets(line, 1024, file);

    int quantity = 0;
    Contest *contests = NULL;

    // enquanto houverem dados, pegar a linha com os valores do arquivo
    while (fgets(line, 1024, file))
    {
        quantity++;
        // converter a linha com os valores do concurso em um concurso
        Contest contest = line_string_to_contest(line);

        contests = realloc(contests, sizeof(Contest) * quantity);
        contests[quantity - 1] = contest;
    }

    LoadContestsFromFileOutput response = {quantity, contests};

    fclose(file);

    return response;
}
