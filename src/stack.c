/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

void init_stack(Stack *s)
{
    s->index = -1;
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }
}

void push_stack(Stack *s, float value)
{
    if (s->index < STACK_MAX_SIZE)
    {
        s->index += 1;
        s->data[s->index] = value;
        printf("La valeur ajoutée est %.2f.\n", value);
    }
    else
    {
        printf("La pile est pleine.");
    }
}

float pop_stack(Stack *s)
{
    int data;
    if (s->index != -1)
    {
        float data = s->data[s->index];
        printf("La valeur enlevée est %.2f.\n", data);
        s->index -= 1;
        return data;
    }
    else
    {
        printf("La pile est vide.");
    }
}

bool is_stack_empty(Stack *s)
{
    if (s->index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float peek_stack(Stack *s)
{
    int data;
    if (s->index != -1)
    {
        float data = s->data[s->index];
        printf("La valeur enlevée est %.2f.\n", data);
        return data;
    }
    else
    {
        printf("La pile est vide.");
    }
}

void dump(Stack *s)
{
    if (s->index != -1)
    {
        push_stack(s, peek_stack(s));
    }
    else
    {
        printf("La pile est vide.");
    }
}

void swap(Stack *s)
{
    float valTemp;
    valTemp = s->data[s->index];
    s->data[s->index] = s->data[s->index - 1];
    s->data[s->index - 1] = valTemp;
    printf("La valeur au sommet est %.2f\n", s->data[s->index]);
    printf("La valeur avant le sommet est %.2f\n", s->data[s->index - 1]);
}

void clear(Stack *s)
{
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }
}
