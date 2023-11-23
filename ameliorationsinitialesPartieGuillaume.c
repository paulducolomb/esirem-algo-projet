


3.1 //Réalisez la sauvegarde du montant actuellement possédé par le joueur. Lorsque ce montant atteint zéro (ou endessous),
celui-ci est réinitialisé et le joueur est prévenu. Ceci ne peut arriver qu’en fin de partie.

int save_score(int somme, int resultat_partie) // somme = argent du joueur, resultat_partie = gain ou perte de la partie précédente
{
    int game_over = 0;
    somme = somme + resultat_partie;

    if (somme <= 0) 	{
        printf(“\n Crédit insuffisants, partie terminée.”);
        game_over = 1;
    }
    if (somme > 0) 	{
        printf(“\n Votre solde est de : %d €,somme”);

    }
    return(game_over);
}

FONCTION SAVE_SCORE
PARAM ENTIER somme
PARAM ENTIER resultat_partie
DEBUT
        somme ← somme + resultat_partie



SI (somme > 0) AFFICHER ‘VOTRE SOLDE EST DE’ + somme + ‘EUROS’
SINON FAIRE	AFFICHER ‘CREDITS INSUFFISANTS’
game_over ← 1
FIN FAIRE
RENVOYER game_over
FIN







3.2	// idem 2.6 avec gestion des As



int calculer_valeur_main(Main main) {  // avec gestion des As
    int valeur_totale = 0;
    int valeur_carte=0

    while (deck * next = NULL) {// pour l’as c’est particulier, la valeur est de 1 ou 11 suivant la main du joueur
        if (main.cartes[i].valeur==1)&&(valeur_totale <11) {
            valeur_carte = 10;
        }
        else {
            valeur_carte = 1;
        }
        if (main.cartes[i].valeur!=1)	{		// pour les autres cartes
            valeur_carte = main.cartes[i].valeur;


            if (valeur_carte > 10) { //toutes les autres sont à 10 (rois,dames…)
                valeur_carte = 10;
            }
        }

        valeur_totale += valeur_carte;
    }

    return valeur_totale;
}


int calculer_valeur_main(struct joueur joueur) {

    struct deck* courant = joueur.cartes_en_main;
    int valeur_totale = 0;


    while (courant != NULL) {
        if (courant->Card.valeur==1)&&(valeur_totale <11) {
            valeur_carte = 10;
        }
        else {
            valeur_carte = 1;
        }
        if (main.cartes[i].valeur!=1)	{		// pour les autres cartes
            int valeur_carte = courant->Card.valeur;
            if (valeur_carte > 10) {
                valeur_carte = 10;
            }
            valeur_totale += valeur_carte;
            courant = courant->next;
        }
        return valeur_totale;
