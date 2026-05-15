#include <stdio.h>
#include <stdlib.h>

void SaisirComptes(int *tabCpt, float *tabSoldes, int N);
void AffichComptes(int *tabCpt, float *tabSoldes, int N);
int  Rechercher(int *tabCpt, int num, int N );
void Ajouter(int num, float s, int *tabCpt,  float *tabSoldes, int *N, int MAX);
void Deposer(float montant, int num, float *tabSoldes, int *tabCpt, int N);
void Retirer(float montant,int num, float *tabSoldes,  int *tabCpt, int N);

int main() {
    int *tabCpt;
    float *tabSoldes;
int N ;    
    const int MAX = 50;

    /* Saisie de N */
    do {
        printf("Entrer la dimension du tableau N (1..%d) : ", MAX);
        scanf("%d", &N);
    } while (N <= 0 || N > MAX);

    /* Allocation dynamique */
    tabCp  t = (int *)malloc(N * sizeof(int));
    tabSoldes = (float *)malloc(N * sizeof(float));

    if (tabCpt == NULL || tabSoldes == NULL) {
        printf("Erreur d'allocation memoire.\n");
        exit(-1);
    }

    /* Saisie + Affichage */
    SaisirComptes(tabCpt, tabSoldes, N);
    printf("\n--- Affichage initial ---\n");
    AffichComptes(tabCpt, tabSoldes, N);

    
    free(tabCpt);
    free(tabSoldes);

    tabCpt = (int *)malloc(MAX * sizeof(int));
    tabSoldes = (float *)malloc(MAX * sizeof(float));
    if (tabCpt == NULL || tabSoldes == NULL) {
        printf("Erreur d'allocation memoire.\n");
        exit(-1);
    }

    /* Re-saisie après allocation MAX (taille actuelle = N) */
    SaisirComptes(tabCpt, tabSoldes, N);
    printf("\n--- Affichage initial (allocation MAX) ---\n");
    AffichComptes(tabCpt, tabSoldes, N);

    /* Ajout */
    Ajouter(19, 600000.00f, tabCpt, tabSoldes, &N, MAX);
    printf("\nAffichage apres ajout de l'element\n");
    AffichComptes(tabCpt, tabSoldes, N);

    /* Depot */
    printf("\nDeposer un montant de 10000 pour le compte 13\n");
    Deposer(10000.00f, 13, tabSoldes, tabCpt, N);
    printf("Affichage apres le depot\n");
    AffichComptes(tabCpt, tabSoldes, N);

    /* Retrait */
    printf("\nRetirer un montant de 1000 pour le compte 14\n");
    Retirer(1000.00f, 14, tabSoldes, tabCpt, N);
    printf("Affichage apres le retrait\n");
    AffichComptes(tabCpt, tabSoldes, N);

    /* Libération mémoire */
    free(tabCpt);
    free(tabSoldes);

    return 0;
}

/*-----------------------------------------------------------
  SaisirComptes : saisie N comptes + soldes
-----------------------------------------------------------*/
void SaisirComptes(int *tabCpt, float *tabSoldes, int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Entrer le numero du compte tabCpt[%d] et le solde tabSoldes[%d] : ", i, i);
        scanf("%d %f", (tabCpt + i), (tabSoldes + i));
    }
}

/*-----------------------------------------------------------
  AffichComptes : affichage des comptes
-----------------------------------------------------------*/
void AffichComptes(int *tabCpt, float *tabSoldes, int N) {
    int i;
    for (i = 0; i < N; i++) {
        printf("Num de compte : %d, Solde : %.2f\n", *(tabCpt + i), *(tabSoldes + i));
    }
}

/*-----------------------------------------------------------
  Rechercher : retourne l'indice du compte num, sinon -1
-----------------------------------------------------------*/
int Rechercher(int *tabCpt, int num, int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (*(tabCpt + i) == num) {
            return i;
        }
    }
    return -1;
}

/*-----------------------------------------------------------
  Ajouter : ajoute (num, solde) si N < MAX
-----------------------------------------------------------*/
void Ajouter(int num, float s, int *tabCpt, float *tabSoldes, int *N, int MAX) {
    if (*N >= MAX) {
        printf("Impossible d'ajouter : tableau plein.\n");
        return;
    }

    *(tabCpt + *N) = num;
    *(tabSoldes + *N) = s;
    (*N)++;
}

/*-----------------------------------------------------------
  Deposer : ajoute un montant au solde du compte num
-----------------------------------------------------------*/
void Deposer(float montant, int num, float *tabSoldes, int *tabCpt, int N) {
    int i = Rechercher(tabCpt, num, N);

    if (i == -1) {
        printf("Compte introuvable.\n");
        return;
    }

    *(tabSoldes + i) += montant;
}

/*-----------------------------------------------------------
  Retirer : retire un montant si solde suffisant
-----------------------------------------------------------*/
void Retirer(float montant, int num, float *tabSoldes, int *tabCpt, int N) {
    int i = Rechercher(tabCpt, num, N);

    if (i == -1) {
        printf("Compte introuvable.\n");
        return;
    }

    if (*(tabSoldes + i) < montant) {
        printf("Solde insuffisant pour ce retrait.\n");
        return;
    }

    *(tabSoldes + i) -= montant;
}
