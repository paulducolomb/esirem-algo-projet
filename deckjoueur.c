#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiser_deck(struct deck **sommet) {
    *sommet = NULL; // Initialise le sommet du deck à NULL
    struct deck *precedent = NULL; // Initialise un pointeur precedent à NULL
    for (int coul = Heart; coul <= Spade; coul++) { // Boucle sur les couleurs de Heart à Spade
        for (int val = 1; val <= 13; val++) { // Boucle sur les valeurs de 1 à 13
            struct deck *nouvelleCarte = (struct deck*)malloc(sizeof(struct deck)); // Allouer de la mémoire pour une nouvelle carte
            nouvelleCarte->Card.valeur = val; // Assigne la valeur de la carte
            nouvelleCarte->Card.Couleur = coul; // Assigne la couleur de la carte
            nouvelleCarte->next = NULL; // Initialise le pointeur 'next' de la nouvelle carte à NULL
            if (*sommet == NULL) { // Vérifie si le sommet du deck est vide
                *sommet = nouvelleCarte; // Si oui, la nouvelle carte devient le sommet du deck
            } else {
                precedent->next = nouvelleCarte; // Sinon, la carte précédente pointe vers la nouvelle carte
            }
            precedent = nouvelleCarte; // La nouvelle carte devient la carte précédente pour la prochaine itération
        }
    }
}

// Fonction pour mélanger un deck de cartes
void melanger_deck(struct deck **sommet) {
    int taille = 0; // Initialise taille a 0 pour stocker la taille du deck
    struct deck *courant = *sommet; // Initialise un pointeur courant au sommet du deck
    // Calcule la taille du deck en parcourant tous les éléments du deck
    while (courant != NULL) {
        taille++; // Incrémente la taille à chaque itération
        courant = courant->next; // Déplace le pointeur courant vers l'élément suivant du deck
    }
    // Vérifie si la taille du deck est supérieure à 1 pour effectuer un mélange
    if (taille > 1) {
        srand(time(NULL)); // Initialise le générateur de nombres aléatoires
        // Boucle pour mélanger le deck
        for (int i = 0; i < taille - 1; i++) {
            int j = i + rand() % (taille - i); // Génère un nombre aléatoire 'j' dans la plage des cartes restantes
            // Initialisation de deux pointeurs 'courant_i' et 'courant_j' pour les cartes à échanger
            struct deck *courant_i = *sommet;
            struct deck *courant_j = *sommet;
            // Déplace les pointeurs 'courant_i' et 'courant_j' vers les cartes à échanger
            for (int k = 0; k < i; k++) courant_i = courant_i->next;
            for (int k = 0; k < j; k++) courant_j = courant_j->next;
            // Échange les valeurs des cartes 'courant_i' et 'courant_j'
            struct cartes temp = courant_i->Card;
            courant_i->Card = courant_j->Card;
            courant_j->Card = temp;
        }
    }
}
