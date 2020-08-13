#ifndef INTERVIEW_SEARCH_ALGOS_H
#define INTERVIEW_SEARCH_ALGOS_H

#include "search.h"

void free_skiplist(skiplist_t *list);

void print_skiplist(const skiplist_t *list);

skiplist_t *create_skiplist(int *array, size_t size);


#endif
