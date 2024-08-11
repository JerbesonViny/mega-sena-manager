#include <stdio.h>
#include <stdlib.h>

#include "process-list-contests.h"
#include "../../usecases/list-contests/list-contests.h"

void process_list_contests(const HashMap hash_map)
{
    list_contests(hash_map);
};
