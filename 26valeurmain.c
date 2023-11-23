#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculer_valeur_main(struct joueur joueur) {
    int valeur_totale = 0;
    struct deck* courant = joueur.cartes_en_main;
    while (courant != NULL) {
        int valeur_carte = courant->Card.valeur;
        if (valeur_carte > 10) {
            valeur_carte = 10;
        }
        valeur_totale += valeur_carte;
        courant = courant->next;
    }
    return valeur_totale;
}
