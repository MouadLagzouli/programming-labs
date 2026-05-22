#include <stdio.h>

void compterRepetitions(int liste[], int n) {
    int valeur, compteur, i;

    printf("Valeur | Répétitions\n");
    printf("-------+------------\n");

    valeur   = liste[0];
    compteur = 1;

    for (i = 1; i < n; i++) {
        if (liste[i] == valeur) {
            compteur++;
        } else {
            printf("  %d    |     %d\n", valeur, compteur);
            valeur   = liste[i];
            compteur = 1;
        }
    }

   
