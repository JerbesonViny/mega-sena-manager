#ifndef FILES_HELPER_H
#define FILES_HELPER_H

#include "../../types/contest.h"

typedef struct LoadContestsFromFileOutput
{
    int quantity;
    Contest *contests;
} LoadContestsFromFileOutput;

char *create_file_path(char *filename, char *extra_path);
LoadContestsFromFileOutput load_contests_from_file(char *file_path);

#endif