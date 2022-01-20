/*
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXTAM 100
//estrutura de árvore binária
typedef struct Arvore {
    char c;
    struct Arvore* direita;
    struct Arvore* esquerda;
}Arvore;
typedef Arvore *PArvore;
//função para criar os nós
PArvore criar(char c, PArvore fe, PArvore fd){
    PArvore p = (PArvore)malloc(sizeof(Arvore));
    p->c = c;
    p->esquerda = fe;
    p->direita = fd;
    return p;
}
//imprimir a árvore binária
void imprimirArvore(PArvore arv, int tabs){
    if(arv != NULL){
        imprimirArvore(arv->esquerda, tabs+1);
        for(int i = 0; i < tabs; i++){
            printf("\t");
        }
        printf("%c\n", arv->c);
        imprimirArvore(arv->direita, tabs+1);
    } 
}
//variável global dado a recursividade da função
int contador = 0;
//checa a validade da prefixa
void validaP(PArvore arv, char palavra[]){
    if(arv != NULL){
        palavra[contador] = arv->c;
        contador++;
        validaP(arv->esquerda, palavra);
        validaP(arv->direita, palavra);
    } 
}
//checa a validade da infixa
void validaI(PArvore arv, char palavra[]){
    if(arv != NULL){
        validaI(arv->esquerda, palavra);
        palavra[contador] = arv->c;
        contador++;
        validaI(arv->direita, palavra);
    } 
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
//variável global usada por conta da recursividade da função
int passo = 0;
//função usada para inserir os nós na árvore de maneira posfixa
PArvore criar_arv_posfix(char S1[], char S2[], int pi, int pf, int N){
    //através do ponto inicial (pi) e do ponto final (pf)
    //calcular quem está na esquerda ou direita do ponto buscado
    int  posicao, i;

    char aux;

    if ((pi > pf) || (passo == N)){
        return NULL; 
    }

    PArvore arv_posfix = criar(S1[passo], NULL, NULL);

    if(pi == pf){
        passo++;
        return arv_posfix;
    }

    aux = S1[passo++];
    //verifica, do início ao final, onde está a raiz na infixa
    for(i = pi; i <= pf; i++){
        if(aux == S2[i]){
            posicao = i;
        }
    }

    arv_posfix->esquerda = criar_arv_posfix(S1, S2, pi, posicao - 1, N);
    arv_posfix->direita = criar_arv_posfix(S1, S2, posicao + 1, pf, N);

    return arv_posfix;

}
//função usada para limpar o buffer do teclado
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(){
    int noss, valida = 0;
    char nos[MAXTAM];
    char infix[MAXTAM], prefix[MAXTAM], infixC[MAXTAM], prefixC[MAXTAM];
    //Inicializando as strings com \0 para checar se está vazia  
    memset(infix,0,sizeof(infix));
    memset(prefix,0,sizeof(prefix));
    memset(infixC,0,sizeof(infixC));
    memset(prefixC,0,sizeof(prefixC));

    PArvore tree;
    
    while(valida == 0){
        printf("Digite a quantidade de nos da arvore: ");
        scanf("%s", nos);
        flush();
        //validação de erros dos nós
        for(int i = 0; i < strlen(nos); i++){
            if(isdigit(nos[i]) == 0 || atoi(nos) > 100){
                printf("Digite a quantidade correta de nos da arvore: ");
                scanf("%s", nos);
                flush();
                i = 0;
            }
        }
        noss = atoi(nos);

        printf("Digite a sequencia dos nos em ordem pre-fixa: ");
        scanf("%s", prefix);
        flush();
        //validação de erros do prefix
        while(noss != strlen(prefix)){
            memset(prefix,0,sizeof(prefix));  
            
            printf("Numero de nos incorreto! Digite uma palavra de tamanho certo!\n");
            printf("Digite a sequencia dos nos em ordem pre-fixa: ");
            scanf("%s", prefix);
            flush();

        }

        printf("Digite a sequencia dos nos em ordem infixa: ");
        scanf("%s", infix); 
        flush();
        
        //validação de erros do infix
        while(noss != strlen(infix)){
            memset(infix,0,sizeof(infix));  

            printf("Numero de nos incorreto! Digite uma palavra de tamanho certo!\n");
            printf("Digite a sequencia dos nos em ordem infixa: ");
            scanf("%s", infix);
            flush();

        }
        //criando a árvore binária e colocando passo como zero
        tree = criar_arv_posfix(prefix, infix, 0, noss, noss);
        passo = 0; 
        //validando se a infixa está correta
        validaP(tree, prefixC);
        contador = 0;
        validaI(tree, infixC);
        contador = 0;
        printf("\nInfixa correta: %s", infixC);
        printf("\nPrefixa correta: %s\n\n", prefixC);
        //validação de infixa
        if(strcmp(infixC, infix) != 0 || strcmp(prefixC, prefix) != 0){
            //significa que as duas strings são diferentes, o que não era para ser
            printf("Infixa ou prefixa incorreta!\n\n");
            liberar(tree);
        } else {
            printf("A arvore binaria eh: \n\n");
            //imprimindo a árvore a partir da altura 0
            imprimirArvore(tree, 0);
            //liberando o espaço de memória alocado
            liberar(tree); 
            valida = 1;
        }
    }

    return 0;
}