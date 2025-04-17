//
// Created by nate on 4/17/25.
//

#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>

int *range(int start, int end);
void pexit(char *msg, int pcode);
void *safe_malloc(size_t bytes);

#endif //UTIL_H
