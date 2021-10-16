/**
 * @file heap.h
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>

#ifndef HEAP_H
#define HEAP_H

#define HEAP_MAX_SIZE 100

typedef struct
{
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;

#endif /* HEAP_H */

void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float pop(Heap *h); //pop the root value
void push(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek(Heap *h);                 // return root value but dont remove it

//En option
void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
void merge(Heap *dest, Heap *src);                       //merge src into dest
