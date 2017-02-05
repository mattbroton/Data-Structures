//
//  main.c
//  Data Structures
//
//  Created by Matthew Broton on 7/31/16.
//  Copyright © 2016 Matthew Broton. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    int a = 12;
    int b = 6;
    int c = 3;
    int d = 9;
    int e = 7;
    int f = 1232;
    int g = 67;
    int h = 9088;
    
    
    stack * mys = create_stack(5);

    stack_push(mys, &a);
    printf("%d\n",*(int*)stack_read_index(mys, 0));
    
    stack_push(mys, &b);
    printf("%d ",*(int*)stack_read_index(mys, 0));
    printf("%d\n",*(int*)stack_read_index(mys, 1));
    
    
    stack_push(mys, &c);
    printf("%d ",*(int*)stack_read_index(mys, 0));
    printf("%d ",*(int*)stack_read_index(mys, 1));
    printf("%d\n",*(int*)stack_read_index(mys, 2));
    
    stack_push(mys, &d);
    printf("%d ",*(int*)stack_read_index(mys, 0));
    printf("%d ",*(int*)stack_read_index(mys, 1));
    printf("%d ",*(int*)stack_read_index(mys, 2));
    printf("%d\n",*(int*)stack_read_index(mys, 3));
    
    
    stack_push(mys, &e);
    printf("%d ",*(int*)stack_read_index(mys, 0));
    printf("%d ",*(int*)stack_read_index(mys, 1));
    printf("%d ",*(int*)stack_read_index(mys, 2));
    printf("%d ",*(int*)stack_read_index(mys, 3));
    printf("%d\n",*(int*)stack_read_index(mys, 4));
    
    
    
    stack_push(mys, &f);
    printf("%d ",*(int*)stack_read_index(mys, 0));
    printf("%d ",*(int*)stack_read_index(mys, 1));
    printf("%d ",*(int*)stack_read_index(mys, 2));
    printf("%d ",*(int*)stack_read_index(mys, 3));
    printf("%d ",*(int*)stack_read_index(mys, 4));
    printf("%d\n",*(int*)stack_read_index(mys, 5));
    
    
    
    
    queue * myq = create_queue2(5);
    
    
    insert(myq, (void*)&a);
    print_queue(myq);
    
    
    insert(myq, (void*)&b);
    print_queue(myq);
    
    
    insert(myq, (void*)&c);
    print_queue(myq);
    
    insert(myq, (void*)&d);
    print_queue(myq);
    
    insert(myq, (void*)&e);
    print_queue(myq);
    
    
    insert(myq, (void*)&f);
    print_queue(myq);
    
    insert(myq, (void*)&g);
    print_queue(myq);
    
    insert(myq, (void*)&h);
    print_queue(myq);
    
    
    return 0;
}
