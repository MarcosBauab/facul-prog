/* 
    Marcos Vinicius Gasparoto Bauab
    RA: 156.717
    Turma: IB
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
//Estrutura padrão para registros no arquivo carros.txt
struct Veiculo{
    char marca[15];
    char modelo[25];
    int anoFab;
    char placa[6];
    int quilometragem;
    int numPortas;
    char arCondicionado;
};
//É usado somente para quando os dados forem buscados no arquivo carros.txt para serem alterados
struct VeiculoAlterado{
    char marca[TAM];
    char modelo[TAM];
    char anoFab[TAM];
    char placa[TAM];
    char quilometragem[TAM];
    char numPortas[TAM];
    char arCondicionado[TAM];
};
    
void cadastrar(struct Veiculo *carro){
    FILE *cars;
    cars = fopen("carros.txt","r");
    if(cars == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return;
    }
    fclose(cars);
    cars = fopen("carros.txt","a");
    

    printf("Qual a placa do seu carro ?\n");
    scanf("%s", &carro->placa);
    printf("Qual a marca do seu carro ?\n");
    scanf("%s", &carro->marca);
    printf("Qual o modelo do seu carro ?\n");
    scanf("%s", &carro->modelo);
    printf("Qual o ano de fabricacao do seu carro ?\n");
    scanf("%d", &carro->anoFab);
    printf("Qual a quilometragem do seu carro ?\n");
    scanf("%d", &carro->quilometragem);
    printf("Qual o numero de portas do seu carro ?\n");
    scanf("%d", &carro->numPortas);
    printf("Seu carro tem ar-condicionado (S/N) ?\n");
    scanf("%s", &carro->arCondicionado);

    fprintf(cars,"Placa: %s\n",carro->placa);
    fprintf(cars,"Marca: %s\n",carro->marca);
    fprintf(cars,"Modelo: %s\n",carro->modelo);
    fprintf(cars,"Ano de fabricacao: %d\n",carro->anoFab);
    fprintf(cars,"Quilometragem: %d\n",carro->quilometragem);
    fprintf(cars,"Numero de portas: %d\n",carro->numPortas);
    fprintf(cars,"Ar-condicionado: %c\n",carro->arCondicionado);

    fclose(cars);
}

void alterar(struct VeiculoAlterado *carro2){
    FILE *cars;
    cars = fopen("carros.txt","r");
    if(cars == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return;
    } 

    char placa[6];

    printf("Qual a placa do veiculo a ser alterado ? ");
    scanf("%s", &placa);

    char frase[20] = "Placa: ";
    strcat(frase, placa);
    
    int c, registrado = 0, numLinha = 1;
    char buf[TAM];

    while(fgets(&carro2->placa, TAM, cars) != NULL){
        carro2->placa[strcspn(carro2->placa,"\n")] = 0;
        if(strcmp(carro2->placa, frase) == 0){
            registrado = 1;
            printf("%s\n", carro2->placa);
            for (c = 0; c < 6; c++)
            {
                switch(c){
                    case 0:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->marca, &buf[7], 15);
                        printf("Marca: %s",carro2->marca);
                        carro2->marca[strcspn(carro2->marca,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                    case 1:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->modelo, &buf[8], 25);
                        printf("Modelo: %s",carro2->modelo);
                        carro2->modelo[strcspn(carro2->modelo,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                    case 2:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->anoFab, &buf[19], 25);
                        printf("Ano de fabricacao: %s",carro2->anoFab);
                        carro2->anoFab[strcspn(carro2->anoFab,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                    case 3:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->quilometragem, &buf[15], 15);
                        printf("Quilometragem: %s",carro2->quilometragem);
                        carro2->quilometragem[strcspn(carro2->quilometragem,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                    case 4:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->numPortas, &buf[18], 15);
                        printf("Numero de portas: %s",carro2->numPortas);
                        carro2->numPortas[strcspn(carro2->numPortas,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                    case 5:
                        fgets(buf, TAM, cars);
                        memcpy(carro2->arCondicionado, &buf[17], 3);
                        printf("Ar-condicionado: %s",carro2->arCondicionado);
                        carro2->arCondicionado[strcspn(carro2->marca,"\n")] = 0;
                        memset(buf, 0, TAM);
                        break;
                } 
            }
            break; 
        } else{
            numLinha++;
        }
    }

    if(registrado == 0){
        printf("Veiculo nao encontrado, voltando ao menu inicial...\n");
    } else {
        rewind(cars);
        FILE *temporario = fopen("temporario.tmp","w");
        int escolha;

        char letra;
        int linhaDeletar = 1;
        letra = getc(cars);
        while(letra != EOF){
            if(linhaDeletar != numLinha && linhaDeletar != numLinha + 1 && linhaDeletar != numLinha + 2 && linhaDeletar != numLinha + 3 && linhaDeletar != numLinha + 4 && linhaDeletar != numLinha + 5 && linhaDeletar != numLinha + 6){
                putc(letra, temporario);  
            } 
            if(letra == '\n'){
                linhaDeletar++;
            }
            letra = getc(cars);
        }

        while(escolha != 7){
            switch(escolha){
                case 1:
                    printf("Insira a nova marca:\n");
                    scanf("%s", &carro2->marca);
                    break;
                case 2:
                    printf("Insira o novo modelo:\n");
                    scanf("%s", &carro2->modelo);
                    break;
                case 3:
                    printf("Insira o novo ano de fabricacao:\n");
                    scanf("%s", &carro2->anoFab);
                    break;
                case 4:
                    printf("Insira a nova quilometragem:\n");
                    scanf("%s", &carro2->quilometragem);
                    break;
                case 5:
                    printf("Insira a nova quantidade de portas:\n");
                    scanf("%s", &carro2->numPortas);
                    break;
                case 6:
                    printf("Insira o estado do ar-condicionado (S/N):\n");
                    scanf("%s", &carro2->arCondicionado);
                    break;
                default:
                    break;
            }
            printf("Escolha uma das opcoes para alterar: \n");
            printf("1) Marca\n");
            printf("2) Modelo\n");
            printf("3) Ano de fabricacao\n");
            printf("4) Quilometragem\n");
            printf("5) Numero de portas\n");
            printf("6) Ar-condicionado\n");
            printf("7) Fim das alteracoes\n");
            scanf("%d", &escolha);
        }

        fprintf(temporario,"%s\n",carro2->placa);
        fprintf(temporario,"Marca: %s\n",carro2->marca);
        fprintf(temporario,"Modelo: %s\n",carro2->modelo);
        fprintf(temporario,"Ano de fabricacao: %s\n",carro2->anoFab);
        fprintf(temporario,"Quilometragem: %s\n",carro2->quilometragem);
        fprintf(temporario,"Numero de portas: %s\n",carro2->numPortas);
        fprintf(temporario,"Ar-condicionado: %s",carro2->arCondicionado);

        fclose(cars);
        fclose(temporario);
        remove("carros.txt");
        rename("temporario.tmp", "carros.txt");
    }
}

void mostrar(){
    FILE *cars;
    cars = fopen("carros.txt","r");
    if(cars == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return;
    } 

    char linha[TAM], placa[6];

    printf("Qual a placa do seu veiculo ? ");
    scanf("%s", &placa);

    char frase[20] = "Placa: ";
    strcat(frase, placa);
    
    int c, registrado = 0;
    

    while(fgets(&linha, TAM, cars) != NULL){
        linha[strcspn(linha,"\n")] = 0;
        if(strcmp(linha, frase) == 0){
            registrado = 1;
            printf("%s\n", linha);
            for (c = 0; c < 6; c++)
            {
                fgets(&linha, TAM, cars);
                printf("%s", linha);
            }
            break; 
        } 
    }
    if(registrado == 0){
        printf("Veiculo nao encontrado, voltando ao menu inicial...\n");
    }
    fclose(cars);
}

void excluir(){
    FILE *cars;
    cars = fopen("carros.txt","r");
    if(cars == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO\n");
        return;
    } 

    char linha[TAM], placa[6];

    printf("Qual a placa do veiculo a ser excluido ? ");
    scanf("%s", &placa);

    char frase[20] = "Placa: ";
    strcat(frase, placa);
    
    int numLinha = 1, registrado = 0;
    

    while(fgets(&linha, TAM, cars) != NULL){
        linha[strcspn(linha,"\n")] = 0;
        if(strcmp(linha, frase) == 0){
            registrado = 1;
            break; 
        } else{
            numLinha++;
        } 
    }
    if(registrado == 0){
        printf("Veiculo nao encontrado, voltando ao menu inicial...\n");
    } else{
        rewind(cars);
        FILE *temporario = fopen("temporario.tmp","w");
        int escolha;

        char letra;
        int linhaDeletar = 1;
        letra = getc(cars);
        while(letra != EOF){
            if(linhaDeletar != numLinha && linhaDeletar != numLinha + 1 && linhaDeletar != numLinha + 2 && linhaDeletar != numLinha + 3 && linhaDeletar != numLinha + 4 && linhaDeletar != numLinha + 5 && linhaDeletar != numLinha + 6){
                putc(letra, temporario);  
            } 
            if(letra == '\n'){
                linhaDeletar++;
            }
            letra = getc(cars);
        }

        printf("Veiculo excluido, voltando ao menu principal...");

        fclose(cars);
        fclose(temporario);
        remove("carros.txt");
        rename("temporario.tmp", "carros.txt");
    }
    
    
}

void main(){
    typedef struct Veiculo *pontVeiculo;
    //carro é um ponteiro da struct Veiculo
    pontVeiculo carro;

    typedef struct VeiculoAlterado *pontVeiculoAlterado;
    //carro2 é um ponteiro da struct VeiculoAlterado
    pontVeiculoAlterado carro2;
    
    int opt;

    while (opt != 5){
        switch (opt){
            case 1:
                //aloco a quantidade de espaços necessários na memória
                carro = (struct Veiculo *)malloc(sizeof(struct Veiculo));
                cadastrar(carro);
                //libero os espaços da memória
                free(carro);
                break;
            case 2:
                carro2 = (struct VeiculoAlterado *)malloc(sizeof(struct VeiculoAlterado));
                alterar(carro2);
                free(carro2);
                break;
            case 3:
                mostrar();
                break;
            case 4:
                excluir();
                break;
            default:
                break;
        }
        printf("\n\n1) Inserir novo cadastro de veiculo\n");
        printf("2) Alterar cadastro\n");
        printf("3) Mostrar os dados de um veiculo\n");
        printf("4) Apagar registro\n");
        printf("5) Sair\n");
        scanf("%d", &opt);
    }
    
}


