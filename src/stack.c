/**
 * @file array_list.c
 * @author Julien PEYROL, Lucas MIGLIARINI (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @brief Fonctions afin d'initialiser une pile et de lui ajouter ou enlever des valeurs.
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/stack.h"

/**
 * @brief Initialise la pile
 * 
 * @param s -> nom de la pile
 */

void init_stack(Stack *s)
{
    s->index = -1;
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }
}

/**
 * @brief Insère une valeur en haut de la pile
 * 
 * @param s -> nom de la pile
 * @param value -> valeur à inserer
 */

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

/**
 * @brief Enleve la valeur en haut de la pile
 * 
 * @param s -> nom de la pîle
 * @return float -> valeur enlevée
 */

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

/**
 * @brief Vérifie si la pile est vide
 * 
 * @param s -> nom de la pile
 * @return true -> la pile est vide
 * @return false -> la pile n'est pas vide
 */

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

/**
 * @brief recupère la donnée du dessus sans des-emplier
 * 
 * @param s -> nom de la pile
 * @return float -> valeur récupérée
 */

float peek_stack(Stack *s)
{
    int data;
    if (s->index != -1)
    {
        float data = s->data[s->index];
        printf("La valeur est %.2f.\n", data);
        return data;
    }
    else
    {
        printf("La pile est vide.");
    }
}

/**
 * @brief duplique le sommet de la pile
 * 
 * @param s -> nom de la pile
 */

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

/**
 * @brief échange les deux éléments au sommet
 * 
 * @param s -> nom de la pile
 */

void swap(Stack *s)
{
    float valTemp;
    valTemp = s->data[s->index];
    s->data[s->index] = s->data[s->index - 1];
    s->data[s->index - 1] = valTemp;
    printf("La valeur au sommet est %.2f\n", s->data[s->index]);
    printf("La valeur avant le sommet est %.2f\n", s->data[s->index - 1]);
}

/**
 * @brief Vide la pile
 * 
 * @param s -> nom de la pile
 */

void clear_stack(Stack *s)
{
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0.0;
    }
}
