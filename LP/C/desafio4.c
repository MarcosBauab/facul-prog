#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s1[50], s2[50], subString[50], tempString[50], *sub, *teste;
    int contador = 0;
    printf("Digite uma string: ");
    gets(s1);
    printf("Digite outra string: ");
    gets(s2);

    for(int i = 0; s1[i]; i++){
        s1[i] = tolower(s1[i]);
    }  
    for(int i = 0; s2[i]; i++){
        s2[i] = tolower(s2[i]);
    } 

    int tam1 = strlen(s1);
    int tam2 = strlen(s2);

    if (tam1 > tam2){
        strcpy(subString, s2);
        strcpy(tempString, s1);
    } else {
        strcpy(subString, s1);
        strcpy(tempString, s2);
    }

    sub = strtok(tempString, " ");
    
    while (sub != NULL){
        teste = strstr(subString, sub);
        if (teste){
            contador++;
        }
        sub = strtok(NULL, " ");
    }

    printf("%i", contador);

    getch();
    return 0;
}