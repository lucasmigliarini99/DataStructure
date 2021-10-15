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
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

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

void testQueu(void){

    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q);
    enqueue(q,1);

    CU_ASSERT_EQUAL(q->data[0], 1);
    enqueue(q,2);
    CU_ASSERT_EQUAL(q->data[1], 2);
    enqueue(q,3);
    CU_ASSERT_EQUAL(q->data[2], 3);
    dequeue(q);
    CU_ASSERT_EQUAL(q->data[0], 2);
    CU_ASSERT_EQUAL(q->data[1], 3);
    CU_ASSERT_EQUAL(is_queue_empty(q), false);
    CU_ASSERT_EQUAL(front(q), 2);

    cleare(q);
    CU_ASSERT_EQUAL(is_queue_empty(q),true);
}

int init(void){

    return 0;
}

int clear_up(void){
    return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    CU_initialize_registry();
     CU_Suite *suite = CU_add_suite("tests",init,clear_up);
     CU_add_test(suite, "test queu",testQueu);
     CU_basic_run_tests(); 

    return (EXIT_SUCCESS);
}

