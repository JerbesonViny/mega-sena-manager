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
