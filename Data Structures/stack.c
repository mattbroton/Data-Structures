//
//  stack.c
//  Data Structures
//
//  Created by Matthew Broton on 7/31/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include "stack.h"



stack * create_stack(){
    stack * c = malloc(sizeof(stack));
    c->max = 10;
    c->items = 0;
    c->data = malloc(sizeof(void*)*c->max);
    return c;
}

stack * create_stack2(int max){
    if( max <= 0 ){
        return NULL;
    }
    stack * c = malloc(sizeof(stack));
    c->max = max + 1;
    c->items = 0;
    c->data = malloc(sizeof(void*)*c->max);
    return c;
}


void delete_stack(stack * s){
    free(s->data);
    free(s);
}

void resize_stack(stack * oldstack, int newsize){
    if( oldstack != NULL ){
        stack * newstack = create_stack2(newsize);
        transfer_stack(oldstack,newstack);
        
        newstack->max = newsize;
        newstack->items = oldstack->items;
        
        
        
        oldstack->max = newstack->max;
        oldstack->items = newstack->items;
        free(oldstack->data);
        oldstack->data = newstack->data;
        free(newstack);
    }
}

void transfer_stack(stack * oldstack, stack * newstack){
    int c = 0;
    while( c < oldstack->items ){
        stack_push(newstack,stack_read_index(oldstack, c));
        c++;
    }
}

void stack_push(stack * s, void * data){
    if( s == NULL ){
        return;
    }
    if( s->items == s->max ){
        resize_stack(s, s->max * 2 );
    }
    s->data[s->items] = data;
    s->items ++;
}

int stack_get_size(stack * s){
    if( s != NULL ){
        return s->items;
    }
    return 0;
}

void * stack_read_index(stack * s , int index){
    if( s == NULL ){
        return NULL;
    }
    if( s->items <= index ){
        return NULL;
    }
    return s->data[index];
}

void * pop_top(stack * s){
    if( s == NULL ){
        return NULL;
    }
    
    if( s->items >= 1 ){
        s->items -= 1;
        return s->data[s->items];
    }
    
    return NULL;
}