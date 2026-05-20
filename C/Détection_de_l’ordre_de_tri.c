#include <stdio.h>

int ordre_tableau(const int t[], int n) {
    int croissant = 1, decroissant = 1;

    for (int i = 0; i < n - 1; i++) {
        if (t[i] > t[i + 1]) croissant = 0;
        if (t[i] < t[i + 1]) decroissant = 0;
    }

    if (croissant) return 1;     /* croissant */
    if (decroissant) return -1;  /* decroissant */
    return 0;                    /* non trie */
}

int main (void) {
    int n;

    printf("Donner N : ");
    scanf("%d", &n);

    int t[n];
    for (int i = 0; i < n; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    }

    int ord = ordre_tableau(t, n);

    if (ord == 1) printf("Le tableau est trie CROISSANT.\n");
    else if (ord == -1) printf("Le tableau est trie DECROISSANT.\n");
    else printf("Le tableau n'est PAS trie.\n");

return 0;
}
