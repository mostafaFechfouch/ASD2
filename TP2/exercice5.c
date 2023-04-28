#include <stdio.h>

void tour_salim(int n);

void tour_mehdi(int n){
    if(n==0){
        printf("Salim a gagne\n");
    }else{
        tour_salim(n-1);
    }
}
void tour_salim(int n){
    if(n==0){
        printf("Mehdi a gagne\n");
    }else if(n%2==0){
        tour_mehdi(n-2);
    }else{
        tour_mehdi(n-1);
    }
}

int main(){
    tour_mehdi(1);
    return 0;
}