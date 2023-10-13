#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, soma = 0, contador = 0, numElementos = 0;
    float media = 0, percNumPositivos = 0, percNumNegativos = 0;

    printf("Quantos numeros pretende introduzir?");
    scanf("%d", &numElementos);
    do
    {
        printf("Introduza um numero inteiro:\n");
        scanf("%d", &num);

        if (num != 0)
        {
            soma += num;
            contador++;
            media = soma/contador;

            if (num > 0)
            {
                percNumPositivos++;
            }
            else
            {
                if (num < 0)
                {
                    percNumNegativos++;
                }
            }
        }
        numElementos--;
    }
    while(numElementos != 0);

    percNumNegativos = (percNumNegativos/contador) * 100;
    percNumPositivos = (percNumPositivos/contador) * 100;

    printf("A soma total e %d.\n", soma);
    printf("A media e %.2f.\n", media);
    printf("A percentagem de numeros positivos e %.2f.\n", percNumPositivos);
    printf("A percentagem de numeros negativos e %.2f.\n", percNumNegativos);

    return 0;
}
