#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"

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

int acrescentaEstudantes(tipoEstudante estudantes[MAX_ESTUDANTES], int quantidadeEstudantes)
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
        if(pos != -1)
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


void leNotas(tipoEstudante estudantes[MAX_ESTUDANTES], int quantidadeEstudantes, int *contadorAvalidados, float *percPositivas)
{
    tipoData data;
    *contadorAvalidados = 0; // reset no contador

    int i, j, contadorPositivas;
    if(quantidadeEstudantes <= 0)
    {
        erro(-2, "Nao existem estudantes...");
    }
    else
    {
        //le as notas
        for(i = 0; i < quantidadeEstudantes; i++)
        {
            printf("\nEstudante: %d (%s)\n", estudantes[i].numero, estudantes[i].nome);
            estudantes[i].nota = lerFloat("Nota:",0,20);
            printf("\nData avaliacao:\n");
            estudantes[i].dataAval = lerData();
            (*contadorAvalidados)++;
        }
        //conta as notas positivas
        for(j = 0; j < quantidadeEstudantes; j++)
        {
            if(estudantes[j].nota > 9.5)
            {
                contadorPositivas++;
            }
        }
        *percPositivas = ((float)contadorPositivas / quantidadeEstudantes) *100;
    }
}

int procurarEstudante(tipoEstudante estudante[MAX_ESTUDANTES], int quantidadeEstudantes, int numeroEstudante)
{
    int posicao = -1, i;

    for(i = 0; i < quantidadeEstudantes; i++)
    {
        if(estudante[i].numero == numeroEstudante)
        {
            posicao = i;
            i = quantidadeEstudantes;
        }
    }

    return posicao;
}

void mostrarDados(tipoEstudante estudante[MAX_ESTUDANTES], int quantidadeEstudantes)
{
    int i;
    if(quantidadeEstudantes == MAX_ESTUDANTES)
    {
        printf("\nLimite de estudantes...\n");
    }
    else
    {
        printf("\n\n Numero \t Nome \t Nota \t Data Avaliacao \n");
        for(i = 0; i<quantidadeEstudantes; i++)
        {
            printf("  %d \t %s", estudante[i].numero, estudante[i].nome);

            if (estudante[i].nota == -1)
            {
                printf(" \t Sem Nota \t N/A\n");
            }
            else
            {
                printf("  \t %.2f \t %2d-%2d-%4d\n", estudante[i].nota, estudante[i].dataAval.dia,estudante[i].dataAval.mes,estudante[i].dataAval.ano);
            }
        }
    }
}
