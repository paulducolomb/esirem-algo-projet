void afficher_main(Main main) {
    printf("Main de cartes:\n");
    for (int i = 0; i < main.nombre_cartes; i++) {
        printf("Carte %d:  %d de %d, \n", i + 1, main.cartes[i].valeur, main.cartes[i].couleur);
    }
}
