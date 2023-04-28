#include <stdio.h>
#include <math.h>
struct complex {
    float A;
    float B;
};

struct complex somme_complex(struct complex N1, struct complex N2){
    struct complex SC;
    SC.A= N1.A+N2.A;
    SC.B= N1.B+N2.B;
    return SC;
}

float module_complex(struct complex N){
    float MC;
    MC= sqrt(N.A*N.A + N.B*N.B);
    return MC;
}

struct complex produit_complex(struct complex N1, struct complex N2){
    struct complex PC;
    PC.A= N1.A * N2.A - N1.B * N2.B;
    PC.B= N1.B * N2.A + N1.A * N2.B;
    return PC;
}

void comparaison_complex(struct complex N1, struct complex N2){
    if(N1.A==N2.A && N1.B==N2.B){
        printf("Les deux nombres sont identiques \n");
    }else if(N1.A>=N2.A && N1.B>=N2.B){
        printf("N1 et plus grand que N2 \n");
    }else if(N1.A<=N2.A && N1.B<=N2.B){
        printf("N1 et plus petit que N2 \n");
    }else{
        printf("N1 et N2 sont quelconques \n");
    }
}
int main(){
    struct complex N1,N2;
    printf("Donner la valeur de N1.A \n");
    scanf("%f",&N1.A);
    printf("Donner la valeur de N1.B \n");
    scanf("%f",&N1.B);

    printf("Donner la valeur de N2.A \n");
    scanf("%f",&N2.A);
    printf("Donner la valeur de N2.B \n");
    scanf("%f",&N2.B);

    float MC1,MC2;
    struct complex PC, SC;

    MC1= module_complex(N1);
    printf("Module de N1 est: %f\n",MC1);

    MC2= module_complex(N2);
    printf("Module de N2 est: %f\n",MC2);

    SC= somme_complex(N1,N2);
    printf("Somme de N1 et N2 est: %f+i%f\n",SC.A,SC.B);

    PC= produit_complex(N1,N2);
    printf("Produit de N1 et N2 est: %f+i%f\n",PC.A,PC.B);

    comparaison_complex(N1,N2);

    return 0;
}