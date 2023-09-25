#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3;
    printf("Insira o primeiro numero\n");
    scanf("%d", &num1);
    printf("Insira o segundo numero\n");
    scanf("%d", &num2);
    printf("Insira o terceiro numero\n");
    scanf("%d", &num3);

    if(num1 != num2 || num1 != num3 || num2 != num3){
        printf("Os numeros sao diferentes entre si");
    }
    else{
        printf("Os numeros sao iguais entre si");
    }
    return 0;
}
