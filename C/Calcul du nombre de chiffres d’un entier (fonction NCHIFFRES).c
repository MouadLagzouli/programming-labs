#include <stdio.h>

/* Prototype de la fonction */
int NCHIFFRES(long N);

int main() {
    long A;

    printf("Introduire un nombre entier : ");
    scanf("%ld", &A);

    printf("Le nombre %ld contient %d chiffres.\n", A, NCHIFFRES(A));
return 0;
 
}

/* Fonction qui calcule le nombre de chiffres */
int NCHIFFRES(long N) {
    int compteur = 0;

    /* Si le nombre est négatif, on le rend positif */
    if (N < 0)
        N = -N;

    /* Cas particulier : N = 0 */
    if (N == 0)
return 1;
    
    /* Comptage des chiffres */
    while (N > 0) {
        compteur++;
        N /= 10;
    }

    return compteur;
}
