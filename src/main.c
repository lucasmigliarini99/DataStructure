/**
 * @file main.c
 * @author Julien Peyrol, Lucas Migliarini (peyrol.jul@gmail.com, l.migliarini@eleve.leschartreux.net)
 * @brief Permet de lancer le programme
 * @version 0.1
 * @date 2021-10-16
 * 
 * @copyright Copyright (c) 2021
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
#include "../include/heap.h"


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

    clear_queue(q);
    CU_ASSERT_EQUAL(is_queue_empty(q),true);
    //8 tests
}

void test_heap(void){

    Heap heap;
    init_heap(&heap);
    CU_ASSERT(heap.index == 0);

    push_heap(&heap, 5);
    CU_ASSERT(heap.data[0] == 5);    
    push_heap(&heap, 25.0);
    push_heap(&heap, 18.0);
    push_heap(&heap, 2);
    push_heap(&heap, 8);

    float popedVar = pop_heap(&heap);
    CU_ASSERT(popedVar == 2);
    CU_ASSERT(peek_heap(&heap) == 5 );

    CU_ASSERT(is_heap_empty(&heap) == false);

    CU_ASSERT(replace_heap(&heap, 1) == 5);
    CU_ASSERT(peek_heap(&heap) == 1 );

    clear_heap(&heap);
    CU_ASSERT(heap.index == 0);
    //8 tests
}

void test_stack(void){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init_stack(s);
    CU_ASSERT_EQUAL(is_stack_empty(s), true);
    push_stack(s,1);
    CU_ASSERT_EQUAL(s->data[0], 1);
    push_stack(s,2);
    CU_ASSERT_EQUAL(s->data[1], 2);
    push_stack(s,3);
    CU_ASSERT_EQUAL(s->data[2], 3);
    pop_stack(s);
    CU_ASSERT_EQUAL(s->data[2], 0);
    dump(s);
    CU_ASSERT_EQUAL(s->data[2], 2);
    swap(s);
    CU_ASSERT_EQUAL(s->data[1], 2);
    clear_stack(s);
    CU_ASSERT_EQUAL(is_stack_empty(s),true);
    //8 tests
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
     CU_add_test(suite, "test heap",test_heap);
     CU_add_test(suite, "test heap",test_stack);
     CU_basic_run_tests(); 

    return (EXIT_SUCCESS);
}

