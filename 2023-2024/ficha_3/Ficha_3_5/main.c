#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, m = 0;
    float resultado = 0;
    printf("Introduza o valor m:\n");
    scanf("%d", &m);
    printf("Introduza o valor n:\n");
    scanf("%d", &n);

    if (m > 0 && n > 0 && n > m)
    {
        for(int i = m; i <= n ; i++)
        {
            resultado += (2.0 * i) / (5.0 + (i * i));
        }
        printf("Resultado :%.2f", resultado);
    }
    else
    {
        printf("Erro!");
    }
    return 0;
}
