#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *tab;
    int L, C, i, j;
    FILE *fp;

    //Lecture des dimensions //
    do {
        printf("Donnez les dimensions de la matrice (L C) :\n");
        scanf("%d %d", &L, &C);
    } while (L < 2 || C < 2);

    /* Allocation */
    tab = (double *)malloc(L * C * sizeof(double));
    if (tab == NULL) {
        printf("Erreur ! Pas assez de memoire\n");
        exit(10);
    }

    /* Saisie de la matrice */
    printf("\nLecture de la matrice\n");
    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++) {
            printf("Donnez Tab[%d][%d] : ", i, j);
            scanf("%lf", tab + i * C + j);
        }

    // Affichage //
    printf("\nAffichage de la matrice\n");
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++)
            printf("%10.2lf", *(tab + i * C + j));
        printf("\n");
    }

    /* Ecriture dans le fichier binaire */
    printf("\nOuverture du fichier Mat2D.bin pour ecriture\n");
    fp = fopen("Mat2D.bin", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Le fichier Mat2D.bin n'a pas pu etre ouvert\n");
        free(tab);
        return EXIT_FAILURE;
    }

    printf("\nEcriture des dimensions de la matrice\n");
    if (fwrite(&L, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "Erreur lors de l'ecriture de L\n");
        free(tab);
        fclose(fp);
        return EXIT_FAILURE;
    }

    if (fwrite(&C, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "Erreur lors de l'ecriture de C\n");
        free(tab);
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("Ecriture des elements de la matrice dans Mat2D.bin\n");
    if (fwrite(tab, sizeof(tab[0]), L * C, fp) != (size_t)(L * C)) {
        fprintf(stderr, "Erreur lors de l'ecriture de la matrice\n");
        free(tab);
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("\nFermeture du fichier Mat2D.bin\n");
    if (fclose(fp) == EOF) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier\n");
        free(tab);
        return EXIT_FAILURE;
    }

    free(tab);
    tab = NULL;

    /* Lecture depuis le fichier binaire */
    printf("\nReouverture du fichier Mat2D.bin pour lecture\n");
    fp = fopen("Mat2D.bin", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Le fichier Mat2D.bin n'a pas pu etre ouvert\n");
        return EXIT_FAILURE;
    }

    printf("\nLecture du nombre de lignes\n");
    if (fread(&L, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de L\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    printf("Nombre de lignes : %d\n", L);

    printf("\nLecture du nombre de colonnes\n");
    if (fread(&C, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "Erreur lors de la lecture de C\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    printf("Nombre de colonnes : %d\n", C);

    tab = (double *)malloc(L * C * sizeof(double));
    if (tab == NULL) {
        printf("Erreur ! Pas assez de memoire\n");
        fclose(fp);
        exit(10);
    }

    printf("\nLecture des elements de la matrice depuis Mat2D.bin\n");
    if (fread(tab, sizeof(tab[0]), L * C, fp) != (size_t)(L * C)) {
        fprintf(stderr, "Erreur lors de la lecture de la matrice\n");
        free(tab);
        fclose(fp);
        return EXIT_FAILURE;
    }

    printf("\nFermeture du fichier Mat2D.bin\n");
    if (fclose(fp) == EOF) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier\n");
        free(tab);
        return EXIT_FAILURE;
    }

    /* Affichage de la matrice lue */
    printf("\nAffichage de la matrice lue depuis le fichier\n");
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++)
            printf("%10.2lf", *(tab + i * C + j));
        printf("\n");
    }

    free(tab);
    return 0;
}
