#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"

int leQuantidadeEstudantes();
char menuPrincipal(int quantidadeEstudantes, int contadorAvalidados, float contadorPositivas);
tipoEstudante lerDadosEstudantes();
int procurarEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES], int quantidadeEstudantes, int numeroEstudante);

int main()
{
    tipoEstudante estudantes[MAX_ESTUDANTES];
    int quantidadeEstudantes;
    int contadorAvalidados, contadorPositivas;
    char opc;
    contadorAvalidados = 0;
    contadorPositivas = 0;
    quantidadeEstudantes = leQuantidadeEstudantes();

    do
    {
        opc = menuPrincipal(quantidadeEstudantes, &contadorAvalidados, &contadorPositivas);
        switch(opc)
        {
        case 'A':
        case 'a':
            //acrescentar Estudantes
            break;
        case 'I':
        case 'i':
            //introduzir notas
            break;
        case 'M':
        case 'm':
            //mostrar dados
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

char menuPrincipal(int quantidadeEstudantes, int *contadorAvalidados, float *contadorPositivas)
{
    char opc;
    printf("************** Menu Principal **************\n");
    printf("Estudantes inseridos: %d\n\n", quantidadeEstudantes);
    printf("Estudantes Avaliados : %d\t\tNotas Positivas (%%): %d", *contadorAvalidados, *contadorPositivas);
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



int leQuantidadeEstudantes()
{
    int numEstudantes = 0;
    numEstudantes = lerInteiro("Numero de Estudantes: ", 1, 100);
    return numEstudantes;
}


tipoEstudante lerDadosEstudantes(int quantidadeEstudantes, tipoEstudante estudantes[MAX_ESTUDANTES])
{
    int i;

    if(quantidadeEstudantes <= 0)
    {
        erro(-2, "Nao existem estudantes...");
    }
    else
    {
        for(i = 0; i < quantidadeEstudantes; i++)
        {
            lerString("Nome:", estudantes[i].nome,80);
            estudantes[i].numero = lerInteiro("Numero:",1,9999);
        }
    }
}

tipoEstudante leNotas(int quantidadeEstudantes, tipoEstudante estudantes[MAX_ESTUDANTES])
{
    int i;
    if(quantidadeEstudantes <= 0)
    {
        erro(-2, "Nao existem estudantes...");
    }
    else
    {
        for(i = 0; i < quantidadeEstudantes; i++)
        {
            estudantes[i].dataAval = lerData();
            estudantes[i].nota = lerFloat("Nota:",0,20);
        }
    }
}

int procurarEstudante(tipoEstudante vetorEstudantes[MAX_ESTUDANTES], int quantidadeEstudantes, int numeroEstudante)
{
    int posicao = -1, i;

    for(i = 0; i < quantidadeEstudantes; i++)
    {
        if(vetorEstudantes[i].numero == numeroEstudante)
        {
            posicao = i;
            i = quantidadeEstudantes;
        }
    }

    return posicao;
}


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
