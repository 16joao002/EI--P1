#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"

char menuPrincipal(int quantidadeEstudantes, int *contadorAvalidados, float *contadorPositivas);
tipoEstudante lerDadosEstudantes();


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


tipoEstudante lerDadosEstudantes()
{
    tipoEstudante estudante;

    printf("\n\nInserir dados do estudante\n");

    estudante.numero = lerInteiro("Numero:",MIN_ESTUDANTES, MAX_ESTUDANTES);
    lerString("Nome:", estudante.nome, LONG_CHAR);
    estudante.nota = -1;

    return estudante;
}

void acrescentaEstudantes(tipoEstudante estudantes[MAX_ESTUDANTES], int quantidadeEstudantes)
{
    tipoEstudante dados;
    int pos;

    if(quantidadeEstudantes == MAX_ESTUDANTES)
    {
        printf("\nLimite de Estudantes atingido...\n");
    }
    else
    {
        dados = lerDadosEstudantes();
        pos = procurarEstudante(estudantes, quantidadeEstudantes, dados.numero);
        if(pos == -1)
        {
            printf("\nEsse estudante ja existe...\n\n");
        }
        else
        {
            estudantes[quantidadeEstudantes] = dados;
            quantidadeEstudantes++;
        }
    }
    return quantidadeEstudantes;
}



void leNotas(int quantidadeEstudantes, tipoEstudante estudantes[MAX_ESTUDANTES])
{
    tipoData data;

    int i;
    if(quantidadeEstudantes <= 0)
    {
        erro(-2, "Nao existem estudantes...");
    }
    else
    {
        for(i = 0; i < quantidadeEstudantes; i++)
        {
            printf("\nEstudante: %d (%s)\n", estudantes[i].numero, estudantes[i].nome);
            estudantes[i].nota = lerFloat("Nota:",0,20);
            printf("\nData avaliacao:\n");
            data = lerData();
            estudantes[i].dataAval = data;
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
