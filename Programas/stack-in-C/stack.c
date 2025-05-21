#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stack.h"

void print_stack(stack_t *stack, int size) {
    if(stack == NULL){
        printf("Nothing to print: The stack is empty.\n");
        return;
    }
    int count = 0;
    while (stack != NULL && (size == 0 || count < size)) {
        printf("%d ", stack->value);
        stack = stack->top;
        count++;
    }
    printf("\n");
}

void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node) {
        fprintf(stderr, "Erro de alocação!\n");
        return;
    }
    new_node->value = value;
    new_node->top = *stack;
    *stack = new_node;
}

void pop(stack_t **stack){
    stack_t *remove = *stack;
    *stack = remove->top;
    free(remove);

}