#include <stdio.h>



int somme_recursive(int n){
    if (n==1){
        return 1;
    }
    return n+ somme_recursive(n-1);
}

int main(){
    int n,somme;
    printf("Donner la valeur de n\n");
    scanf("%d",&n);

    somme= somme_recursive(n);
    printf("La somme des entiers jusqu'a %d est %d\n",n,somme);

    return 0;
}