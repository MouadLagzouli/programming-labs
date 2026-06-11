
#include <stdio.h>
#include <math.h>

struct Point {
    float x;
      float y;
};

int main() {
    struct Point p1, p2;
    float distance;

    printf("Saisir les coordonnees du point 1 (x y) : ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Saisir les coordonnees du point 2 (x y) : ");
    scanf("%f %f", &p2.x, &p2.y);

    distance = sqrt((p2.x - p1.x) * (p2.x - p1.x)
                  + (p2.y - p1.y) * (p2.y - p1.y));

    printf("La distance entre p1 et p2 est : %.2f\n", distance);

    return 0;
}
