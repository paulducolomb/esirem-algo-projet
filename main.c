#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum couleur { Heart, Club, Diamond, Spade };

struct cartes {
    enum couleur Couleur;
    int valeur;
};

struct deck {
    struct cartes Card;
    struct deck* next;
};

struct joueur {
    struct deck* cartes_en_main;
    int valeur;
};

enum PlayerChoice {
    HIT,
    STAND,
    DOUBLE,
    SURRENDER
};

void initialiser_deck(struct deck **sommet) {
    *sommet = NULL;
    struct deck *precedent = NULL;
    for (int coul = Heart; coul <= Spade; coul++) {
        for (int val = 1; val <= 13; val++) {
            struct deck *nouvelleCarte = (struct deck*)malloc(sizeof(struct deck));
            nouvelleCarte->Card.valeur = val;
            nouvelleCarte->Card.Couleur = coul;
            nouvelleCarte->next = NULL;
            if (*sommet == NULL) {
                *sommet = nouvelleCarte;
            } else {
                precedent->next = nouvelleCarte;
            }
            precedent = nouvelleCarte;
        }
    }
}

void melanger_deck(struct deck **sommet) {
    int taille = 0;
    struct deck *courant = *sommet;
    while (courant != NULL) {
        taille++;
        courant = courant->next;
    }
    if (taille > 1) {
        srand(time(NULL));
        for (int i = 0; i < taille - 1; i++) {
            int j = i + rand() % (taille - i);
            struct deck *courant_i = *sommet;
            struct deck *courant_j = *sommet;
            for (int k = 0; k < i; k++) courant_i = courant_i->next;
            for (int k = 0; k < j; k++) courant_j = courant_j->next;
            struct cartes temp = courant_i->Card;
            courant_i->Card = courant_j->Card;
            courant_j->Card = temp;
        }
    }
}

void handbanque(struct deck **deck, struct joueur *banque, struct joueur *joueur) {
    initialiser_deck(deck);
    banque->cartes_en_main = NULL;
    joueur->cartes_en_main = NULL;
}
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

enum PlayerChoice traiter_saisie_utilisateur() {
    int choix;
    printf("Entrez votre choix (0: HIT, 1: STAND, 2: DOUBLE, 3: SURRENDER): \n");
    scanf("%d", &choix);
    while (choix < 0 || choix > 3) {
        printf("Choix invalide, reessayez : \n");
        scanf("%d", &choix);
    }
    return (enum PlayerChoice)choix;
}
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

int main(void) {
    struct deck *deck = NULL;
    struct joueur banque, joueur;

    handbanque(&deck, &banque, &joueur);
    melanger_deck(&deck);

    distribuer_carte(&deck, &banque);
    distribuer_carte(&deck, &joueur);
    printf("\nMain de la banque:\n");
    afficher_main(banque);
    int valeur_main_banque = calculer_valeur_main(banque);
    printf("Valeur de la banque : %d\n", valeur_main_banque);
    printf("\nMain du joueur :\n");
    afficher_main(joueur);
    int valeur_main_joueur = calculer_valeur_main(joueur);
    printf("Valeur du joueur : %d\n", valeur_main_joueur);
    enum PlayerChoice choix_joueur = traiter_saisie_utilisateur();
    printf("Le joueur a choisi : %d\n", choix_joueur);

   if (choix_joueur==0){
        afficher_main(joueur);
    }
    if (choix_joueur=1){
        //
    }
    if (choix_joueur=2){
        distribuer_carte(&deck, &joueur);
        afficher_main(joueur);
        calculer_valeur_main(joueur);
        newmise=2*mise;
    }
    // Libération de la mémoire
    while (deck != NULL) {
        struct deck *tmp = deck;
        deck = deck->next;
        free(tmp);
    }

    return 0;
}
