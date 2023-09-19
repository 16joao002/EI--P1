#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pondTE, pondProj;
    printf("Componente de Avaliação\n\n");
    printf("TesteEscritos\t\tProjeto\n");
    printf("   50%%\t\t\t  50%%\n");
    printf("Aulas TP + Aulas PL\n");

    printf("Inicialmente estas eram as ponderacoes, agora altere-as:\n");
    printf("Nova ponderacao dos Testes Escritos:\n");
    scanf("%f",&pondTE);
    printf("Nova ponderacao do Projeto:\n");
    scanf("%f",&pondProj);

    printf("Componente de Avaliação\n\n");
    printf("TesteEscritos\t\tProjeto\n");
    printf("   %.2f%%\t\t\t  %.2f%%\n",pondTE,pondProj);
    printf("Aulas TP + Aulas PL\n");
    return 0;
}
