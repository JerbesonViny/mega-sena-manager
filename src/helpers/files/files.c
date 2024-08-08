#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "files.h"
#include "../strings/strings.h"

char *create_file_path(char *filename, char *extra_path)
{
    char *path;

    int path_length = get_length_of_concatenated_text(filename, extra_path);
    path = (char *)malloc(path_length);

    sprintf(path, "%s/%s", extra_path, filename);

    return path;
}

Contest line_string_to_contest(char line[1024])
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

    char line[1024];
    fgets(line, 1024, file);

    int quantity = 0;
    Contest *contests = NULL;

    while (fgets(line, 1024, file))
    {
        quantity++;
        Contest contest = line_string_to_contest(line);

        contests = realloc(contests, sizeof(Contest) * quantity);
        contests[quantity - 1] = contest;
    }

    LoadContestsFromFileOutput response = {quantity, contests};

    return response;
}