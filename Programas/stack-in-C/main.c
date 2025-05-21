#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char const *argv[]){
    stack_t *pilha = NULL;
    push(&pilha, 12);
    push(&pilha, 1);
    push(&pilha, 20);
    print_stack(pilha, 0);
    pop(&pilha);
    print_stack(pilha, 0);

    return 0;
}
