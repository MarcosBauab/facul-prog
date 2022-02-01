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
//imprime a árvore binária
void imprimirArvore(PArvore arv, int tabs){
    if(arv != NULL){
        imprimirArvore(arv->esquerda, tabs+1);
        for(int i = 0; i < tabs; i++){
            printf("\t");
        }
        printf("%s\n", arv->c);
        imprimirArvore(arv->direita, tabs+1);
    } 
}
//função de operações com sinais, que altera os valores na árvore binária
int conta(PArvore arv, int *num){ 

    int num1, num2, resultado;
    /*
        primeiro começa pelos sinais, achando eles
        depois disso checa se está no último nó
        senão checa o sinal do próximo nó e vê
        se por exemplo são dois negativos, se sim os valores são somados
        e o próximo nó é alterado para receber o resultado.
        o mesmo ocorre com a soma.
        e o sinal é alterado na árvore se o resultado tiver um sinal diferente.
    */
    if(arv != NULL){

        if(strcmp(arv->c, "-") == 0){

            num1 = atoi(arv->esquerda->c);

            if(arv->direita->esquerda == NULL){

                num2 = atoi(arv->direita->c);
                resultado = num2 - num1;

            } else {

                if(strcmp(arv->direita->c, "-") == 0){

                    num2 = atoi(arv->direita->esquerda->c); 
                    resultado = num2 + num1;
                    sprintf(arv->direita->esquerda->c,"%d",resultado);

                } else {

                    num2 = atoi(arv->direita->esquerda->c); 
                    resultado = num2 - num1;

                    if(resultado <= 0){

                        resultado = resultado * -1;
                        sprintf(arv->direita->esquerda->c,"%d",resultado);
                        strcpy(arv->direita->c, "-");

                    } else {

                        sprintf(arv->direita->esquerda->c,"%d",resultado);

                    }
                }
            }
        } else if(strcmp(arv->c, "+") == 0){
            num1 = atoi(arv->esquerda->c);
            if(arv->direita->esquerda == NULL){
                num2 = atoi(arv->direita->c);
                resultado = num2 + num1;
            } else {
                if(strcmp(arv->direita->c, "-") == 0){
                    num2 = atoi(arv->direita->esquerda->c); 
                    resultado = num1 - num2;
                    if(resultado >= 0){
                        strcpy(arv->direita->c, "+");
                    } else {
                        resultado = resultado * -1;
                        sprintf(arv->direita->esquerda->c,"%d",resultado);
                    }
                    sprintf(arv->direita->esquerda->c,"%d",resultado);
                } else {
                    num2 = atoi(arv->direita->esquerda->c); 
                    resultado = num2 + num1;
                    sprintf(arv->direita->esquerda->c,"%d",resultado);
                }
            }
        }
        if(arv->direita->esquerda == NULL){
            *num = resultado;
            return resultado;
        } else {
            conta(arv->direita, num);
            return resultado;
        }
    }
    return 0;
}
//variável global devido a recursividade
int indice = -1;
//função para criação da árvore binária
PArvore arvrinha(char palavra[], int N){ 

    /*
        vai até o último índice da string,
        pega o sinal e o coloca como raiz.
        a partir daí vai até a direita até que acabe a string
        e depois volta ao sinal à esquerda mais próximo
        para então fazer o mesmo processo de pegar todos os dígitos
        de números até o sinal à direita.
    */

    int i, j = 0, z;

    char string[MAXTAM], aux[MAXTAM];
    memset(string, 0, sizeof(string));        
    memset(aux, 0, sizeof(aux));

    if(indice == -1){
        indice = N - 1;
    }
    z = indice;
     
    while(isdigit(palavra[indice])){
        
        if(indice == 0){

            i = indice;

            while(i != z + 1){

                string[j] = palavra[i];
                j++;
                i++;

            }

            PArvore arv = criar(string, NULL, NULL);
            return arv;
        }

        indice--;
        aux[0] = palavra[indice];
    }

    i = indice + 1;
    

    while(i != z+1){

        string[j] = palavra[i];
        j++;
        i++;

    }
    //descomente se quiser ter informações mais detalhadas
    //printf("z= %d i= %d indice= %d string= %s\n", z,i,indice,string);
    
    //dado o fato de que já se pega o sinal e o número na mesma chamada de função
    //cria-se o nó com a raiz e o número à sua esquerda de uma vez
    PArvore arv = criar(aux, criar(string, NULL, NULL), NULL);

    arv->direita = arvrinha(palavra, indice--);
    
    return arv;
}

//função usada para limpar o buffer do teclado
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}


int main(){

    int valida = 0, j = 0, result;
    char equa[MAXTAM], equaF[MAXTAM], anterior = '3';

    PArvore tree;
    
    while(valida != 1){

        valida = 0;
        j = 0;

        //Inicializando as strings com \0 para checar se está vazia  
        memset(equa, 0, sizeof(equa));
        memset(equaF, 0, sizeof(equaF));   

        printf("Digite a expressao matematica de soma ou subtracao: ");
        scanf("%[^\n]s", equa);
        flush();

        //Retirando os espaços da string
        for(int i = 0; i < strlen(equa); i++){  

            if(equa[i] != ' '){

                if( !isdigit(equa[i]) && !isdigit(anterior) ){

                    printf("\nERRO NOS OPERADORES!\n");
                    valida = -1;
                    
                }

                equaF[j] = equa[i];
                anterior = equa[i];
                j++; 
                
            //Checando erro de número espaço número
            } else if((isdigit(equa[i+1]) != 0) && (isdigit(anterior) != 0)){

                printf("\nERRO, INSIRA NUMEROS SEM ESPACOS NO MEIO!\n");
                valida = -1;

            } 
        }
        
        //checando se a string está vazia
        if(strcmp(equaF, "") == 0){

            printf("\nERRO, STRING VAZIA!\n");
            valida = -1;

        }

        //se está tudo certo, continue
        if(valida != -1){
            
            //tree recebe a árvore binária
            tree = arvrinha(equaF, strlen(equaF));
            printf("\n\n");
            printf("\n\n");
            printf("A arvore binaria eh: \n\n");

            //imprimindo a árvore a partir da altura 0
            imprimirArvore(tree, 0);
            indice = -1;
            
            //fazendo a operação e usando uma variável para receber o resultado
            conta(tree, &result);
            printf("\nO resultado da expressao eh: %d\n", result);

            //liberando o espaço de memória alocado
            liberar(tree); 
            valida = 1;

        }
        
    }

    return 0;
}