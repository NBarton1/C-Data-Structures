//
// Created by nate on 4/17/25.
//

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue_s *Queue;

Queue q_init();
void q_free(Queue q);
void enqueue(Queue q, void *data);
void *dequeue(Queue q);
void *peek(Queue q);

#endif //QUEUE_H
