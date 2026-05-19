#include <stdio.h>   

void triSelection(int T[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (T[j] < T[minIndex])
                minIndex = j;
        }
        temp = T[i];
        T[i] = T[minIndex];
        T[minIndex] = temp;
    }
}

int main() {
    int T[] = {5, 2, 9, 1, 3};
    int n = sizeof(T) / sizeof(T[0]);

    printf("Tableau avant tri : ");
    for (int i = 0; i < n; i++) printf("%d ", T[i]);

    triSelection(T, n);

    printf("\nTableau après tri (sélection) : ");
    for (int i = 0; i < n; i++) printf("%d ", T[i]);

    return 0;
}
