/*
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXTAM 500
//estrutura de árvore binária
typedef struct Arvore {
    char c[MAXTAM];
    struct Arvore* direita;
    struct Arvore* esquerda;
}Arvore;
typedef Arvore *PArvore;
//função para criar os nós
PArvore criar(char c[], PArvore fe, PArvore fd){
    PArvore p = (PArvore)malloc(sizeof(Arvore));
    strcpy(p->c, c);
    p->esquerda = fe;
    p->direita = fd;
    return p;
}
//liberar a árvore/os nós
PArvore liberar(PArvore arv){
    if(arv != NULL){
        liberar(arv->esquerda);
        liberar(arv->direita);
        free(arv);
    }
    return NULL;
}
int caba = 0;
void imprimir(PArvore arv){
    if(arv != NULL){
        printf("%s ", arv->c);
        caba++;
        imprimir(arv->esquerda);
        imprimir(arv->direita);
    }
}
//imprimir a árvore binária
int caba2 = 0;
void imprimirArvore(PArvore arv, int tabs){
    PArvore aux;
    if(arv != NULL){
        for(int i = 0; i < tabs; i++){
            printf("\t");
        }
        printf("%s\n", arv->c);
        caba2++;
        imprimirArvore(arv->esquerda, tabs-1);
        if(caba2 == caba-1){
            imprimirArvore(arv->direita, tabs);
        } else {
            imprimirArvore(arv->direita, tabs+1);
        }
    } 
}
//variável global devido a recursividade da função
int index = -1;
PArvore arvrinha(char palavra[], int N){ //14-10 + 10
    int i, j = 0, posicao, raiz;
    char string[MAXTAM], aux[MAXTAM];
    memset(string, 0, sizeof(string));        
    memset(aux, 0, sizeof(aux));

    if(index == -1){
        index = N - 1;
    }
    i = index;
    
    if((index - 1) == -1){
        aux[0] = palavra[index];
        PArvore arv3 = criar(aux, NULL, NULL);
        return arv3;
    }

    //números com mais de um dígito
    if(isdigit(palavra[index - 1]) && isdigit(palavra[index])){
        while(isdigit(palavra[i])){
            posicao = i;
            i--;
        }
        for(posicao; posicao <= index; posicao++){
            string[j] = palavra[posicao];
            j++;
        }
        index = index - strlen(string) + 1;
        PArvore arv4 = criar(string, NULL, NULL);

        if((index - 1) == -1){
            return arv4;
        }
        
        arv4->esquerda = arvrinha(palavra, index--);
        arv4->direita = arvrinha(palavra, index--);
        
        return arv4;
    } else if(isdigit(palavra[index - 1])){
        aux[0] = palavra[index];
        PArvore arv2 = criar(aux, NULL, NULL);
        return arv2;
    } 

    aux[0] = palavra[index];

    PArvore arv = criar(aux, NULL, NULL);

    arv->esquerda = arvrinha(palavra, index--);
    arv->direita = arvrinha(palavra, index--);

    return arv;
}

//função usada para limpar o buffer do teclado
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(){
    int valida = 0, j = 0;
    char equa[MAXTAM], equaF[MAXTAM], anterior;

    PArvore tree;
    
    while(valida == 0){
        //Inicializando as strings com \0 para checar se está vazia  
        memset(equa, 0, sizeof(equa));        
        memset(equaF, 0, sizeof(equaF));        

        printf("Digite a expressao: ");
        scanf("%[^\n]s", equa);
        flush();
        //Retirando os espaços da string
        for(int i = 0; i < strlen(equa); i++){ // 5+4          4  
            if(equa[i] != ' '){
                equaF[j] = equa[i];
                anterior = equa[i];
                j++; 
                //Checando erro de número espaço número
            } else if((isdigit(equa[i+1])!= 0) && (isdigit(anterior)!= 0)){
                printf("\nERRO, INSIRA NUMEROS SEM ESPACOS NO MEIO!\n");
            }
        }

        tree = arvrinha(equaF, strlen(equaF));
        imprimir(tree);
        printf("\n\n");
        //imprimirInfix(tree);
        printf("\n\n");
        printf("A arvore binaria eh: \n\n");
        //imprimindo a árvore a partir da altura 0
        imprimirArvore(tree, 1);
        //liberando o espaço de memória alocado
        liberar(tree); 
        valida = 1;
        
    }

    return 0;
}