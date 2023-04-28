#include <stdio.h>

long suite_Un(int n){
    long Un;
    int i;
    Un = 10;
    for(i=1; i<=n; i++){
        Un=5*Un+9;
        printf("Un%d= %lu\n",i,Un);
    }
    return Un;
}

int main(){
    int n;
    long Un;
    printf("Entrez le rang du terme que vous souhaitez calculer ");
    scanf("%d",&n);
    
    Un=suite_Un(n);
    printf("La valeur du terme %d est %lu ",n,Un);

    return 0;
}