#include<stdio.h>

void deslocamento_x(int *vetor, int x){
    
    for(int i = 0; i < 4; i++){
        vetor[i] = vetor[i] + x;
    }
}

int main(){

    int x;
    int vetor[4] = {1,2,3,4};
    printf("Insira o valor de x : ");
    scanf("%i", &x);
    
    deslocamento_x(vetor, x);

    for(int i = 0; i < 4; i++){
        printf("O %i valor do vetor novo eh: %i\n", i + 1, vetor[i]);
    }
    
}