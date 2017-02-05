//
//  queue.c
//  Data Structures
//
//  Created by Matthew Broton on 1/30/17.
//  Copyright © 2017 Matthew Broton. All rights reserved.
//

#include "queue.h"


queue * create_queue(){
    queue * q = malloc(sizeof(queue));
    q->front = 0;
    q->back = 0;
    q->items = 0;
    q->max = 10;
    q->data = malloc(10*sizeof(void*));
    return q;
}

queue * create_queue2(int maxsize){
    queue * q = malloc(sizeof(queue));
    q->front = 0;
    q->back = 0;
    q->items = 0;
    q->max = maxsize;
    q->data = malloc(maxsize*sizeof(void*));
    return q;
}

int get_size(queue* q){
    if( q != NULL ){
        return q->items;
    }
    return 0;
}


void * insert(queue * q, void * data){
    if( q != NULL ){
        if( q->items == 0 ){
            q->data[q->front] = data;
        }
        else{
            if( q->items == q->max ){
                resize(q, q->max * 2 );
            }
            q->back += 1;
            q->back = (q->back + q->max) % q->max;
            q->data[q->back] = data;
        }
        q->items += 1;
    }
    return NULL;
}

void resize(queue * q, int newsize){
    queue * newqueue = create_queue2(newsize);
    while( get_size(q) > 0){
        void * cdata = pop(q);
        insert(newqueue, cdata);
    }
    //delete_queue(q);
    //q = newqueue;
    free(q->data);
    q->data = newqueue->data;
    q->front = newqueue->front;
    q->back = newqueue->back;
    q->items = newqueue->items;
    q->max = newqueue->max;
    free(newqueue);
}

void * pop(queue * q){
    if( q != NULL ){
        if( q->items > 0 ){
            q->items -= 1;
            void * rdata = q->data[q->front];
            q->front = (q->front + 1 )%q->max;
            if( q->items == 0 ){
                q->front = 0;
                q->back = 0;
            }
            return rdata;
        }
    }
    return NULL;
}

void * read_front(queue * q){
    if( q != NULL ){
        if( q->items > 0 ){
            return q->data[q->front];
        }
    }
    return NULL;
}

void print_queue(queue * q){
    for(int i = 0; i < q->items; i++ ){
        printf("%d ",*((int *)(read_index(q, i))));
    }
    printf("\n");
    /*
    int cpointer = q->front;
    if( q->items == 1 ){
        printf("%d ",*((int *)(q->data[cpointer])));
    }
    else if( q->items > 1){
        while( cpointer != q->back ){
            printf("%d ",*((int *)(q->data[cpointer])));
            cpointer += 1;
            cpointer = (cpointer % q->max) % q->max;
        }
    }
    else{
    }
    printf("\n");
     */
}

void delete_queue(queue * q){
    free(q->data);
    free(q);
}

void * read_index(queue * q, int index){
    if( index < 0 ){
        return NULL;
    }
    if( q != NULL ){
        if( index < q->items){
            int cindex = (q->front + index)%q->max;
            return q->data[cindex];
        }
    }
    return NULL;
}