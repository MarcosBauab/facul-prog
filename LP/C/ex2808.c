#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char entrada[21], *primeiro, *segundo;
    int x, y;
    gets(entrada);
    
    primeiro = strtok(entrada, " ");
    segundo = strtok(NULL, " ");

    switch (primeiro[0]){
        case 'a':
            x = 1;
            break;
        case 'b':
            x = 2;
            break;

        case 'c':
            x = 3;
            break;

        case 'd':
            x = 4;
            break;

        case 'e':
            x = 5;
            break;

        case 'f':
            x = 6;
            break;

        case 'g':
            x = 7;
            break;

        case 'h':
            x = 8;
            break;

        default:
            break;
    }
    switch (segundo[0]){
        case 'a':
            y = 1;
            break;

        case 'b':
            y = 2;
            break;

        case 'c':
            y = 3;
            break;

        case 'd':
            y = 4;
            break;

        case 'e':
            y = 5;
            break;

        case 'f':
            y = 6;
            break;

        case 'g':
            y = 7;
            break;
        case 'h':
            y = 8;
            break;
        default:
            break;
    }
    int sub = (y - x);
    int sub3 = primeiro[1] - segundo[1];
    if ((sub == 1 || sub == -1) && (sub3 == 2 || sub3 == -2)){
        printf("VALIDO\n");
    }else {
        if ((sub == 2 || sub == -2) && (sub3 == 1 || sub3 == -1)){
            printf("VALIDO\n");
        } else{
            printf("INVALIDO\n");
        }
    }
    

}


