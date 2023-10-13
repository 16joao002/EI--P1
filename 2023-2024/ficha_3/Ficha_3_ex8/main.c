#include <stdio.h>

int main()
{
    int numero, soma = 0, digito;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
    {
        printf("Por favor, digite um número inteiro positivo.\n");
    }
    else
    {
        while (numero > 0)
        {
            digito = numero % 10;
            soma += digito;
            numero /= 10;
        }
    }

    printf("A soma dos digitos e: %d\n", soma);
    return 0;
}
