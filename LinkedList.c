//
// Created by nate on 4/17/25.
//

#include "LinkedList.h"

#include <stddef.h>
#include <stdlib.h>

#include "util.h"

typedef struct Node_s {
	void *data;
	struct Node_s *prev;
	struct Node_s *next;
}* Node;

Node node_init(void *data) {
	Node n = safe_malloc(sizeof(struct Node_s));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

struct LinkedList_s {
	Node head;
	Node tail;
	size_t len;
};

LinkedList ll_init() {
	LinkedList l = safe_malloc(sizeof(struct LinkedList_s));
	l->head = NULL;
	l->tail = NULL;
	l->len = 0;
	return l;
}

void ll_free(LinkedList l) {
	Node curr = l->head;
	while (curr != NULL) {
		Node tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(l);
}

void ll_insert(LinkedList l, size_t idx, void *data) {
	if (idx == END)
		idx = l->len;

	if (idx > l->len)
		pexit("ll_insert idx out of bounds", 1);

	Node add = node_init(data);
	if (l->len == 0) {
		l->head = add;
		l->tail = add;
	} else {
		if (idx == 0) {
			add->next = l->head;
			l->head->prev = add;
			l->head = add;
		} else if (idx == l->len) {
			add->prev = l->tail;
			l->tail->next = add;
			l->tail = add;
		} else {
			Node curr;
			for (curr = l->head; idx > 1; idx--)
				curr = curr->next;
			add->next = curr->next;
			add->prev = curr;
			curr->next->prev = add;
			curr->next = add;
		}
	}

	l->len++;
}

Node ll_get_node(LinkedList l, size_t idx) {
	if (idx == END)
		idx = l->len - 1;

	if (idx >= l->len)
		pexit("ll_get_node idx out of bounds", 1);

	if (idx == 0)
		return l->head;

	if (idx == l->len - 1)
		return l->tail;

	Node node;
	for (node = l->head; idx > 0; idx--)
		node = node->next;
	return node;
}

void *ll_get(LinkedList l, size_t idx) {
	return ll_get_node(l, idx)->data;
}

void *ll_remove(LinkedList l, size_t idx) {
	if (idx == END)
		idx = l->len - 1;

	Node removed = ll_get_node(l, idx);
	if (l->len == 1) {
		l->head = NULL;
		l->tail = NULL;
	} else {
		if (idx == 0) {
			l->head = l->head->next;
			l->head->prev = NULL;
		} else if (idx == l->len - 1) {
			l->tail = l->tail->prev;
			l->tail->next = NULL;
		} else {
			removed->prev->next = removed->next;
			removed->next->prev = removed->prev;
		}
	}

	l->len--;
	void *data = removed->data;
	free(removed);

	return data;
}

void ll_for_each(LinkedList l, void (*f)(void *)) {
	for (Node curr = l->head; curr != NULL; curr = curr->next)
		(*f)(curr->data);
}

