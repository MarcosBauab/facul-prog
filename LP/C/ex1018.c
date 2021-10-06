#include <stdio.h>

int main(){
    int valor = 0;
    
    scanf("%i", &valor);
    printf("%i\n", valor);

    int cedulas[7] = {100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 7; i++){
        int divisao = valor / cedulas[i];
        printf("%i nota(s) de R$ %d,00\n", divisao, cedulas[i]);
        valor -= divisao * cedulas[i];
    }

    return 0;
}