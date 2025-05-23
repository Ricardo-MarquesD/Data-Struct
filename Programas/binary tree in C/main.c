#include <stdio.h>
#include <stdlib.h>
#include "bintre.h"

int main(int argc, char const *argv[]){
    bin_t bina[4]; // Minhas informações bases para formar a pilha
    bin_t *root = &bina[(sizeof(bina)/sizeof(bin_t))/2]; // A pilha em si, não inicializada
    int var = 30;

    // Os dados brutos
    bina[0].value = 1;
    bina[1].value = 4;
    bina[2].value = 10;
    bina[3].value = 21;
    inibin(bina, 4); // Cria a pilha

    // Acessando a pilha    
    printf("Valor do poteiro: %d\n", root->value);
    printf("Ponteiro esquerdo: %d\n", root->left);
    printf("Ponteiro direito: %d\n\n", root->right);

    // Testando a busca binária
    printf("Valor encontrado(certeiro ou aproximado) na busca binária: %d\n\n", binsearch(root, var));

    return 0;
}
