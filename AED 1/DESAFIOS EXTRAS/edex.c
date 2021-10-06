#include <stdio.h>
#include <math.h>

int fatorial(int i){
    int fat;
    if(i == 1){
        fat = 1;
    } else {
        fat = i * fatorial(i - 1);
        return fat;
    }
}

void main(){
    float e,x,frac;
    int i = 2;

    scanf("%f", &x);

    e = 1 + x;

    while(1){
        frac = pow(x,i) / fatorial(i);
        if(frac < 0.001){
            break;
        } 
        e += frac;
        i++;       
    }

    printf("%f", e);
    
}
