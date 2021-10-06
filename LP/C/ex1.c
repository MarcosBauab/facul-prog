#include <stdio.h>

int main() {
    
    int nums[5];
    int par = 0;
    int impar = 0;
    int neg = 0;
    int pos = 0;

    scanf("%i", &nums[0]);

    scanf("%i", &nums[1]);

    scanf("%i", &nums[2]);

    scanf("%i", &nums[3]);

    scanf("%i", &nums[4]);

    
    for (int i = 0; i <= 4; i++)
    {
        if(nums[i] % 2 == 0){
            par++;
        } else {
            impar++;
        }

        if(nums[i] < 0){
            neg++;
        } else {
            if(nums[i] > 0){
                pos++;
            }
        }
    }
    
    printf("%i valor(es) par(es)\n", par);
    printf("%i valor(es) impar(es)\n", impar);
    printf("%i valor(es) positivo(s)\n", pos);
    printf("%i valor(es) negativo(s)\n", neg);
    scanf("%f");
    return 0;
}
/*
int main(){
    int nums;
    int ValoresPares = 0,ValoresImpares = 0,ValoresPositivos = 0,ValoresNegativos = 0;
    for (int i = 0; i <= 4; i++)
    {
        scanf("%i", &nums);
        if(nums % 2 == 0)
        {
            ValoresPares++;
        }else
        {
            ValoresImpares++;
        }

        if(nums >= 0)
        {
            ValoresPositivos++;
        }else
        {
            ValoresNegativos++;
        } 
    }
    printf("\n%i valor(es) par(es)",ValoresPares);
    printf("\n%i valor(es) impar(es)",ValoresImpares);
    printf("\n%i valor(es) positivo(s)",ValoresPositivos);
    printf("\n%i valor(es) negativo(s)",ValoresNegativos);

    return 0;
}*/