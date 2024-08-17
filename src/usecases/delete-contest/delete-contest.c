#include "delete-contest.h"

int delete_contest(HashMap *hash_map, const int id)
{
    SearchOutput searched = search_in_hash_map(*hash_map, id);

    if (!searched.has_value)
    {
        return 0;
    }

    return delete_element_in_hash_map(hash_map, id);
}