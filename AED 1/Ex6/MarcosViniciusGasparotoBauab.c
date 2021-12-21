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

typedef struct lista {
    int coef, exp;
    struct lista* ant;
    struct lista* prox;
}Lista;
typedef Lista *PLista;
//Inserir ordenado
PLista inserir(PLista l, int c, int e) {  
    PLista aux;
    PLista novo = (PLista) malloc(sizeof(Lista));
    novo->coef = c;
    novo->exp = e;
    //Se já tiver algum elemento
    if (l != NULL){ 
        aux = l;
        if(aux->prox != NULL){ //tem mais de um elemento
            while(aux != NULL){
                if(aux->exp > e){ 
                    if(aux->prox != NULL)
                        aux = aux->prox;
                    else {
                        aux->prox = novo;
                        novo->ant = aux;
                        novo->prox = NULL;
                        aux = NULL;
                    }
                } else { 
                    novo->prox = aux; 
                    novo->ant = aux->ant;
                    if(aux->ant != NULL) 
                        aux->ant->prox = novo;
                    else {
                        novo->ant = NULL; 
                        l = novo;
                    }
                    aux->ant = novo;
                    break;
                }
            }
        } else { // só um elemento
            if(l->exp > novo->exp){
                novo->prox = l->prox;
                l->prox = novo;
                novo->ant = l;
            } else {
                novo->prox = l;
                novo->ant = NULL;
                l->ant = novo;
                l = novo;
            }
        }           
    } else {
        novo->prox = NULL;
        novo->ant = NULL;
        l = novo;
    }
    return l;
}
//Imprimir a lista - usada para testes
void imprimir(PLista inicial){
    if (inicial == NULL){
        return;
    }
    printf("[%d, ", inicial->coef);
    printf("%d] ", inicial->exp);
    imprimir(inicial->prox);
}
//Formatar para achar o coeficiente e o expoente
PLista formatar(char string[MAXTAM], PLista lista){ 
    int i, j = 0,z = 1, sub;
    char recebe[MAXTAM], expoente[10], nova[MAXTAM], anterior;
    //Zerando as strings e inicializando elas
    memset(recebe,0,sizeof(recebe));
    memset(expoente,0,sizeof(expoente));
    memset(nova,0,sizeof(nova));
    //Retirando os espaços da string
    for(i = 0; i < strlen(string); i++){
        if(string[i] != ' '){
            nova[j] = string[i];
            anterior = string[i];
            j++; 
            //Checando erro de número espaço número
        } else if((isdigit(string[i+1])!= 0) && (isdigit(anterior)!= 0)){
            printf("\nERRO, INSIRA NUMEROS SEM ESPACOS NO MEIO!\n");
            return NULL;
        }
    }
    j=0;
    //Checando caractere por caractere
    for(i = 0; i < strlen(nova); i++){ 
        if(nova[i] == 'x'){
            //Vendo se o x está sem coeficiente
            if(strlen(recebe) == 1 && recebe[0] == '-'){
                strcpy(recebe, "-1");
            } else if(strlen(recebe) == 0){
                strcpy(recebe, "1");
            }
            //Checando se tem expoente
            if(nova[i+1] == '^'){ 
                i = i+1;
                sub = strlen(nova) - i;
                //Pegando um expoente com mais de um número
                while(z <= sub){
                    if(nova[i+z] == '+' || nova[i+z] == '-'){
                        break;
                    }
                    expoente[z-1] = nova[i+z];
                    z++;
                }
                i = i+z-1;
                z = 0;
                              
                lista = inserir(lista, atoi(recebe), atoi(expoente));
                memset(recebe,0,sizeof(recebe));
                memset(expoente,0,sizeof(expoente));
                j = 0;
            } else {  
                lista = inserir(lista, atoi(recebe), 1);
                memset(recebe,0,sizeof(recebe));
                j = 0;
            }
            //Adicionando os números em "recebe"
        } else if(nova[i] != '+'){
			recebe[j] = nova[i];
            j++;
            //Pegando os números até atingir um caractere especial
            while(nova[i+1] != '+' && nova[i+1] != '-' && nova[i+1] != '\0' && nova[i+1] != 'x'){
                i++;
                recebe[j] = nova[i];
                j++;
            }
            //Se atingir o final e o número estiver sem x
            if(nova[i+1] == '\0' || nova[i+1] == '+' || nova[i+1] == '-'){
                recebe[j] = '\0';
                lista = inserir(lista, atoi(recebe), 0);
                j = 0;
                memset(recebe,0,sizeof(recebe));
            }
        } 
    }
    return lista;
}
//Limpar o buffer do teclado
void flush(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
//Fazer a soma de duas listas
void soma(PLista lista1, PLista lista2){
    PLista aux1, aux2, maior;
    aux1 = lista1;
    aux2 = lista2;
    int soma = 0, tam1 = 0, tam2 = 0;
    //Calcular o tamanho das listas
    while(aux1 != NULL){
        tam1++;
        aux1 = aux1->prox;
    } 
    while(aux2 != NULL){
        tam2++;
        aux2 = aux2->prox;
    } 

    aux1 = lista1;
    aux2 = lista2; 

    //Comparar o tamanho das listas
    if(tam1 > tam2){
        maior = aux1;
    } else {
        maior = aux2;
    }
    printf("\nResultado da soma: ");
    //Rodar até o polinômio de maior grau
    while(maior != NULL){ 

        //Levar ele até o lugar certo no código se um deles acabar primeiro
        if(aux1 == NULL){
            goto VIM2;
        } else if(aux2 == NULL){
            goto VIM1;
        }
        //Comparando para fazer a operação ou não
        if(aux1->exp == aux2->exp){
            soma = aux1->coef + aux2->coef;
            switch (aux1->exp){
                case 0:
                    if(soma > 0){
                        printf("+%d",soma);
                    } else if(soma != 0){
                        printf("%d",soma);
                    }
                    break;
                case 1:
                    if(soma > 0){
                        printf("+%dx",soma);
                    } else if(soma != 0){
                        printf("%dx",soma);
                    }
                    break;
                default:
                    if(soma > 0){
                        printf("+%dx^%d",soma, aux1->exp);
                    } else if(soma != 0){
                        printf("%dx^%d",soma, aux1->exp);
                    }
                    break;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            if(tam1 > tam2){
                maior = aux1;
            } else {
                maior = aux2;
            }
        } else if(aux1->exp != aux2->exp){
            if(aux1->exp > aux2->exp){
                VIM1: switch (aux1->exp){
                    case 0:
                        if(aux1->coef > 0){
                            printf("+%d",aux1->coef);
                        } else if(aux1->coef != 0) {
                            printf("%d",aux1->coef);
                        }
                        break;
                    case 1:
                        if(aux1->coef > 0){
                            printf("+%dx",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%dx",aux1->coef);
                        }
                        break;
                    default:
                        if(aux1->coef > 0){
                            printf("+%dx^%d",aux1->coef, aux1->exp);
                        } else if(aux1->coef != 0){
                            printf("%dx^%d",aux1->coef, aux1->exp);
                        }
                        break;
                    }
                aux1 = aux1->prox;
                maior = aux1;
            } else if(aux2->exp > aux1->exp){
                VIM2: switch (aux2->exp){
                case 0:
                    if(aux2->coef > 0){
                        printf("+%d",aux2->coef);
                    } else if(aux2->coef != 0){
                        printf("%d",aux2->coef);
                    }
                    break;
                case 1:
                    if(aux2->coef > 0){
                        printf("+%dx",aux2->coef);
                    } else if(aux2->coef != 0){
                        printf("%dx",aux2->coef);
                    }
                    break;
                default:
                    if(aux2->coef > 0){
                        printf("+%dx^%d",aux2->coef, aux2->exp);
                    } else if(aux2->coef != 0){
                        printf("%dx^%d",aux2->coef, aux2->exp);
                    }
                    break;
                }   
                aux2 = aux2->prox;
                maior = aux2; 
            }
        } 
        //Checando para listas de tamanho diferente
        if(maior == NULL && aux1 == NULL && aux2 != NULL){
            while(aux2 != NULL){
                switch (aux2->exp){
                    case 0:
                        if(aux2->coef > 0){
                            printf("+%d",aux2->coef);
                        } else if(aux2->coef != 0){
                            printf("%d",aux2->coef);
                        }
                        break;
                    case 1:
                        if(aux2->coef > 0){
                            printf("+%dx",aux2->coef);
                        } else if(aux2->coef != 0){
                            printf("%dx",aux2->coef);
                        }
                        break;
                    default:
                        if(aux2->coef > 0){
                            printf("+%dx^%d",aux2->coef, aux2->exp);
                        } else if(aux2->coef != 0){
                            printf("%dx^%d",aux2->coef, aux2->exp);
                        }
                        break;
                    }   
                aux2 = aux2->prox;
            }
        } else if(maior == NULL && aux1 != NULL && aux2 == NULL){
            while(aux1 != NULL){
                switch (aux1->exp){
                    case 0:
                        if(aux1->coef > 0){
                            printf("+%d",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%d",aux1->coef);
                        }
                        break;
                    case 1:
                        if(aux1->coef > 0){
                            printf("+%dx",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%dx",aux1->coef);
                        }
                        break;
                    default:
                        if(aux1->coef > 0){
                            printf("+%dx^%d",aux1->coef, aux1->exp);
                        } else if(aux1->coef != 0){
                            printf("%dx^%d",aux1->coef, aux1->exp);
                        }
                        break;
                    }   
                aux1 = aux1->prox;
            }
        }

    } //A função sub é muito semelhante
}
//Fazer a subtração de duas listas
void sub(PLista lista1, PLista lista2){
    PLista aux1, aux2, maior;
    aux1 = lista1;
    aux2 = lista2;
    int soma = 0, tam1 = 0, tam2 = 0;

    while(aux1 != NULL){
        tam1++;
        aux1 = aux1->prox;
    } 
    while(aux2 != NULL){
        tam2++;
        aux2 = aux2->prox;
    } 

    aux1 = lista1;
    aux2 = lista2;

    if(tam1 > tam2){
        maior = aux1;
    } else {
        maior = aux2;
    }
    printf("\nResultado da subtracao: ");
    while(maior != NULL){ 

        if(aux1 == NULL){
            goto VIM2;
        } else if(aux2 == NULL){
            goto VIM1;
        }

        if(aux1->exp == aux2->exp){
            soma = aux1->coef - aux2->coef;
            switch (aux1->exp){
                case 0:
                    if(soma > 0){
                        printf("+%d",soma);
                    } else if(soma != 0){
                        printf("%d",soma);
                    }
                    break;
                case 1:
                    if(soma > 0){
                        printf("+%dx",soma);
                    } else if(soma != 0){
                        printf("%dx",soma);
                    }
                    break;
                default:
                    if(soma > 0){
                        printf("+%dx^%d",soma, aux1->exp);
                    } else if(soma != 0){
                        printf("%dx^%d",soma, aux1->exp);
                    }
                    break;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
            if(tam1 > tam2){
                maior = aux1;
            } else {
                maior = aux2;
            }
        } else if(aux1->exp != aux2->exp){
            if(aux1->exp > aux2->exp){
                VIM1: switch (aux1->exp){
                    case 0:
                        if(aux1->coef > 0){
                            printf("+%d",aux1->coef);
                        } else if(aux1->coef != 0) {
                            printf("%d",aux1->coef);
                        }
                        break;
                    case 1:
                        if(aux1->coef > 0){
                            printf("+%dx",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%dx",aux1->coef);
                        }
                        break;
                    default:
                        if(aux1->coef > 0){
                            printf("+%dx^%d",aux1->coef, aux1->exp);
                        } else if(aux1->coef != 0){
                            printf("%dx^%d",aux1->coef, aux1->exp);
                        }
                        break;
                    }
                aux1 = aux1->prox;
                maior = aux1;
            } else if(aux2->exp > aux1->exp){
                VIM2: switch (aux2->exp){
                case 0:
                    if(aux2->coef > 0){
                        printf("-%d",aux2->coef);
                    } else if(aux2->coef != 0){
                        printf("+%d",aux2->coef * -1);
                    }
                    break;
                case 1:
                    if(aux2->coef > 0){
                        printf("-%dx",aux2->coef);
                    } else if(aux2->coef != 0){
                        printf("+%dx",aux2->coef * -1);
                    }
                    break;
                default:
                    if(aux2->coef > 0){
                        printf("-%dx^%d",aux2->coef, aux2->exp);
                    } else if(aux2->coef != 0){
                        printf("+%dx^%d",aux2->coef * -1, aux2->exp);
                    }
                    break;
                }   
                aux2 = aux2->prox;
                maior = aux2; 
            }
        } 

        if(maior == NULL && aux1 == NULL && aux2 != NULL){
            while(aux2 != NULL){
                switch (aux2->exp){
                    case 0:
                        if(aux2->coef > 0){
                            printf("-%d",aux2->coef);
                        } else if(aux2->coef != 0){
                            printf("+%d",aux2->coef * -1);
                        }
                        break;
                    case 1:
                        if(aux2->coef > 0){
                            printf("-%dx",aux2->coef);
                        } else if(aux2->coef != 0){
                            printf("+%dx",aux2->coef * -1);
                        }
                        break;
                    default:
                        if(aux2->coef > 0){
                            printf("-%dx^%d",aux2->coef, aux2->exp);
                        } else if(aux2->coef != 0){
                            printf("+%dx^%d",aux2->coef * -1, aux2->exp);
                        }
                        break;
                    }   
                aux2 = aux2->prox;
            }
        } else if(maior == NULL && aux1 != NULL && aux2 == NULL){
            while(aux1 != NULL){
                switch (aux1->exp){
                    case 0:
                        if(aux1->coef > 0){
                            printf("+%d",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%d",aux1->coef);
                        }
                        break;
                    case 1:
                        if(aux1->coef > 0){
                            printf("+%dx",aux1->coef);
                        } else if(aux1->coef != 0){
                            printf("%dx",aux1->coef);
                        }
                        break;
                    default:
                        if(aux1->coef > 0){
                            printf("+%dx^%d",aux1->coef, aux1->exp);
                        } else if(aux1->coef != 0){
                            printf("%dx^%d",aux1->coef, aux1->exp);
                        }
                        break;
                    }   
                aux1 = aux1->prox;
            }
        }
    }
}
//Retirar o zero, se for o caso, da lista
PLista comparar(PLista lista){
    PLista aux, aux2;
    aux = lista;
    //Rodando toda a lista e retirando os zeros
    while(aux != NULL){
        if(aux->coef == 0){
            if(aux->prox == NULL){
                aux->ant->prox = aux->prox;
            } else if(aux->ant == NULL) {
                aux->prox->ant = aux->ant;
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            free(aux);
        }
        if(aux->prox == NULL){
            aux2 = aux;
        }  
        aux = aux->prox;
    }
    //Voltando ao início da lista
    while(aux2->ant != NULL){
        aux2 = aux2->ant;
    }

    return aux2;
}
//Calcular a derivada
void derivada(PLista lista){
    PLista aux;
    aux = lista;
    printf("\nResultado da derivada: ");
    //Rodando a lista e utilizando a regra do tombo
    while(aux != NULL){
        aux->coef = aux->coef * aux->exp;
        aux->exp = aux->exp - 1;
        switch (aux->exp){
            case 0:
                printf("%d", aux->coef);
                break;
            case 1:
                if(aux->coef > 0){
                    printf("+%dx",aux->coef);
                } else if(aux->exp != 0){
                    printf("%dx",aux->coef);
                }
                break;
            default:
                if(aux->coef > 0){
                    printf("+%dx^%d",aux->coef, aux->exp);
                } else if(aux->coef != 0){
                    printf("%dx^%d",aux->coef, aux->exp);
                }
                break;
        }
        aux = aux->prox;
    }

    
}
//Liberar as listas
PLista liberar(PLista lista){
    if(lista != NULL){
	    liberar(lista->prox);
        free(lista);
    }
    return NULL;
}

int main(){
    PLista lista1 = NULL;
    PLista lista2 = NULL;
    int opt = 0, i, deriv;
    char string[MAXTAM], string2[MAXTAM];
    //Menu
    while (opt != 5){
        //Inicializando as strings com \0 para checar se está vazia  
        memset(string,0,sizeof(string));
        memset(string2,0,sizeof(string2));
        switch (opt){
            case 1:
                lista1 = liberar(lista1);
                lista2 = liberar(lista2);
                printf("Digite seu primeiro polinomio: ");
                scanf("%[^\n]s", string);
                flush();
                //Checando se a string está vazia
                if(string[0] == '\0' || string[0] == 0){
                    printf("\nDigite um polinomio de verdade!\n\n");
                    break;
                }
                //Formatando
                lista1 = formatar(string, lista1);
                //Checando se deu algum erro
                if(lista1 == NULL){
                    break;
                }
                //Checando se o coeficiente de maior grau tem coeficiente zero
                if(lista1->coef == 0){
                    printf("\nERRO, MONOMIO DE MAIOR GRAU COM COEFICIENTE ZERO!");
                    break;
                } 
                //Tentando achar algum zero como coeficiente para tirar
                lista1 = comparar(lista1);
                //imprimir(lista1);
                //-------------------------------------------------------
                printf("\nDigite seu segundo polinomio: ");
                scanf("%[^\n]s", string2);
                flush();
                if(string2[0] == '\0' || string2[0] == 0){
                    printf("\nDigite um polinomio de verdade!\n\n");
                    break;
                }
                //Formatando
                lista2 = formatar(string2, lista2);
                //Checando se deu algum erro
                if(lista2 == NULL){
                    break;
                } 
                //Checando se o coeficiente de maior grau tem coeficiente zero
                if(lista2->coef == 0){
                    printf("\nERRO, MONOMIO DE MAIOR GRAU COM COEFICIENTE ZERO!");
                    break;
                } 
                //Tentando achar algum zero como coeficiente para tirar
                lista2 = comparar(lista2);
                //imprimir(lista2);
                break;
            case 2:
                soma(lista1,lista2);
                break;
            case 3:
                sub(lista1,lista2);
                break;
            case 4:
                printf("Qual polinomio quer usar para derivar (1 ou 2)?: ");
                scanf("%d", &deriv);
                if(deriv == 1){
                    derivada(lista1);
                } else if(deriv == 2){
                    derivada(lista2);
                } else {
                    printf("Digite um valor correto!\n\n");
                    break;
                }
                break;
            default:
                break;
        }
        printf("\n\n1) Inserir novos polinomios\n");
        printf("2) Somar polinomios\n");
        printf("3) Subtrair polinomios\n");
        printf("4) Derivar um polinomio\n");
        printf("5) Sair\n");
        scanf("%d%*c",&opt);
    }
    //Liberando as listas
    liberar(lista1);
    liberar(lista2);
    return 0;
}