#include <stdlib.h>
#include <stdio.h>

#include "nodes.h"

Node *make_contest_node(const Contest constest)
{
    Node *node = malloc(sizeof(Node));
    Contest *new_constest = make_constest_copy(constest);

    node->key = constest.id;
    node->value = new_constest;
    node->next = NULL;

    return node;
}