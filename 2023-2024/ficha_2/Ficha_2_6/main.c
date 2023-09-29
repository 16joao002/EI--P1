#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, resultado;
    char opcao;
    printf("Introduza um numero inteiro:\n");
    scanf("%d", &num1);
    printf("Introduza um novo numero inteiro:\n");
    scanf("%d", &num2);
    printf("Introduza a operacao que pretende realizar:\n");
    scanf(" %c", &opcao);

    switch(opcao)
    {
        case '+':
            resultado = num1+num2;
            printf("Resultado: %d", resultado);
        break;

        case '-':
            resultado = num1-num2;
            printf("Resultado: %d", resultado);
        break;

        case '*':
            resultado = num1*num2;
            printf("Resultado: %d", resultado);
        break;

        case '/':
            if(num2 == 0)
            {
                printf("ERRO - Divisao por zero");
                break;
            }
            resultado = num1/num2;
            printf("Resultado: %d", resultado);
        break;

        case '%':
            resultado = num1%num2;
            printf("Resultado: %d", resultado);
        break;

        default:
            printf("ERRO - Operador desconhecido");
            break;
    }
    return 0;
}
