#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int registration;
    char person_name[120];
}data;

int main(int argc, char const *argv[]){
    FILE* file;
    data d;
    int flag = 1, keyCamp, key, found;
    char text[2000];

    file = fopen("register.csv", "r");
    if(file == NULL){
        printf("Erro inesperado!");
        return -1;
    }

    while(flag){
        printf("Diga a matriculo do aluno: ");
        scanf("%d", &keyCamp);

        rewind(file);
        found = 0;

        fgets(text, sizeof(text), file);

        while(fgets(text, sizeof(text), file) != NULL){
            char* parser = strtok(text, ",");
            d.registration = atoi(parser);
            if (d.registration == keyCamp) {
                char* nome = strtok(NULL, "\n");
                printf("\nResultado da Busca: \nMatricula: %d\nNome do Aluno(a): %s\n\n", d.registration, nome);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Matricula não encontrada!\n");
        }

        printf("Deseja repetir a busca.\n     (sim - 1 | nao - 2)\n");
        scanf("%d", &key);

        switch (key){
        case 1:
            flag = 1;
            break;

        case 2:
            flag = 0;
            break;
        
        default:
            printf("Comando invalido, processo reiniciado!");
            break;
        }
        
    }
    
    fclose(file);

    return 0;
}