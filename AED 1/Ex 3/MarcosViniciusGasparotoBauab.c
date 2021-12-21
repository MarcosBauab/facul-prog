/*
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define PILHA_MAX 100

typedef struct{
    char vetor[PILHA_MAX];
    int topo;
}Pilha;

Pilha* novaPilha(){
    Pilha *pilhaNova;
    pilhaNova = (Pilha *)malloc(sizeof(Pilha));
    pilhaNova->topo = -1;
    memset(pilhaNova->vetor, 0, PILHA_MAX);
    return pilhaNova;
}

Pilha* liberar(Pilha *p){
    free(p);
    return NULL;
}

int push(Pilha* p, char val){
    if(p->topo >= PILHA_MAX - 1){
        return -1;
    }
    p->topo++;
    p->vetor[p->topo] = val;
    return 0;
}

int pop(Pilha* p, char *val, int i){
    if(p->topo < 0)
        return -1;

    val[i] = p->vetor[p->topo];

    p->topo--;
    return 0;
}

float desempilhar(Pilha *p){
    float num;
    if(p->topo < 0){
        printf("Pilha vazia!");
    } else {
        num = p->vetor[p->topo];
        p->topo--;
        return num;
    }
    return 0;
}

int prioridade(Pilha *p, char operador){
    int poperador,pt;
    
    if(operador == '^')
        poperador = 4;
    else if(operador == '*' || operador == '/')
        poperador = 2;
    else if(operador == '+' || operador == '-')
        poperador = 1;
    
    if(p->vetor[p->topo] == '^')
        pt = 3;
    else if(p->vetor[p->topo] == '*' || p->vetor[p->topo] == '/')
        pt = 2;
    else if(p->vetor[p->topo] == '+' || p->vetor[p->topo] == '-')
        pt = 1;
    
    return (poperador > pt);
}

void calculo(char posfixo[PILHA_MAX], Pilha *p){
    char *numero;
    float numero1, numero2, total;
    numero = strtok(posfixo, " ");
    while(numero != NULL){
        switch (numero[0])
        {
        case '+':
            numero1 = desempilhar(p);
            numero2 = desempilhar(p);
            total = numero2 + numero1;
            push(p, total);
            break;
        case '-':
            numero1 = desempilhar(p);
            numero2 = desempilhar(p);
            total = numero2 - numero1;
            push(p, total);
            break;
        case '*':
            numero1 = desempilhar(p);
            numero2 = desempilhar(p);
            total = numero2 * numero1;
            push(p, total);
            break;
        case '/':
            numero1 = desempilhar(p);
            numero2 = desempilhar(p);
            total = numero2 / numero1;
            push(p, total);
            break;
        case '^':
            numero1 = desempilhar(p);
            numero2 = desempilhar(p);
            total = pow(numero2, numero1);
            push(p, total);
            break;
        default:
            numero1 = strtol(numero, NULL, 10);
            //numero1 = atoi(numero);
            push(p, numero1);
            break;
        }
        numero = strtok(NULL, " ");
    }
    total = desempilhar(p);
    printf("Resultado: %.1f\n", total);
}

int posfix(Pilha* p , char s[PILHA_MAX], char *recebe){
    int j = 0;
    
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            if(p->topo == -1 || prioridade(p, s[i]) == 1){
                recebe[j] = ' ';
                j++;
                push(p, s[i]);
            } else {
                while(1){
                    recebe[j] = ' ';
                    j++;
                    pop(p, recebe, j);
                    j++;
                    if(p->topo == -1 || prioridade(p, s[i]) == 1){
                        recebe[j] = ' ';
                        j++;
                        push(p, s[i]);
                        break;
                    }
                }
            }
        } else {
            recebe[j] = s[i];
            j++;
        }
    }
    while(p->topo != -1){
        recebe[j] = ' ';
        j++;
        pop(p, recebe, j);
        j++;
    }
    recebe[j] = '\0';
    
    return 0;
}

int main(){
    Pilha *pilha = novaPilha();
    Pilha *pilhaNumeros = novaPilha();

    char numRetornado[PILHA_MAX];
    char string[PILHA_MAX];
    int teste1 = 0;

    printf("Digite sua expressao: ");
    scanf("%[^\n]s", string);

    posfix(pilha, string, numRetornado);

    printf("Operacao pos-fixa: %s\n", numRetornado);

    calculo(numRetornado, pilhaNumeros);

    liberar(pilha);
    liberar(pilhaNumeros);
    return 0;
}