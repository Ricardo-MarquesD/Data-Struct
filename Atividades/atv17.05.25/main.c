#include <stdio.h>
#include <stdlib.h>
#include "barcar.h"

int main(int argc, char const *argv[]){
    card_t deck[SIZE_DECK];

    create_deck(deck, SIZE_DECK);
    shuffle(deck);
    debugPrint(deck, SIZE_DECK);

    return 0;
}
