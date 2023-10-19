#include <stdio.h>
#include <stdlib.h>

int leNumero();
int areaQuadrado();
int areaTriangulo();
float areaCirculo();
int areaRetangulo();
void limparEcra();

int main()
{
    menu();
    return 0;
}

int leNumero()
{
    int num;
    scanf("%d", &num);
    return num;
}

int areaTriangulo()
{
    int base, altura;
    float area;
    printf("Escolheu o calculo da area de um triangulo!\n");
    leDadosTriangulo(&base, &altura);
    area = (base * altura) / 2;
    printf("A area e %.2f.\n", area);
    return area;
}

int leDadosTriangulo(int *base, int *altura)
{
    printf("Introduza o valor da base: \n");
    scanf("%d", base);
    printf("Introduza o valor da altura: \n");
    scanf("%d", altura);
}


int areaRetangulo()
{
    int area, comprimento, largura;
    printf("Escolheu o calculo da area de um retangulo!\n");
    printf("Introduza o comprimento do retangulo\n");
    comprimento = leNumero();
    printf("Introduza a largura do retangulo\n");
    largura = leNumero();
    area = largura * comprimento;
    printf("A area e %d.\n", area);
    return area;
}

int areaQuadrado()
{
    int lado, area;
    printf("Escolheu o calculo da area de um quadrado!\n");
    printf("Introduza o lado do quadrado");
    lado = leNumero();
    area = lado*lado;
    printf("A area e %d.\n", area);
    return area;
}

float areaCirculo()
{
    float area;
    int raio;
    printf("Escolheu o calculo da area de um Circulo!\n");
    printf("Introduza o raio:\n");
    raio = leNumero();
    area = 3.15 * (float)raio * (float)raio;
    printf("A area e %.2f.\n", area);
    return area;
}

void menu()
{
    char opc;
    int contadorR = 0, contadorQ = 0, contadorT = 0;
    float contadorC = 0;
    do
    {
        printf("\t\tCalculo de Area\n");
        printf("Triangulo (N) : %d\t\t\tRetangulo(N) : %d\n", contadorT, contadorR);
        printf("Circulo (N) : %d\t\t\tQuadrado(N) : %d\n", contadorC, contadorQ);
        printf("\tOPCOES\n");
        printf("\t(T)riangulo\n");
        printf("\t(R)etangulo\n");
        printf("\t(Q)uadrado\n");
        printf("\t(C)irculo\n");
        printf("\t(F)im\n");
        printf("\tSelecione opcao : ");
        scanf(" %s", &opc);
        switch(opc)
        {
        case 'T':
        case 't':
            areaTriangulo();
            contadorT++;
            break;
        case 'R':
        case 'r':
            areaRetangulo();
            contadorR++;
            break;
        case 'Q':
        case 'q':
            areaQuadrado();
            contadorQ++;
            break;
        case 'C':
        case 'c':
            areaCirculo();
            contadorC++;
            break;
        }
    }
    while(opc != 'F' && opc != 'f');
}


