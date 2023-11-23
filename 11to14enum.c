#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum couleur {Heart,Club,Diamond,Spade} ;

struct cartes
{
    enum couleur Couleur;
    int valeur;
};
struct deck
{

    struct cartes Card;
    struct deck* next;

};
struct joueur
{
    struct deck* cartes_en_main;
    int valeur;

};
