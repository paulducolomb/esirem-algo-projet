void distribuer_carte(Deck *deck, Main *main) {
    if (deck->nombre_cartes > 0) {
        main->cartes[main->nombre_cartes] = deck->cartes[deck->nombre_cartes - 1];
        main->nombre_cartes++;
        deck->nombre_cartes--;
    } else {
        printf("Le deck est vide, impossible de distribuer une carte.\n");
    }
}