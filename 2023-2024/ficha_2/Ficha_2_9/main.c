#include <stdio.h>
#include <stdlib.h>

#define BASE1 600
#define BASE2 750
#define BASE3 1000

int main()
{
    int categoria, dependentes;
    float resultado, bonus;
    printf("Introduza a sua categoria\n");
    scanf("%d", &categoria);
    printf("Introduza a quantidade de dependentes\n");
    scanf("%d", &dependentes);

    if(categoria == 1)
    {
        if(dependentes == 1)
        {
            bonus = BASE1 * 0.05;
            resultado = BASE1 + bonus;
            printf("Montante ganho: %.2f", resultado);
        }
        else
        {
            if(dependentes > 1)
            {
                bonus = BASE1 * 0.09;
                resultado = BASE1 + bonus;
                printf("Montante ganho: %.2f", resultado);
            }
            else
            {
                printf("ERRO - montante invalido");
            }
        }
    }
    else
    {
        if(categoria == 2)
        {
            if(dependentes == 1)
            {
                bonus = BASE2 * 0.03;
                resultado = BASE2 + bonus;
                printf("Montante ganho: %.2f", resultado);
            }
            else
            {
                if(dependentes > 1)
                {
                    bonus = BASE2 * 0.07;
                    resultado = BASE2 + bonus;
                    printf("Montante ganho: %.2f", resultado);
                }
                else
                {
                    printf("ERRO - montante invalido");
                }
            }
        }
        else
        {
            if(categoria == 3)
            {
                if(dependentes == 1)
                {
                    bonus = BASE3 * 0.02;
                    resultado = BASE3 + bonus;
                    printf("Montante ganho: %.2f", resultado);
                }
                else
                {
                    if(dependentes > 1)
                    {
                        bonus = BASE3 * 0.05;
                        resultado = BASE3 + bonus;
                        printf("Montante ganho: %.2f", resultado);
                    }
                    else
                    {
                        printf("ERRO - montante invalido");
                    }
                }
            }
        }
    }
    return 0;
}
