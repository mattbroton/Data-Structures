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


void resize_stack(stack * oldstack, int newsize);


/*
 deletes the stack. does not free the memory of the items placed inside.
 */
void delete_stack(stack * s);

/*
 pushes a new item to the top of the stack
 */
void stack_push(stack * s, void * data);
/*
 Does NOT remove the item.
 @params
    s   - stack to read from
    index - item to get
*/
void * stack_read_index(stack * s , int index);


int stack_get_size(stack * s);

void transfer_stack(stack * oldstack, stack * newstack);


/*
 Removes the top most item from the stack if possible otherwise return NULL.
 @params
    s - stack to read from
*/
void * pop_top(stack * s);



#endif /* stack_h */
