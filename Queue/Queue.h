//
// Created by nate on 4/17/25.
//

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue_s *Queue;

Queue q_init();
void q_free(Queue q);
void q_enqueue(Queue q, void *data);
void *q_dequeue(Queue q);
void *q_peek(Queue q);

#endif //QUEUE_H
