#include <stdio.h>

int binomial(int n, int p){
    if (p==0 || p==n){
        return 1;
    }
    return binomial(n-1,p)+ binomial(n-1,p-1);
}

int main(){
    int n,p;
    printf("Donner la valeur de n \n");
    scanf("%d",&n);
    printf("Donner la valeur de p \n");
    scanf("%d",&p);
    int b;
    b=binomial(n,p);
    printf("Le coefficient binomial de n et p est %d\n",b);

    return 0;
}