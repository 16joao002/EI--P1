#include <stdio.h>
#include <stdlib.h>

#define DOBRO 2
#define PI 3.14

int main()
{
    int num, multi, raio;
    float perimetro, area;
    printf("Este programa calcula o dobro do seu numero\n");
    printf("Digite um numero\n");
    scanf("%d",&num);
    multi = num * DOBRO;
    printf("O dobro do seu nunero e %d", multi);

    printf("Posteriormente, vamos calcular o perimetro e a area da circunferencia.\n");
    printf("Digite o raio:");
    scanf("%d", &raio);
    area = PI * (raio*raio);
    perimetro = 2 * PI * raio;
    printf("Area : %f\nPerimetro: %f", area, perimetro);
    printf("Area : +%f\nPerimetro: +%f", area, perimetro);
    printf("Area : %.1f\nPerimetro: %.1f", area, perimetro);
    printf("\t\t Area : %.2f\n\t\t Perimetro: %.2f", area, perimetro);
    return 0;
}
