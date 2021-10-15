/* 
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>

struct Veiculo{
    char marca[15];
    char modelo[25];
    int anoFab;
    char placa[6];
    int quilometragem;
    int numPortas;
    char arCondicionado;
};
    
void cadastrar(struct Veiculo *carro){
    carro->anoFab = 20;
}

void main(){
    typedef struct Veiculo *pontVeiculo;
    //carro é um ponteiro da struct Veiculo
    pontVeiculo carro;
    //aloco a quantidade de espaços necessários na memória
    carro = (struct Veiculo *)malloc(sizeof(struct Veiculo));
    
    int opt;

    while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5){
        printf("1) Inserir novo cadastro de veículo\n");
        printf("2) Alterar cadastro\n");
        printf("3) Mostrar os dados de um veículo\n");
        printf("4) Apagar registro\n");
        printf("5) Sair\n");
        scanf("%d", &opt);
    } 
    
    switch (opt){
    case 1:
        cadastrar(carro);
        break;
    
    default:
        break;
    }

    free(carro);
}


