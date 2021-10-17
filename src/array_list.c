/**
 * @file array_list.c
 * @author Julien PEYROL, Lucas MIGLIARINI (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @brief Fonctions afin d'initialiser une liste et de lui ajouter ou enlever des valeurs.
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "../include/array_list.h"

/**
 * @brief Initialize la liste
 * 
 * @param l -> nom de liste
 */

void init_array_list(Array_list *l)
{
    l->index = 0;
    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {
        l->data[i] = 0.0;
    }
}

/**
 * @brief Insère une valeur à un endroit donné dans la liste
 * 
 * @param l -> nom de la liste
 * @param position -> position de la liste ou entrer une valeur
 * @param value -> valeur a inserer
 */

void insert_at(Array_list *l, int position, float value)
{
    for (int i = l->index; i > position; i--)
    {
        l->data[i] = l->data[i - 1];
    }
    l->data[position] = value;
    l->index += 1;
}

/**
 * @brief Ajoute une valeur à la fin de la liste
 * 
 * @param l -> nom de la liste
 * @param value -> valeur à inserer
 */

void add(Array_list *l, float value)
{
    l->data[l->index] = value;
    l->index += 1;
}

/**
 * @brief Retire une valeur à un endroit donné
 * 
 * @param l -> nom de la liste
 * @param position -> position à laquelle on veut enlever la valeur
 * @return float -> return la valeur enlevée
 */

float remove_at(Array_list *l, int position)
{
    float value = l->data[position];
    l->data[position] = 0.0;
    for (position + 1; position < ARRAY_LIST_MAX_SIZE; position++)
    {
        l->data[position - 1] = l->data[position];
    }
    l->index -= 1;
}

/**
 * @brief Récupere la valeur à une position voulu
 * 
 * @param l -> nom de la liste
 * @param position -> position à laquelle on veut la valeur
 * @return float -> retourne la valeur à la position demandéel
 */

float get_at(Array_list *l, int position)
{
    float value = l->data[position];
    return value;
}

/**
 * @brief Vide la liste
 * 
 * @param l nom de la liste
 */

void clear_list(Array_list *l)
{
    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {
        l->data[i] = 0.0;
    }
}