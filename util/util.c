//
// Created by nate on 4/17/25.
//

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

int *range(int start, int end) {
	int *arr = safe_malloc((end-start) * sizeof(int));
	for (int i=start; i<end; i++)
		arr[i-start] = i;
	return arr;
}

void pexit(char *msg, int pcode) {
	printf("%s\n", msg);
	exit(pcode);
}

void *safe_malloc(size_t bytes) {
	void *p = malloc(bytes);
	if (!p)
		pexit("could not malloc", 1);
	return p;
}
