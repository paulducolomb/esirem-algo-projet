void afficher_main(struct joueur joueur) {
    struct deck* courant = joueur.cartes_en_main;
    printf("Main de cartes:\n");
    while (courant != NULL) {
        printf("Couleur %d, Valeur %d\n", courant->Card.Couleur, courant->Card.valeur);
        courant = courant->next;
    }
}
