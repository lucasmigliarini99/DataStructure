/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "../include/stack.h"
#include "../include/queue.h"

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));

}

float testQueu(){
    printf("////////////////////////////////////////\n");
    printf("///////////////////Test Queu////////////////////\n");
    Queue *q = (Queue *)malloc(sizeof(Queue));
    assert(q != NULL);
    init_queue(q);
    assert(q->data[0] == 0);
    enqueue(q,1);
    assert(q->data[0] == 1);
    enqueue(q,2);
    assert(q->data[1] == 2);
    enqueue(q,3);
    assert(q->data[2] == 3);
    dequeue(q);
    assert(q->data[0] == 2);
    
    assert(is_queue_empty(q) == false);
    assert(front(q)==2);
    
    cleare(q);
    assert(is_queue_empty(q) == true);
     printf("///////////////////END Test Queu////////////////////\n");
}


/*
 * 
 */
int main(int argc, char** argv) {

    testQueu();

    return (EXIT_SUCCESS);
}

