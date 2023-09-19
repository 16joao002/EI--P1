#include <stdio.h>
#include <stdlib.h>

#define SAL_BASE 600
#define ACRE_CARRO 100
#define ACRE_EMPRESA 0.05

int main()
{
    int carros, mont_fat, mont_carro_vendido, mont_vendas, total;
    printf("Indique o numero de carros vendidos: ");
    scanf("%d", &carros);
    printf("\nIndique o montante faturado: ");
    scanf("%d", &mont_fat);

    mont_carro_vendido = ACRE_CARRO * carros;
    mont_vendas = ACRE_EMPRESA * mont_fat;
    total = SAL_BASE + mont_carro_vendido + mont_vendas;

    printf("\nVencimento:\n\n");
    printf("\t\t\tSalario Base: \t\t%d\n", SAL_BASE);
    printf("\t\t\tPor carro vendido: \t%d\n", mont_carro_vendido);
    printf("\t\t\t5.00%% das Vendas: \t%d\n",mont_vendas);
    printf("\t\t\t-----------------------\n");
    printf("\t\t\t\tTotal:\t %d",total);
    return 0;
}
