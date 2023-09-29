#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, soma = 0;
    printf("Digite um n�mero entre 1 e 10: ");
    scanf("%d", &numero);

    if (numero >= 1 && numero <= 10)
    {
        switch (numero)
        {
        case 10:
            soma += 10;
        case 9:
            soma += 9;
        case 8:
            soma += 8;
        case 7:
            soma += 7;
        case 6:
            soma += 6;
        case 5:
            soma += 5;
        case 4:
            soma += 4;
        case 3:
            soma += 3;
        case 2:
            soma += 2;
        case 1:
            soma += 1;
            break;
        default:
            break;
        }

        printf("A soma de todos os n�meros at� %d � %d.\n", numero, soma);
    }
    else
    {
        printf("N�mero fora do intervalo v�lido (1 a 10).\n");
    }
    return 0;
}
