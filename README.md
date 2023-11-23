# esirem-algo-projet

## Algorithme

```
  DEBUT FONCTION initialiser_deck
    PARAM sommet
    VAR sommet = NULL
    VAR precedent = NULL
    POUR chaque coul DE Heart A Spade :
        POUR chaque val DE 1 A 13 :
            nouvelleCarte = allouer mémoire pour une nouvelle carte de type deck
            nouvelleCarte -> Card.valeur = val
            nouvelleCarte -> Card.Couleur = coul
            nouvelleCarte -> next = NULL
            SI sommet == NULL ALORS
                sommet = nouvelleCarte
            SINON
                precedent->next = nouvelleCarte
            precedent = nouvelleCarte
        FIN POUR
    FIN POUR
FIN FONCTION
```

```
DEBUT FONCTION melanger_deck
    PARAM sommet
    VAR taille = 0
    VAR courant = *sommet
    TANT QUE courant != NULL
        taille++
        courant = courant -> next
    FIN TANT QUE
    SI taille > 1 ALORS
        initialiser le générateur de nombres aléatoires
        POUR i DE 0 A taille - 2
            j = i + rand() % (taille - i)
            courant_i = *sommet
            courant_j = *sommet
            POUR k DE 0 A i
                courant_i = courant_i -> next
            FIN POUR
            POUR k DE 0 A j 
                courant_j = courant_j -> next
            FIN POUR
            temp = courant_i -> Card
            courant_i->Card = courant_j->Card
            courant_j->Card = temp
        FIN POUR
    FIN SI
FIN FONCTION
```

```
DEBUT FONCTION handbanque
    PARAM deck 
    PARAM banque 
    PARAM joueur
    initialiser_deck(deck)
    banque->cartes_en_main = NULL
    joueur->cartes_en_main = NULL
FIN FONCTION
```

```
DEBUT FONCTION afficher_main
    PARAM joueur
    VAR courant = joueur.cartes_en_main
    afficher("Main de cartes:\n")
    TANT QUE courant != NULL
        VAR nomCouleur
        VAR nomValeur
        CAS DE courant -> Card.Couleur:
            CAS Heart:   nomCouleur = "Coeur"
            CAS Club:    nomCouleur = "Trefle"
            CAS Diamond: nomCouleur = "Carreau"
            CAS Spade:   nomCouleur = "Pique"
        FIN CAS
        CAS de courant -> Card.valeur:
            CAS 1:  nomValeur = "As"
            CAS 11: nomValeur = "Valet"
            CAS 12: nomValeur = "Dame"
            CAS 13: nomValeur = "Roi"
            DEFAUT: nomValeur = entierEnChaine(courant->Card.valeur)
        FIN CAS
        AFFICHER(" %s de %s\n", nomValeur, nomCouleur)
        courant = courant->next
    FIN TANT QUE
FIN FONCTION
```

```
DEBUT FONCTION distribuer_carte
    PARAM deck
    PARAM joueur
    SI deck != NULL
        carteDistribuee = deck
        deck = deck -> next
        carteDistribuee -> next = joueur -> cartes_en_main
        joueur -> cartes_en_main = carteDistribuee
    SINON
        AFFICHER("Le deck est vide, impossible de distribuer une carte.\n")
    FIN SI
FIN FONCTION
```

```
DEBUT FONCTION traiter_saisie_utilisateur()
    VAR choix
    AFFICHER("Entrez votre choix (0: HIT, 1: STAND, 2: DOUBLE, 3: SURRENDER): \n")
    DEMANDER A USER choix
    TANT QUE choix < 0 OU choix > 3 
        AFFICHER("Choix invalide, reessayez : \n")
        DEMANDER A USER choix
    FIN TANT QUE
    RETURN enum PlayerChoice)choix
FIN FONCTION
```



    
