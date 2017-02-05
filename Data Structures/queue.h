//
//  queue.h
//  Data Structures
//
//  Created by Matthew Broton on 1/30/17.
//  Copyright © 2017 Matthew Broton. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    void ** data; // array of items
    int items;
    int max;
    
    int front;
    int back;
}queue;

queue * create_queue();

queue * create_queue2(int maxsize);

int get_size(queue* q);

void * insert(queue * q, void * data);

void resize(queue * q, int newsize);

void * pop(queue * q);

void print_queue(queue * q);

void * read_front(queue * q);

void delete_queue(queue * q);

void * read_index(queue * q,int index);


#endif /* queue_h */
