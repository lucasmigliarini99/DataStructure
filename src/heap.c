/**
 * @file heap.c
 * @author Kubilay KAPLAN & Emile METRAL
 * @brief 
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/heap.h"

/**
 * @brief initialise le tas
 * 
 * @param h 
 */
void init_heap(Heap *h){
    h->index = 0;
    
    for (int i = 0; i < HEAP_MAX_SIZE ; i++)
    {
        h->data[i] = 0.0;     
    }
}

/**
 * @brief Vérifie si le tas est vide
 * 
 * @param h 
 * @return true 
 * @return false 
 */
bool is_heap_empty(Heap *h){
    return h->index == 0;
}


/**
 * @brief Get the Parent Index 
 * 
 * @param childIndex 
 * @return int 
 */
int getParentIndex(int childIndex){
    return (childIndex - 1) / 2;
}

/**
 * @brief Get the Left Child Index 
 * 
 * @param parentIndex 
 * @return int 
 */
int getLeftChildIndex(int parentIndex){
    return 2 * parentIndex +1;
}

/**
 * @brief Get the Right Child Index 
 * 
 * @param parentIndex 
 * @return int 
 */
int getRightChildIndex(int parentIndex){
    return 2 * parentIndex + 2;
}

/**
 * @brief Echange deux valeurs dans le tas
 * 
 * @param h Tableau 
 * @param index1 Valeur a echanger
 * @param index2 Valeur a echanger
 */
void swap_heap(Heap *h, int index1, int index2){
    float temp = h->data[index1];
    h->data[index1] = h->data[index2];
    h->data[index2] = temp;
}

/**
 * @brief Reorganise en partant par la fin
 * 
 * @param h 
 */
void heapifyUp(Heap *h){
    int index = h->index - 1;

    while(  getParentIndex(index) >= 0 && h->data[getParentIndex(index)] > h->data[index] ){
        swap_heap(h,getParentIndex(index),index);
        index = getParentIndex(index);
    }
}

/**
 * @brief Reorganise en partant du debut
 * 
 * @param h 
 */
void heapifyDown(Heap *h){
    int index  = 0;

    while (getLeftChildIndex(index) < h->index)
    {
        int smallerChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int leftChildIndex = getLeftChildIndex(index);

        if ( rightChildIndex < h->index && h->data[rightChildIndex] < h->data[leftChildIndex])
        {
            smallerChildIndex = rightChildIndex;
        }

        if (h->data[index] < h->data[smallerChildIndex])
        {
           break;
        }
        else{
            swap_heap(h, index, smallerChildIndex);
        }

        index = smallerChildIndex;
    }
    
}

/**
 * @brief supprime le premier element 
 * 
 * @param h 
 * @return float : element supprimer
 */
float pop_heap(Heap *h){
    float items = 0.0;
    if (is_heap_empty(h))
    {
        printf("Error : heap is empty \n");
    }
    else{
        items = h->data[0];
        // printf(" %d in function %f \n",h->index, items);
        int index = (h->index)-1 ;
        // printf(" %d in function index -1\n",index);
        h->data[0] = h->data[index] ;
        // printf(" %d in function %f \n",h->index, h->data[0]);
        h->index --;
        // printf(" %d in function %f \n",h->index, h->data[0]);
        heapifyDown(h);
    }

    return items; 
}

/**
 * @brief ajoute une valeur
 * 
 * @param h 
 * @param value 
 */
void push_heap(Heap *h, float value){
    int index = h->index;
    h->data[index] = value;
    //printf(" %d in function %f ",h->index, h->data[h->index]);
    h->index++;
    heapifyUp(h);
}

/**
 * @brief supprime la premiere valeur et en ajoute une autre
 * 
 * @param h 
 * @param value 
 * @return float 
 */
float replace_heap(Heap *h, float value){
    float itemsRemoved = pop_heap(h);
    push_heap(h,value);
    return itemsRemoved;
}

/**
 * @brief retourne la premiere valeur 
 * 
 * @param h 
 * @return float 
 */
float peek_heap(Heap *h){
    return  h->data[0] ;
}

/**
 * @brief 
 * 
 * @param h 
 */
void clear_heap(Heap *h){
    init_heap(h);
}