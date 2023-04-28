#include <stdio.h>
#include <stdbool.h>

bool nombre_parfait(int n){
    int i;
    int somme=0;
    for (i=1; i<=n/2; i++){
        if (n % i == 0){
            somme=somme + i;
        }
    }
    return somme==n;
}
int main(){
    int n;
    bool est_parfait;
    printf("Entrez un nombre pour tester si il est parfait ");
    scanf("%d",&n);
    est_parfait=nombre_parfait(n);
    if (est_parfait && n!=1){
        printf("Oui, %d est un nombre parfait", n);
    }else {
        printf("Non, %d n'est pas un nombre parfait", n);
    }
    return 0;
}