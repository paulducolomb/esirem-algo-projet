#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction pour initialiser un deck de cartes
void initialiser_deck(ListeCartes *deck) {
    // Allocation de mémoire pour un tableau de 52 cartes dans le deck
    deck->cartes = malloc(sizeof(Carte) * 52);
    deck->taille = 52; // Taille du deck initialisé à 52 cartes
    int index = 0;
    // Boucles pour assigner chaque valeur de carte (de 1 à 13) à chaque couleur de carte (4 couleurs)
    for (int val = 1; val <= 13; val++) {
        for (int coul = COEUR; coul <= PIQUE; coul++) {
            deck->cartes[index].valeur = val; // Assignation de la valeur de la carte
            deck->cartes[index].couleur = coul; // Assignation de la couleur de la carte
            index++;
        }
    }
}

// Fonction pour mélanger un deck de cartes
void melanger_deck(ListeCartes *deck) {
    srand(time(NULL)); // Initialisation de la graine pour rand()

    // Mélange les cartes dans le deck
    for (size_t i = deck->taille - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);

        // Échange des cartes aux positions i et j dans le deck
        Carte temp = deck->cartes[i];
        deck->cartes[i] = deck->cartes[j];
        deck->cartes[j] = temp;
    }
}

// Fonction principale (exemple d'utilisation)
int main() {
    ListeCartes deck; // Déclaration d'une variable de type ListeCartes pour le deck
    initialiser_deck(&deck); // Initialiser le deck
    melanger_deck(&deck); // Mélanger le deck
    free(deck.cartes); // Libération de la mémoire allouée pour le tableau de cartes du deck
    return 0; // Fin du programme
}
