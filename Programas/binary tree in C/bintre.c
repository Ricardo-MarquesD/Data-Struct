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
        current = &bin[indexMiddle];
        if(i == indexMiddle){
            continue;
        }
        while(1){
            if(bin[i].value < current->value){
                if(current->left == NULL){
                    current->left = &bin[i];
                    break;
                }else{
                    current = current->left;
                    continue;
                }
            }else if(bin[i].value > current->value){
                if(current->right == NULL){
                    current->right = &bin[i];
                    break;
                }else{
                    current = current->right;
                    continue;
                }
            }else{
                break;
            }
        }
    }
}

int binsearch(bin_t *bin, int target){
    bin_t *current = bin;
    while(1){
        if(target < current->value){
            if(current->left != NULL){
                current = current->left;
                continue;
            }
            break;
        }else if(target > current->value){
            if(current->right != NULL){
                current = current->right;
                continue;
            }
            break;
        }else{
            break;
        }
    }
    return current->value;
}