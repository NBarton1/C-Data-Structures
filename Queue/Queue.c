//
// Created by nate on 4/17/25.
//


#include <stdlib.h>

#include "Queue.h"
#include "../LinkedList/LinkedList.h"
#include "../util/util.h"

struct Queue_s {
	LinkedList l;
};

Queue q_init() {
	Queue q = safe_malloc(sizeof(struct Queue_s));
	q->l = ll_init();
	return q;
}

void q_free(Queue q) {
	ll_free(q->l);
	free(q);
}

void q_enqueue(Queue q, void *data) {
	ll_insert(q->l, END, data);
}

void *q_dequeue(Queue q) {
	return ll_remove(q->l, 0);
}

void *q_peek(Queue q) {
	return ll_get(q->l, 0);
}
