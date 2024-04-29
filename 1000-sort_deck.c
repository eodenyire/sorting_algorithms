#include <stdlib.h>
#include "deck.h"

/* Compare function for qsort */
int compare_cards(const void *a, const void *b) {
    const card_t *card1 = (*(const deck_node_t **)a)->card;
    const card_t *card2 = (*(const deck_node_t **)b)->card;

    if (card1->kind != card2->kind)
        return card1->kind - card2->kind;
    else
        return strcmp(card1->value, card2->value);
}

void sort_deck(deck_node_t **deck) {
    deck_node_t *current = *deck;
    deck_node_t **array = malloc(52 * sizeof(deck_node_t *));
    size_t i = 0;

    /* Extract cards into array */
    while (current) {
        array[i++] = current;
        current = current->next;
    }

    /* Sort array of cards */
    qsort(array, 52, sizeof(deck_node_t *), compare_cards);

    /* Update doubly linked list */
    for (i = 0; i < 52; i++) {
        if (i == 0) {
            *deck = array[i];
            array[i]->prev = NULL;
        } else {
            array[i]->prev = array[i - 1];
            array[i - 1]->next = array[i];
        }
    }
    array[51]->next = NULL;

    free(array);
}

