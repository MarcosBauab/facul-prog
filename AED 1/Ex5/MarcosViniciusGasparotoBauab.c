/*
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_TAM 50

typedef struct lista{
    char letra;
    //É usado para a pontuação
    int num;
    struct lista* prox;
} Lista;
typedef Lista *PontLista;
//Imprime letras
void imprimir(PontLista ultimo){
    PontLista p;
    if(ultimo != NULL){
        p = ultimo->prox;
        do{
            printf("%c", p->letra);
            p = p->prox;
        } while(p != ultimo->prox);
    } 
}
//Imprime números
void imprimir_num(PontLista ultimo){
    PontLista p;
    if(ultimo != NULL){
        p = ultimo->prox;
        do{
            printf("%d ", p->num);
            p = p->prox;
        } while(p != ultimo->prox);
    } 
}
//Insere em ordem
PontLista inserir(PontLista ultimo, char val){
    PontLista novo = (PontLista) malloc(sizeof(Lista));
    novo->letra = val;
    if(ultimo == NULL){
        novo->prox = novo;
        ultimo = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    
    return novo;
}
//Insere números em ordem
PontLista inserir_num(PontLista ultimo, int val){
    PontLista novo = (PontLista) malloc(sizeof(Lista));
    novo->num = val;
    if(ultimo == NULL){
        novo->prox = novo;
        ultimo = novo;
    } else {
        novo->prox = ultimo->prox;
        ultimo->prox = novo;
    }
    
    return novo;
}
//Liberar
void liberar(PontLista ultimo){
    PontLista p = ultimo->prox;
    PontLista q = ultimo;
    while(p != ultimo){
        q = p;
        p = p->prox;
        free(q);
    }
    free(ultimo);
}
//Calcula quantas substrings tem e retorna a quantidade de letras iguais
int substrings(PontLista strincipal, char sub[MAX_TAM], int tamanho, int *subs){
    int i,j, letrasIguais = 0, substring = 0, aux = 0, aux2 = 0;
    //Checar se há substrings na string principal
    for(j = 0; j < strlen(sub); j++){
        aux = letrasIguais;
        //Checa se já exitem letras iguais
        if(letrasIguais != 0){ 
            strincipal = strincipal->prox;
            if (sub[j] == strincipal->letra){
                letrasIguais++;
            }
            aux++;
            //Se alguma letra da substring não bater, começar de novo
            if(aux != letrasIguais && aux2 <= tamanho){
                letrasIguais = 0;
                j = -1;
                continue;
            }
        //Se é a primeira vez tentar achar uma letra igual a da substring
        } else {
            for(i = 0; i < tamanho; i++){
                if (sub[j] == strincipal->letra){
                    letrasIguais++;
                    break;
                } else {
                    strincipal = strincipal->prox;
                }
                aux2++;
            }
            //Se não achar nenhuma letra igual de primeira, sair do for
            if(letrasIguais == 0){
                break;
            }
        }
        
    }   
    //Ver se a quantidade de letras bate com o tamanho da substring 
    if(letrasIguais == strlen(sub)){
        //E adicionar nas substrings se bater
        *subs = *subs + 1;
    } else {
        letrasIguais = 0;
    }

    return letrasIguais;
}
//Comparar qual o menor valor em uma lista encadeada
int comparar(PontLista lista){
    PontLista p = lista->prox;
    int recebe = 50;
    do{
        if(p->num != 0 && p->num < recebe){
            recebe = p->num;
        }
        p = p->prox;
    } while(p != lista->prox);
    return recebe;
}

int main(){
    PontLista stringLista = NULL;
    PontLista pontuacao = NULL;
    int linhas, subs = 0;
    char linhasTeste[5], stringPrincipal[MAX_TAM], substring[MAX_TAM];
    REFAZ: printf("Digite a quantidade de substrings: ");
    scanf("%s", linhasTeste);
    //validação de erros 
    for(int i = 0; i < strlen(linhasTeste); i++){
        if(isdigit(linhasTeste[i]) == 0){
            //Não é um número, portanto volta
            printf("ERRO, INSIRA UM NUMERO!\n\n");
            goto REFAZ;
            break;
        } 
    }
    linhas = atoi(linhasTeste);
    printf("--------------------------\n");

    REFAZ2: printf("Digite a palavra principal (letras minusculas, 50 char): ");
    scanf("%s", stringPrincipal);
    //validação de erros
    for(int i = 0; i < strlen(stringPrincipal); i++){
        if(isdigit(stringPrincipal[i]) != 0 || isupper(stringPrincipal[i]) > 0){
            //Não é uma letra minúscula, portanto volta
            printf("ERRO, INSIRA UMA LETRA MINUSCULA!\n\n");
            goto REFAZ2;
            break;
        } else {
            stringLista = inserir(stringLista, stringPrincipal[i]);
        }
    }
    printf("--------------------------\n");

    for(int i = 0; i < linhas; i++){
        REFAZ3: printf("Digite a substring: ");
        scanf("%s", substring);
        //validação de erros
        for(int i = 0; i < strlen(substring); i++){
            if(isdigit(substring[i]) != 0 || isupper(substring[i]) > 0){
                //Não é uma letra minúscula, portanto volta
                printf("ERRO, INSIRA UMA LETRA MINUSCULA!\n\n");
                goto REFAZ3;
                break;
            }
        }
        pontuacao = inserir_num(pontuacao, substrings(stringLista, substring, strlen(stringPrincipal), &subs));
    }

    printf("Numero de strings ciclicas: %d\n", subs);
    
    printf("Menor pontuacao: %d", comparar(pontuacao));

    liberar(stringLista);
    liberar(pontuacao);

    return 0;
}