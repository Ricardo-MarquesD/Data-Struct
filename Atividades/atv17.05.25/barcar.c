#include <stdlib.h>
#include <stdio.h>
#include "barcar.h"

card_t *create_deck(card_t *card, int size){
    if(size != SIZE_DECK){
        perror("Error: Invalid deck size. Expected 52 cards.\n");
        return NULL;
    }
    
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            card[count].rank = j;
            card[count].nipe = i;
            card[count].next = (count < SIZE_DECK-1)? &card[count+1]:NULL;
            count++;
        }
    }
    
    return card;
}

void debugPrint(card_t *card, int size) {
    if(card == NULL){
        perror("Error: The deck has not been initialized yet. Please initialize it before proceeding.\n");
        return;
    }

    char *rank[] = {"As", "1", "2", "3", "4", "5", "6", "7", "8","9", "10", "Valete", "Dama", "Rei"};
    char *nipe[] = {"Copas", "Diamantes", "Paus", "Espadas"};

    card_t *current = card;
    int count = 0;
    while(current != NULL){
        printf("Carta %d : %s de %s\r\n", count + 1, rank[current->rank], nipe[current->nipe]);
        current = current->next;
        count++;
    }
}

void shuffle(card_t card[]){
    for(int i = SIZE_DECK - 1; i > 0; i--){
        int r = rand() % (i + 1);
        card_t temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
    for(int i = 0; i < SIZE_DECK - 1; i++){
        card[i].next = &card[i+1];
    }
    card[SIZE_DECK-1].next = NULL;
}