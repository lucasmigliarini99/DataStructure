/**
 * @file queue.h
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX_SIZE 100

typedef struct
{
    float data[QUEUE_MAX_SIZE];
    int index;
} Queue;

#endif /* QUEUE_H */

void init_queue(Queue *s);
void enqueue(Queue *q, float value);
float dequeue(Queue *q);

bool is_queue_empty(Queue *q);
float front(Queue *q);
//void clear(Queue *q);
