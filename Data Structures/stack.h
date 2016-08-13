//
//  stack.h
//  Data Structures
//
//  Created by Matthew Broton on 7/31/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int items;
    int max;
    void ** data;
} stack;

/*
 
 @params
    max -
 
*/
stack * create_stack(int max);


void resize_stack(int newsize);


/*
 Does NOT remove the item.
 @params
    s   - stack to read from
    index - item to get
*/
void * read_index(stack * s , int index);


/*
 Removes the top most item from the stack if possible otherwise return NULL.
 @params
    s - stack to read from
*/
void * get_top(stack * s);



#endif /* stack_h */
