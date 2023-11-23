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
    printf("Main de cartes:\n");
    while (courant != NULL) {
        printf("Couleur %d, Valeur %d\n", courant->Card.Couleur, courant->Card.valeur);
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
        printf("Choix invalide, réessayez : \n");
        scanf("%d", &choix);
    }
    return (enum PlayerChoice)choix;
}

int main(void) {
    struct deck *deck = NULL;
    struct joueur banque, joueur;

    handbanque(&deck, &banque, &joueur);
    melanger_deck(&deck);

    distribuer_carte(&deck, &banque);
    distribuer_carte(&deck, &joueur);

    printf("\nMain de la banque apres distribution:\n");
    afficher_main(banque);
    printf("\nMain du joueur apres distribution:\n");
    afficher_main(joueur);

    enum PlayerChoice choix_joueur = traiter_saisie_utilisateur();
    printf("Le joueur a choisi : %d\n", choix_joueur);

    // Ici, vous pouvez ajouter la logique du jeu en fonction du choix du joueur

    // Libération de la mémoire
    while (deck != NULL) {
        struct deck *tmp = deck;
        deck = deck->next;
        free(tmp);
    }

    return 0;
}
