#ifndef STACK_H
#define STACK_H

#define SIZE_S 100

typedef struct{
    int value;
    Stack *top;
}Stack;

Stack *create_stack(Stack *stack, int size);
Stack pop(Stack stack);
Stack push(Stack stack);
Stack free_stack(Stack *stack, int size);

#endif