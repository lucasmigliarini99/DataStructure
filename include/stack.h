/**
 * @file stack.h
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net) 
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct
{
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

#endif /* STACK_H */

void init_stack(Stack *s);
void push_stack(Stack *s, float value);
float pop_stack(Stack *s);
bool is_stack_empty(Stack *s);
float peek_stack(Stack *s); // aka top or front
void dump(Stack *s);
void swap(Stack *s);
void clear_stack(Stack *s);
void printStack(Stack *s);
