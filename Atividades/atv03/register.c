#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int registration;
    char person_name[120];
} data;

int verify(int regis) {
    FILE* file = fopen("register.csv", "r");
    if (file == NULL) return 0;

    int matri;
    char text[2000];

    while (fgets(text, sizeof(text), file) != NULL) {
        char* parser = strtok(text, ",");
        if (parser != NULL) {
            matri = atoi(parser);
            if (regis == matri) {
                fclose(file);
                return -1;
            }
        }
    }
    fclose(file);
    return 0;
}

void update(int valor) {
    FILE* file = fopen("register.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE* stream = fopen("newRegister.csv", "w");
    if (stream == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    char text[2000], buffer[120];
    while (fgets(text, sizeof(text), file) != NULL) {
        char* parser = strtok(text, ",");
        int num = atoi(parser);
        char nome[120];

        if (num == valor) {
            printf("Nome do Aluno(a): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(nome, buffer);
        } else {
            char* temp = strtok(NULL, "\n");
            strcpy(nome, temp);
        }

        fprintf(stream, "%d,%s\n", num, nome);
    }

    fclose(file);
    fclose(stream);

    remove("register.csv");
    rename("newRegister.csv", "register.csv");

    printf("Atualização realizada com sucesso.\n");
}

int main(int argc, char* argv[]) {
    FILE* file;
    data d;
    int key;

    while (1) {
        printf("        Registrar Aluno       \n");
        printf("Matricula: ");
        scanf("%d", &d.registration);
        while (getchar() != '\n');

        if (verify(d.registration) != 0) {
            printf("Matricula já registrada, deseja atualizar essa matricula?\n       (sim - 1 | nao - 0):\n");
            scanf("%d", &key);
            while (getchar() != '\n');

            switch (key) {
                case 1:
                    update(d.registration);
                    return 0;
                case 0:
                    return 0;
                default:
                    printf("Comando invalido!\n");
                    continue;
            }
        }

        printf("Nome do Aluno(a): ");
        fgets(d.person_name, sizeof(d.person_name), stdin);

        file = fopen("register.csv", "a");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return -1;
        }

        fprintf(file, "\n%d,%s", d.registration, d.person_name);
        fclose(file);

        printf("\nRegistro feito com sucesso!\n");
        return 0;
    }
}
