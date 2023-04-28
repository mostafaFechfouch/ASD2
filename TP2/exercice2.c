#include <stdio.h>

void lire(float *tableau, int n, int i){
    if(i<n){
        printf("entrer la valeur de l'indice %d\n", i);
        scanf("%d",&tableau[i]);
        lire(tableau,n,i+1);
    }
}

int recherche(int *tableau, int n, int i, int val){
    if(i>=n){
        return -1;
    }
    if(tableau[i]==val){
        return i;
    }
    return recherche(tableau,n,i+1,val);
}

void inverser(int *tableau, int i, int j){
    int temp;
    if(i<j){
        temp=tableau[i];
        tableau[i]=tableau[j];
        tableau[j]=temp;
        inverser(tableau,i+1,j-1);
    }
}
void afficher(int *tableau, int n,int i){
    if(i<n){
        printf("tableau[%d]=%d\n" ,i,tableau[i]);
        afficher(tableau,n,i+1);
    }
}

int main(){
    int n, val, found;

    printf("Entrer n la taille du tableau\n");
    scanf("%d", &n);

    int tableau[n];
    lire(tableau, n,0);

    printf("entrer la valeur à rechercher\n");
    scanf("%d", &val);

    found=recherche(tableau, n,0, val);
    if(found!=-1){
        printf("La valeur %d existe dans le tableau à l'indice %d\n",val,found);
    }else{
        printf("La valeur %d n'existe pas dans le tableau\n",val);
    }

    afficher(tableau,n,0);
    inverser(tableau,0,n-1);
    printf("Tableau apres inversion\n");
    afficher(tableau,n,0);
    return 0;
}