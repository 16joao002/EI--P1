#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, soma, sub, multi, div, resto;
    printf("Introduza o primeiro numero: ");
    scanf("%d", &num1);
    printf("\nIntroduza o segundo numero: ");
    scanf("%d", &num2);
    soma = num1 + num2;
    sub = num1 - num2;
    multi = num1 * num2;
    div = num1 / num2;
    resto = num1 % num2;
    printf("\n\nsoma\t\t %d + %d = %d", num1,num2, soma);
    printf("\nsubtracao\t %d - %d = %d", num1,num2, sub);
    printf("\nmultiplicacao    %d * %d = %d", num1,num2, multi);
    printf("\ndivisao\t\t %d / %d = %d", num1,num2, div);
    printf("\nresto da divisao inteira %d %% %d = %d", num1,num2, resto);
    return 0;
}
