#include <string.h>

#include "strings.h"

int get_length_of_concatenated_text(char *first_text, char *second_text)
{
    int first_string_length = strlen(first_text);
    int second_string_length = strlen(second_text);

    return (first_string_length + second_string_length + 1) * sizeof(char);
}