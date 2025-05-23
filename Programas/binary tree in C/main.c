#include <stdio.h>
#include <stdlib.h>
#include "bintre.h"

int main(int argc, char const *argv[]){
    bin_t data[4]; // Minhas informações bases para formar a pilha
    bin_t *tree = &data[(sizeof(data)/sizeof(bin_t))/2]; // A pilha em si, não inicializada
    int var = 30;

    // Os dados brutos
    data[0].value = 1;
    data[1].value = 4;
    data[2].value = 10;
    data[3].value = 21;
    inibin(data, 4); // Cria a pilha

    // Acessando a pilha    
    printf("Valor do poteiro: %d\n", tree->value);
    printf("Ponteiro esquerdo: %d\n", tree->left);
    printf("Ponteiro direito: %d\n\n", tree->right);

    // Testando a busca binária
    printf("Valor encontrado(certeiro ou aproximado) na busca binária: %d\n\n", binsearch(tree, var));

    return 0;
}
