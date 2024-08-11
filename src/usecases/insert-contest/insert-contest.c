#include <stdio.h>
#include <stdlib.h>

#include "insert-contest.h"
#include "../../helpers/helpers.h"

int insert_contest(HashMap *hash_map, Contest contest)
{
    Node *new_node = make_contest_node(contest);
    return insert_in_hash_map(hash_map, new_node, contest.id);
};