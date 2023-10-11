#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, numWhile, numDoWhile, numFor, somaWhile = 0, somaDoWhile = 0, somaFor = 0;
    printf("Introduza um numero inteiro positivo: \n");
    scanf("%d", &num);
    if (num < 1)
    {
        printf("ERRO - Numero nao positivo\n");
    }
    else
    {
        numDoWhile = num;
        numWhile = num;
        numFor = num;

        while(numWhile > 0)
        {
            somaWhile += numWhile;
            numWhile--;
        }
        printf("Resultado(Ciclo While):%d\n",somaWhile);

        do
        {
            somaDoWhile += numDoWhile;
            numDoWhile--;
        }while(numDoWhile > 0);
        printf("Resultado(Ciclo DoWhile):%d\n",somaDoWhile);

        for(int i=0; i <= numFor; i++)
        {
            somaFor += i;
        }
        printf("Resultado(Ciclo For):%d\n",somaFor);
    }
    return 0;
}
