#include <stdio.h>

void saisie(int n,int m, int matrice[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Entrer la valeur de la case [%d][%d] ",i,j);
            scanf("%d",&matrice[i][j]);
        }
    }

}

void moy_lignes(float *T,int n,int m, int matrice[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        float somme=0;
        for(j=0;j<m;j++){
            somme=somme+matrice[i][j];
        }
        T[i]=somme/(float)m;
        printf("la moyenne de la ligne %d est %f\n",i,T[i]);
    }
}

void min_col(int *C, int n, int m, int matrice[n][m]){
    int i,j;
    for(j=0;j<m;j++){
        int min=matrice[0][j];
        for(i=1;i<n;i++){
            if(matrice[i][j]<min){
                min=matrice[i][j];
            }
        }
        C[j]=min;
        printf("le minimum de la colonne %d est %d\n",j,C[j]);
    }
}

int main(){
    int n,m;
    printf("Entrer le nombre des lignes ");
    scanf("%d",&n);
    printf("Entrer le nombre des colonnes ");
    scanf("%d",&m);

    int matrice[n][m];
    float T[n];
    int C[m];

    saisie(n,m,matrice);

    moy_lignes(T, n, m, matrice);

    min_col(C, n, m, matrice);

    return 0;
}