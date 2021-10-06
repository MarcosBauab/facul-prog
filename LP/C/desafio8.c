#include<stdio.h>

void * diagonal(int mat[][3]){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (i == j){
                printf("%i ",mat[i][j]);
            }
        }
    }

}

void * abaixo(int mat[][3]){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (i > j){
                printf("%i ",mat[i][j]);
            }
        }
    }

}

void * somar_matrizes(int mat[][3], int mat2[][4]){
    int somada[7][5];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            somada[i][j] = mat[i][j];
            if (i == 0 && j == 0){
                printf("[%i", somada[i][j]);
            }else {
                printf(", %i", somada[i][j]);
            }
            
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            somada[i + 3][j] = mat2[i][j];
            if (i == 3 && j == 3){
                printf(", %i]", somada[i + 3][j]);
            }else {
                printf(", %i", somada[i + 3][j]);
            }
        }
    }
}

void main(){

    int matriz[3][3] = {{1,2,3}, {4,5,6}, {10,20,30}};
    int matriz2[4][4] = {{1,2,3,4}, {7,5,6,8}, {10,20,30,40}, {25,50,100,125}};
    printf("Diagonal da matriz : \n");
    diagonal(matriz);
    printf("\nAbaixo da matriz : \n");
    abaixo(matriz);
    printf("\nSoma das matrizes : \n");
    somar_matrizes(matriz, matriz2);
}