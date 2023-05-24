#include <stdio.h>
#include <stdlib.h>

void removeNegativeElements(int P[], int *p_top, int Q[], int *q_top) {
    while (*p_top >= 0) {  // tant que la pile P n'est pas vide
        int element = P[*p_top];  // récupère l'élément en haut de la pile P

        if (element >= 0) {
            Q[++(*q_top)] = element;  // si l'élément est positif, l'ajoute à la pile Q
        }

        (*p_top)--;  // décrémente l'indice de l'élément en haut de la pile P
    }

    while (*q_top >= 0) {  // tant que la pile Q n'est pas vide
        P[++(*p_top)] = Q[(*q_top)--];  // ajoute les éléments de la pile Q à la pile P
    }
}

int main() {
    int P[10] = {3, -5, 7, -1, 0, -4, 6, -2, 9, -8};
    int Q[10];
    int p_top = 9;  // l'indice du dernier élément de la pile P
    int q_top = -1;  // l'indice du dernier élément de la pile Q

    removeNegativeElements(P, &p_top, Q, &q_top);

    // affiche la pile P après suppression des éléments négatifs
    printf("Pile P : ");
    for (int i = 0; i <= p_top; i++) {
        printf("%d ", P[i]);
    }
    printf("\n");

    return 0;
}
