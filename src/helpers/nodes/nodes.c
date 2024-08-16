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
    node->previous = NULL;

    return node;
}

Node *make_best_lucky_number_node(const BestLuckyNumber best_lucky_number)
{
    Node *node = malloc(sizeof(Node));
    BestLuckyNumber *value = malloc(sizeof(BestLuckyNumber));
    value->lucky_number = best_lucky_number.lucky_number;
    value->incidence = best_lucky_number.incidence;

    node->key = value->lucky_number;
    node->value = value;
    node->next = NULL;
    node->previous = NULL;

    return node;
};