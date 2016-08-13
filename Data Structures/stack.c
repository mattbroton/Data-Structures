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



void resize_stack(int newsize){

}

void * read_index(stack * s , int index){
    if( s == NULL ){
        return NULL;
    }
    if( s->items <= index ){
        return NULL;
    }
    return s->data[index];
}

void * get_top(stack * s){
    
    return NULL;
}

int get_size(stack * s){
    if( s == NULL ){
        return 0;
    }
    return s->items;
}
