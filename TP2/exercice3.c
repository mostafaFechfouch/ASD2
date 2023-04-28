#include <stdio.h>

int somme_des_carrees(int n)
{
    int chiffre;
    if (n == 0) {  // base case
        return 0;
    }
    chiffre = n % 10;
    return (chiffre * chiffre) + somme_des_carrees(n / 10);
}

int main(){
    int n,result;

    printf("Donner la valeur de n\n");
    scanf("%d",&n);

    result = somme_des_carrees(n);
    printf("La somme des carrees des chiffres du %d est %d\n", n, result);

    return 0;
}
