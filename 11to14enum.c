
enum couleur {Diamond,Club,Heart,Spade} ;

struct cartes
{
    enum couleur Couleur;
    int valeur;
};
struct deck
{
    struct *carte Card;

};
struct joueur
{
    struct deck cartes_en_main;
    int valeur;

};
