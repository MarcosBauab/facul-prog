/*
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_TAM 1000

typedef struct lista{
    int num;
    struct lista* prox;
} Lista;
typedef Lista *PontLista;
//Função usada para inserir em ordem invertida, baseado no da professora
PontLista inserir(PontLista inicial, int dado){
    PontLista novo;
    novo = (PontLista)malloc(sizeof(Lista));
    novo->num = dado;
    novo->prox = inicial;
    return novo;
}
//Função usada para inserir em ordem, baseado no da professora
PontLista insere_final(PontLista inicial, int dado){
    PontLista novo, ant = NULL, paux = inicial;  
    novo = (PontLista) malloc(sizeof(Lista));
    novo->num = dado; 
    
    while (paux!=NULL){
        ant = paux;
        paux = paux->prox;
    }
    
    if (ant == NULL){
    
        novo->prox = inicial;
        inicial = novo;
    }
    else{ 
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return inicial;
}
//Função recursiva usada para impressão de listas encadeadas
void imprimir(PontLista inicial){
    if (inicial == NULL){
        return;
    }
    printf("%d", inicial->num);
    imprimir(inicial->prox);
}
//Função de soma
PontLista calculo(PontLista lista1, PontLista lista2){
    PontLista result = NULL;
    PontLista aux1, aux2 = lista2;
    //Pegar cada caractere e somar, inserindo no resultado
    for(aux1 = lista1; aux1 != NULL && aux2 != NULL; aux1 = aux1->prox){
        int soma = aux1->num + aux2->num;
        
        //Se a soma for maior que 10, pegar o segundo dígito e somar +1 no dígito seguinte
        if (soma >= 10){
            result = inserir(result, soma - 10);
            //Se for o último número, inserir 1, pois a unidade ultrapassou a dos dois números
            if(aux2->prox == NULL){
                result = inserir(result, 1);
            } else {
                aux2 = aux2->prox;
                aux2->num++;
            }
        } else {
            result = inserir(result, soma);
            aux2 = aux2->prox;
        }
    }

    return result;
}
//Função para liberar uma lista encadeada completa
void liberar(PontLista lista){
    if(lista != NULL){
        liberar(lista->prox);
        free(lista);
    }
}

int main(){
    PontLista listaEncadeada1 = NULL;
    PontLista listaEncadeada2 = NULL;
    PontLista resultado = NULL;

    char string[MAX_TAM], string2[MAX_TAM];

    printf("--------------------------\n");
    REFAZ: printf("Digite o primeiro numero: ");
    scanf("%s", string);
    //validação de erros
    for(int i = 0; i < strlen(string); i++){
        if(isdigit(string[i]) == 0){
            //Não é um número, portanto volta
            goto REFAZ;
            break;
        } else {
            listaEncadeada1 = inserir(listaEncadeada1, string[i] - '0');
        }
    }

    REFAZ2: printf("Digite o segundo numero: ");
    scanf("%s", string2);
    //validação de erros
    for(int i = 0; i < strlen(string2); i++){
        if(isdigit(string2[i]) == 0){
            //Não é um número, portanto volta
            goto REFAZ2;
            break;
        } else {
            listaEncadeada2 = inserir(listaEncadeada2, string2[i] - '0');
        }
    }
    printf("--------------------------\n");

    //Igualando as casas para fazer a soma
    if(strlen(string) > strlen(string2)){
        int dif = strlen(string) - strlen(string2);
        for(int i = 0; i < dif; i++){
            listaEncadeada2 = insere_final(listaEncadeada2, 0);
        }
    } else if(strlen(string) < strlen(string2)){
        int dif = strlen(string2) - strlen(string);
        for(int i = 0; i < dif; i++){
            listaEncadeada1 = insere_final(listaEncadeada1, 0);
        }
    } 

    resultado = calculo(listaEncadeada1, listaEncadeada2);
    printf("O resultado eh: \n");
    imprimir(resultado);
    printf("\n");
    liberar(listaEncadeada1);
    liberar(listaEncadeada2);
    liberar(resultado);
    return 0;
}