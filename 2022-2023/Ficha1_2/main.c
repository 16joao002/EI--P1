#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testE, proj;
    printf("Introduza o valor da ponderacao dos testes escritos.\n");
    scanf("%d",&testE);     //obtem o valor da ponderacao dos testes escritos
    printf("Introduza o valor da ponderacao do projeto.\n");
    scanf("%d", &proj);     //obtem o valor da ponderacao dos projetos
    printf("Componentes de avaliacao\n\n");
    printf("Testes escritos\t\t\t\tProjeto\n");
    printf("%d%%\t\t\t\t\t%d%%", testE, proj);      //indica no ecra os valores introduzidos anteriormente
    printf("\n\nAultas TP + Aulas PL");
    return 0;
}
