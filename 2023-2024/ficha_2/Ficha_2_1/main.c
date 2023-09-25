#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Insira um numero: \n");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("numero Par\n");
    }
    else{
        if(num % 2 != 0){
            printf("numero Impar\n");
        }
    }

    if(num > 0){
        printf("Numero Positivo\n");
    }
    else{
        if(num < 0){
            printf("numero Negativo\n");
        }
        else{
            printf("numero Nulo\n");
        }
    }
    return 0;
}
