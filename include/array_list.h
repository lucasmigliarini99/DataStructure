/**
 * @file array_list.h
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @brief 
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define ARRAY_LIST_MAX_SIZE 100

typedef struct
{
    float data[ARRAY_LIST_MAX_SIZE];
    int index;
} Array_list;

#endif /* ARRAY_LIST_H */

void init_array_list(Array_list *l);
void insert_at(Array_list *l, int position, float value);
void add(Array_list *l, float value);
float remove_at(Array_list *l, int position);
float get_at(Array_list *l, int position);
void clear(Array_list *l);
