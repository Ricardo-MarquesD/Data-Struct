#ifndef STACK_H
#define STACK_H

#define SIZE_S 100

typedef struct stack_t{
    int value;
    struct stack_t *top;
}stack_t;

void print_stack(stack_t *stack, int size);
void push(stack_t **stack, int value);
void pop(stack_t **stack);

#endif