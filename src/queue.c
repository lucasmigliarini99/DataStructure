/**
 * @file queue.c
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @brief Fonctions afin d'initialiser une file et de lui ajouter ou enlever des valeurs
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/queue.h"

/**
 * @brief initialise une file
 * 
 * @param q -> nom de la file
 */

void init_queue(Queue *q)
{

    for (int i = 0; i < QUEUE_MAX_SIZE; i++)
    {
        q->data[i] = 0.0;
    }
    q->index = 0;
};

/**
 * @brief ajoute une valeur dans la queue
 * 
 * @param q -> nom de la queue
 * @param value -> valeur ajoutée
 */

void enqueue(Queue *q, float value)
{

    if (q != NULL)
    {
        if (q->index < QUEUE_MAX_SIZE)
        {
            q->data[q->index] = value;
            q->index += 1;
        }
    }
};

/**
 * @brief enleve la valeur au début de la file
 * 
 * @param q -> nom de la file
 * @return float -> valeur enlevée
 */

float dequeue(Queue *q)
{
    float dequeu = q->data[0];
    if (q != NULL)
    {
        for (int i = 0; i <= q->index; i++)
        {
            q->data[i] = q->data[i + 1];
        }
        return dequeu;
    }

    return -1;
};

/**
 * @brief vérifie si la file est pleine
 * 
 * @param q -> nom de la file
 * @return true -> la file est vide
 * @return false -> la file n'est pas vide
 */

bool is_queue_empty(Queue *q)
{
    if (q != NULL)
    {
        if (q->index == 0)
        {
            return true;
        }
        return false;
    }
};

/**
 * @brief Retourne la premiere valeur de la file
 * 
 * @param q -> nom de la file
 * @return float -> donne la valeur au début la file
 */

float front(Queue *q)
{
    if (q != NULL)
    {
        return q->data[0];
    }

    return -1;
};

/**
 * @brief vide la file
 * 
 * @param q -> nom de la file
 */

void clear_queue(Queue *q)
{
    init_queue(q);
};
