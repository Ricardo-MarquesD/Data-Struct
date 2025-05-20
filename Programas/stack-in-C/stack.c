#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *create_stack(Stack *stack, int size){
    if(stack != NULL){
        printf("Error founded in the creation the Stack.");
        return -1;
    }

    stack->value = 0;
    stack->top = NULL;

    return stack;
}

Stack pop(Stack stack){
    
}