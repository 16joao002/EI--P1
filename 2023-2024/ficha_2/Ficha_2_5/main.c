#include <stdio.h>
#include <stdlib.h>

int main()
{
    float compras, desconto, valorFinal;
    printf("Digite o valor das compras efetuadas:\n");
    scanf("%f", &compras);

    if(compras <= 500)
    {
        printf("Nao tem custo suficiente para receber desconto.\n");
    }
    else
    {
        if(compras > 500 && compras <= 1250)
        {
            desconto = compras * 0.04;
            valorFinal = compras - desconto;
            printf("Obteve:%.2f\nE so vai ter que pagar %.2f.\n",desconto, valorFinal);
        }
        else
        {
            if(compras > 1250 && compras <= 2000)
            {
                desconto = compras * 0.06;
                valorFinal = compras - desconto;
                printf("Obteve:%.2f\nE so vai ter que pagar %.2f.\n",desconto, valorFinal);
            }
            else
            {
                if(compras > 2000)
                {
                    desconto = compras * 0.08;
                    valorFinal = compras - desconto;
                    printf("Obteve:%.2f\nE so vai ter que pagar %.2f.\n",desconto, valorFinal);
                }
            }
        }
    }
    return 0;
}
