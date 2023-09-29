#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    char ordem;
    printf("Introduza tres numeros inteiros\n");
    printf("Primeiro numero:");
    scanf("%d", &num1);
    printf("\nSegundo numero:");
    scanf("%d", &num2);
    printf("\nTerceiro numero:");
    scanf("%d", &num3);
    printf("\nQual a ordem que os deseja ver (C)rescente ou (D)ecrescente:");
    scanf(" %c", &ordem);

    switch(ordem)
    {
        case 'C':
    case 'c':
        printf("\nValores em ordem crescente:\n");
        if (num1 <= num2 && num1 <= num3)
        {
            printf("%d ", num1);
            if (num2 <= num3)
            {
                printf("%d %d\n", num2, num3);
            }
            else
            {
                printf("%d %d\n", num3, num2);
            }
        }
        else if (num2 <= num1 && num2 <= num3)
        {
            printf("%d ", num2);
            if (num1 <= num3)
            {
                printf("%d %d\n", num1, num3);
            }
            else
            {
                printf("%d %d\n", num3, num1);
            }
        }
        else
        {
            printf("%d ", num3);
            if (num1 <= num2)
            {
                printf("%d %d\n", num1, num2);
            }
            else
            {
                printf("%d %d\n", num2, num1);
            }
        }
        break;

    case 'D':
    case 'd':
        printf("\nValores em ordem decrescente:\n");
        if (num1 >= num2 && num1 >= num3)
        {
            printf("%d ", num1);
            if (num2 >= num3)
            {
                printf("%d %d\n", num2, num3);
            }
            else
            {
                printf("%d %d\n", num3, num2);
            }
        }
        else if (num2 >= num1 && num2 >= num3)
        {
            printf("%d ", num2);
            if (num1 >= num3)
            {
                printf("%d %d\n", num1, num3);
            }
            else
            {
                printf("%d %d\n", num3, num1);
            }
        }
        else
        {
            printf("%d ", num3);
            if (num1 >= num2)
            {
                printf("%d %d\n", num1, num2);
            }
            else
            {
                printf("%d %d\n", num2, num1);
            }
        }
        break;

        default:
            printf("ERRO - Ordem incorreta!");
            break;
    }
    return 0;
}
