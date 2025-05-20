#ifndef BARCAR_H
#define BARCAR_H

#define SIZE_DECK 52

typedef enum Nipe {
    HEARTH,
    DIAMOND,
    CLUB,
    SPADE
} nipe_t;

typedef struct Card {
    int rank;
    nipe_t nipe;
    struct Card *next;
} card_t;

card_t *create_deck(card_t *card, int size);
void debugPrint(card_t *card, int size);
void shuffle(card_t card[]);

#endif