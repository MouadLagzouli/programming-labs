#include <stdio.h>
#include <math.h>

int main() {
    int i, n;
    float x, P_pow = 0.0f, P_horner = 0.0f;
    float coeff[101]; // A[0]..A[n], n <= 100

    // Lecture de n
 do {
        printf("Entrez le degre du polynome n (1 <= n <= 100) : ");
        scanf("%d", &n);
    } while (n < 1 || n >  100);

    // Lecture des coefficients A[0]..A[n]
    printf("Entrez les coefficients du polynome (A[0]..A[%d]) :\n", n);
    for (i = 0; i <= n; i++) {
        printf("A[%d] = ", i);
        scanf("%f", &coeff[i]);
    }

    // Lecture de x
    printf("Entrez la valeur de x : ");
    scanf("%f", &x);

    // Methode 1 : evaluation directe avec pow()
    for (i = 0; i <= n; i++) {
        P_pow += coeff[i] * (float)pow(x, i);
    }

    // Methode 2 : Horner
    P_horner = coeff[n];
    for (i = n - 1; i >= 0; i--) {
        P_horner = P_horner * x + coeff[i];
    }

    // Affichage
    printf("\n--- Resultats ---\n");
    printf("P(x) avec pow()    = %.6f\n", P_pow);
    printf("P(x) avec Horner   = %.6f\n", P_horner);

return 0;
}
