PlayerChoice traiter_saisie_utilisateur() {
    int choix;
    printf("Entrez votre choix (0: HIT, 1: STAND, 2: DOUBLE, 3: SURRENDER): \n");
    scanf("%d", &choix);

    while (choix < 0 || choix > 3) {
        printf("Choix invalide, Réésayez : \n");
        scanf("%d", &choix);
    }
    return (PlayerChoice)choix;
}
