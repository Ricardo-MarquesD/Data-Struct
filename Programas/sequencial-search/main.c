#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int vetor[] = {10, 20, 1, 23, 54, 77, 102};
    int target = 21;


    for(int i = 0; i < sizeof(vetor)/sizeof(int); i++){
        if(vetor[i] == target){
            printf("Valor encontrado foi de %d", vetor[i]);
            return 0;
        }
    }
    printf("Valor não encontrado.");
    
    return 0;
}
