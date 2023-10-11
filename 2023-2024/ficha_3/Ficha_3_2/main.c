#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, numWhile, numDoWhile, numFor, somaWhile = 0, somaDoWhile = 0, somaFor = 0, contadorWhile = 0, contadorDoWhile = 0, contadorFor = 0;
    char opc;
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
        do
        {
            printf("Introduza o ciclo que pretende utilizar:\n");
            printf("(w) ciclo While\n");
            printf("(d) ciclo do...While\n");
            printf("(f) ciclo For\n");
            printf("(s) sair\n");
            printf("opcao ->");
            scanf(" %c", &opc);
            switch(opc)
            {

            case 'W':
            case 'w':
                while(numWhile > 0)
                {
                    contadorWhile++;
                    somaWhile += numWhile;
                    numWhile--;
                }
                printf("Resultado(Ciclo While):%d\n",somaWhile);
                break;
            case 'D':
            case 'd':
                do
                {
                    contadorDoWhile++;
                    somaDoWhile += numDoWhile;
                    numDoWhile--;
                }
                while(numDoWhile > 0);
                printf("Resultado(Ciclo DoWhile):%d\n",somaDoWhile);
                break;
            case 'F':
            case 'f':
                for(int i=0; i <= numFor; i++)
                {
                    contadorFor++;
                    somaFor += i;
                }
                printf("Resultado(Ciclo For):%d\n",somaFor);
                break;
            }
        }
        while(opc != 'S' && opc != 's');

        printf("While foi utilizado %d vezes.\n", contadorWhile);
        printf("DoWhile foi utilizado %d vezes.\n", contadorDoWhile);
        printf("For foi utilizado %d vezes.\n", contadorFor);
    }
    return 0;
}
