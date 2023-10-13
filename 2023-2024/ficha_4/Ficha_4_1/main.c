#include <stdio.h>
#include <stdlib.h>

int leNumero();
int areaRetangulo(int lado1, int lado2);

int main()
{
    int lado1, lado2, area = 0;
    lado1 = leDadosRetangulo();
    lado2 = leDadosRetangulo();

    area = areaRetangulo(lado1, lado2);
    printf("%d", area);
    return 0;
}

int leNumero()
{
    int num;
    printf("Introduza um numero:");
    scanf("%d", &num);
    return num;
}

int areaRetangulo(int lado1, int lado2)
{
    int area = 0;
    area = lado1 * lado2;
    return area;
}

int leDadosRetangulo()
{
    int lado;
    lado = leNumero();
    return lado;
}
