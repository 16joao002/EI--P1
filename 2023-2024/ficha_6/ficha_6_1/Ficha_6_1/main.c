#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"

char menuPrincipal(int quantidadeEstudantes, int *contadorAvalidados, float *contadorPositivas);
void contas(int quantidadeEstudantes, int contadorPositivas, float *notasPositivas, tipoEstudante vetorEstudante[MAX_ESTUDANTES], int *quantidadeAvaliados);

int main()
{
    tipoEstudante estudantes[MAX_ESTUDANTES];
    int quantidadeEstudantes, contadorAvalidados;
    float percPositivas;
    char opc;
    contadorAvalidados = 0;
    percPositivas = 0;

    do
    {
        opc = menuPrincipal(quantidadeEstudantes, &contadorAvalidados, &percPositivas);
        switch(opc)
        {
        case 'A':
        case 'a':
            //acrescentar Estudantes
            quantidadeEstudantes = acrescentaEstudantes(estudantes,quantidadeEstudantes);
            break;
        case 'I':
        case 'i':
            //introduzir notas
            leNotas(estudantes, quantidadeEstudantes, &contadorAvalidados, &percPositivas);
            break;
        case 'M':
        case 'm':
            //mostrar dados
            mostrarDados(estudantes, quantidadeEstudantes);
            break;
        case 'G':
        case 'g':
            //gravar dados em um ficheiro
            break;
        case 'L':
        case 'l':
            //ler dados de um ficheiro
            break;
        case 'F':
        case 'f':
            printf("Programa Terminado....\n");
            pressionarContinuar();
            break;
        default:
            erro(-1,"Opcao errada!\n");
        }
    }
    while(opc != 'F' && opc != 'f');
    return 0;
}

char menuPrincipal(int quantidadeEstudantes, int *contadorAvalidados, float *percPositivas)
{
    char opc;
    printf("************** Menu Principal **************\n");
    printf("Estudantes inseridos: %d\n\n", quantidadeEstudantes);
    printf("Estudantes Avaliados : %d\t\tNotas Positivas (%%): %d", *contadorAvalidados, *percPositivas);
    printf("\nA - Acrescenta Estudante");
    printf("\nI - Introducao Notas");
    printf("\nM - Mostrar Dados");
    printf("\nG - Gravar Dados em Ficheiro");
    printf("\nL - Ler Dados de ficheiro");
    printf("\nF - Fim");
    printf("\nOpcao -->");
    scanf("%c", &opc);
    limparBuffer();

    return opc;
}
/*
void contas(int quantidadeEstudantes, int contadorPositivas, float *notasPositivas, tipoEstudante vetorEstudante[MAX_ESTUDANTES], int *quantidadeAvaliados)
{
    int i;
    *notasPositivas = (float)contadorPositivas/quantidadeEstudantes;
    if(quantidadeEstudantes < 0)
    {
        erro(-2, "Nao existem estudantes...");
    }
    else
    {
        for(i = 0; i < quantidadeEstudantes; i++)
        {
            if(vetorEstudante[i].nota != 0)
            {
                *quantidadeAvaliados++;
            }
        }
    }
}
*/
