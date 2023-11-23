#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficher_main(struct joueur joueur) {
    struct deck* courant = joueur.cartes_en_main;
    while (courant != NULL) {
        const char* nomCouleur;
        switch (courant->Card.Couleur) {
            case Heart:   nomCouleur = "Coeur"; break;
            case Club:    nomCouleur = "Trefle"; break;
            case Diamond: nomCouleur = "Carreau"; break;
            case Spade:   nomCouleur = "Pique"; break;
        }
        const char* nomValeur;
        switch (courant->Card.valeur) {
            case 1:  nomValeur = "As"; break;
            case 11: nomValeur = "Valet"; break;
            case 12: nomValeur = "Dame"; break;
            case 13: nomValeur = "Roi"; break;
            default: nomValeur = (char[3]){ courant->Card.valeur + '0', '\0' }; break;
        }
        printf("%s de %s\n",nomValeur,nomCouleur);
        courant = courant->next;
    }

}
