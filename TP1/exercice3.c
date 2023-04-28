#include <stdio.h>

void lire_tableau(float *tableau, int n){
    int i;
    for(i=0; i<n; i++){
        printf("entrer la valeur de l'indice %d ", i);
        scanf("%f",&tableau[i]);
    }
}

void afficher_tableau(float *tableau, int n){
    int i;
    for (i=0; i<n; i++){
        printf("la valeur à l'indice %d est %f\n", i, tableau[i]);
    }
}

void afficher_indice_valeur_negative(float *tableau, int n){
    int i;
    for (i=0; i<n; i++){
        if (tableau[i]<0){
            printf("la valeur %f à l'indice %d est negative\n", tableau[i], i);
        }
    }
}

int rechercher_tableau(float *tableau, int n,float val){
    int i;
    for (i=0; i<n; i++){
        if (tableau[i]==val){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,found;
    float val;

    printf("Entrer n la taille du tableau ");
    scanf("%d", &n);

    float tableau[n];

    lire_tableau(tableau, n);

    afficher_tableau(tableau, n);

    afficher_indice_valeur_negative(tableau,n);

    printf("entrer la valeur à rechercher ");
    scanf("%f", &val);

    found=rechercher_tableau(tableau, n, val);
    if(found!=-1){
        printf("La valeur %f existe dans le tableau à l'indice %d",val,found);
    }else{
        printf("La valeur %f n'existe pas dans le tableau",val);
    }

    return 0;
}
