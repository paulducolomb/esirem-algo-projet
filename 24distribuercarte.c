void distribuer_carte(struct deck **deck, struct joueur *joueur) {
    if (*deck != NULL) {
        struct deck *carteDistribuee = *deck;
        *deck = (*deck)->next;
        carteDistribuee->next = joueur->cartes_en_main;
        joueur->cartes_en_main = carteDistribuee;
    } else {
        printf("Le deck est vide, impossible de distribuer une carte.\n");
    }
}
