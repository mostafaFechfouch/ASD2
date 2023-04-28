#include <stdio.h>

int somme_carre(int n){
    int i,somme;
    somme = 0;
    for (i=1;i<=n;i++){
        somme = somme + i*i;
    }
    return somme;
}

int main(){
    int n,somme;
    printf("Entrer un nombre ");
    scanf("%d",&n);
    somme=somme_carre(n);
    printf("La somme des carrés des nombres à %d est %d ",n,somme);

    return 0;
}