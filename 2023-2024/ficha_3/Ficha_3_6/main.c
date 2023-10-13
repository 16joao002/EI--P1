#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0, contador = 0;
    char opc = 'O';
    do
    {
        printf("**************Menu Principal**************\n\n");
        printf("Numero: %d\t\t\tOperacoes efetuadas: %d\n", num, contador);
        printf("I - Incrementar\n");
        printf("D - Decrementar\n");
        printf("Z - Zero\n");
        printf("S - Sair\n");
        printf("Opcao -> \n");
        scanf(" %c", &opc);
        contador++;
        switch(opc)
        {
        case 'I':
        case 'i':
            num++;
            break;
        case 'D':
        case 'd':
            num--;
            break;
        case 'Z':
        case 'z':
                num = 0;
            break;
        default:
            break;
        }
    }
    while(opc != 'S' && opc != 's');
    return 0;
}
