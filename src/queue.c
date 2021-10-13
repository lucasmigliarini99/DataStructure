/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void init_queue(Queue *q)
{

    for (int i = 0; i < QUEUE_MAX_SIZE; i++)
    {
        q->data[i] = -1;
    }
    q->index = 0;
};

void enqueue(Queue *q, float value)
{

    if (q != NULL)
    {
        if (q->index < QUEUE_MAX_SIZE)
        {
            q->data[q->index] = value;
            q->index += 1;
            printf("La valeur: %2.f à été ajoutée\n", value);
        }
        else
        {
            printf("La file est pleine");
        }
    }
};

float dequeue(Queue *q)
{
    float dequeu = q->data[0];
    if (q != NULL)
    {
        for (int i = 0; i <= q->index; i++)
        {
            q->data[i] = q->data[i+1];
        }
        return dequeu;
        
    }

    return -1;
};

bool is_queue_empty(Queue *q)
{
    if (q != NULL)
    {
        if (q->index == 0)
        {
            printf("la pile est vide\n");
            return true;
        }
        printf("la pile contient des valeurs\n");
        return false;
    }
};

float front(Queue *q){
    if (q != NULL)
    {
        printf("La première valeur dans la file est: %.2f\n", q->data[0]);
        return q->data[0];
    }

    return -1;
    
};

void clear(Queue *q){
    for (int i = 0; i < QUEUE_MAX_SIZE; i++)
    {
        q->data[i] = -1;
    }
};
