//
// Created by nate on 4/17/25.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

#define END (-1lu)

typedef struct LinkedList_s *LinkedList;

LinkedList ll_init();
void ll_free(LinkedList l);
void ll_insert(LinkedList l, size_t idx, void *data);
void *ll_get(LinkedList l, size_t idx);
void *ll_remove(LinkedList l, size_t idx);
void ll_for_each(LinkedList l, void (*f)(void *));

#endif //LINKEDLIST_H
