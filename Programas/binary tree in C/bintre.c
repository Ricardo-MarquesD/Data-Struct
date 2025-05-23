#include <stdio.h>
#include <stdlib.h>
#include "bintre.h"

void inibin(bin_t bin[], int size){
    int middle = 0, indexMiddle = 0;
    for(int i = 0; i < size; i++){
        if(i == size/2){
            middle = bin[i].value;
            indexMiddle = i;
        }
        bin[i].left = NULL;
        bin[i].right = NULL;
    }
    bin_t *current = &bin[indexMiddle];
    for(int i = 0; i < size; i++){
        int flag = 1;
        while(flag){
            if(bin[i].value < current->value){
                if(current->left == NULL){
                    current->left = &bin[i];
                    flag = 0;
                }else{
                    current = current->left;
                    continue;
                }
            }else if(bin[i].value > current->value){
                if(current->right == NULL){
                    current->right = &bin[i];
                    flag = 0;
                }else{
                    current = current->right;
                    continue;
                }
            }else{
                flag = 0;
            }
        }
    }
}