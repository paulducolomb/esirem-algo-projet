#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void handbanque(Deck *deck, struct joueur *banque, struct joueur *joueur) {
    initialiser_deck(deck);
    banque->cartes_en_main = NULL;
    joueur->cartes_en_main = NULL;
}


