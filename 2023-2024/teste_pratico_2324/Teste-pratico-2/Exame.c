#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "Exame.h"

void inserirNovoAgendamento(tipoAgendamento *vetorAgendamentos,int *quantidadeAgendamentos,tipoCliente clientes[MAX], int quantidadeClientes)
{
    int posClientes, posAgendamentos,numContribuinte;
    tipoData data;
    tipoHorario horario;

    tipoAgendamento agendamentosAux;
    posClientes = -1;
    posAgendamentos = -1;

    //verifica se existem clientes
    if(quantidadeClientes <= 0)
    {
        printf("Erro - Nao existem clientes\n");
    }
    else
    {

        numContribuinte = lerInteiro("Introduza o numero de contribuinte do Cliente:\n", 111111111, 999999999);
        posClientes = procurarCliente(clientes, quantidadeClientes, numContribuinte);
        //verifica se existe algum cliente com esse numero de contribuinte
        if(posClientes == -1)
        {
            printf("Erro - Nao existe um cliente com esse numero de contribuinte.\n");
        }
        else
        {
            //adiciona uma posicao ao vetor
            vetorAgendamentos = realloc(vetorAgendamentos, ((*quantidadeAgendamentos) + 1) * sizeof(tipoAgendamento));


            if(vetorAgendamentos == NULL)
            {
                printf("Erro - Nao foi possivel alocar a memoria.\n");
            }
            else
            {
                data = lerData();
                horario = lerHorario();

                posAgendamentos = procurarAgendamento(vetorAgendamentos, *quantidadeAgendamentos, data, horario);
                if(posAgendamentos == -1)
                {

                }
                else
                {
                    if(agendamentosAux.id == 0)
                    {
                        agendamentosAux.id = 1;
                    }
                    else
                    {
                        agendamentosAux.id++;
                    }
                    agendamentosAux.data = data;
                    agendamentosAux.horario = horario;
                    lerString("\nDescricao: ", agendamentosAux.descricao, TEXTO_LONGO);
                    agendamentosAux.numContribuinte = numContribuinte;

                    vetorAgendamentos[*quantidadeAgendamentos] = agendamentosAux;
                    (*quantidadeAgendamentos)++;
                    clientes[posClientes].quantidadeAgendamentos++;
                }

            }
        }
    }
}

int procurarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoData data, tipoHorario horario)
{
    int posAgendamentos = -1, i;

    for (i = 0; i < quantidadeAgendamentos; i++)
    {
        if (vetorAgendamentos[i].data.dia == data.dia &&
                vetorAgendamentos[i].data.mes == data.mes &&
                vetorAgendamentos[i].data.ano == data.ano &&
                vetorAgendamentos[i].horario.horas == horario.horas &&
                vetorAgendamentos[i].horario.minutos == horario.minutos)
        {
            posAgendamentos = i;
            i = quantidadeAgendamentos;
        }
    }
    return posAgendamentos;
}

//Regista o custo da reparacao e o grau de satisfa�ao do cliente
void registarVisita(tipoAgendamento *vetorAgendamentos, int *quantidadeAgendamentos, tipoCliente clientes[MAX], int quantidadeClientes, int *quantidadeVisitas)
{
    int numContribuinte;
    int posCli = -1;
    tipoData data;
    tipoHorario horario;
    int posAgendamento;
    posAgendamento = -1;

    if(quantidadeClientes <= 0)
    {
        printf("Erro - Nao existem clientes");
    }
    else
    {
        if(vetorAgendamentos == NULL)
        {
            printf("Erro - Nao foi possivel alocar a memoria.\n");
        }
        else
        {
            numContribuinte = lerInteiro("Introduza o numero de contribuinte: ", 111111111, 999999999);
            posCli = procurarCliente(clientes, quantidadeClientes, numContribuinte);
            if (posCli == -1)
            {
                printf("Erro - Nao existem esse numero de contribuinte.\n");
            }
            else
            {
                data = lerData();
                horario = lerHorario();

                posAgendamento = procurarAgendamento(vetorAgendamentos, quantidadeAgendamentos, data, horario);
                if(posAgendamento == -1)
                {
                    printf("Erro - Nao existem essa data.\n");
                }
                else
                {
                    vetorAgendamentos->custo = lerFloat("Introduza o custo da reparação:", 1, 5000);
                    vetorAgendamentos->grauSatisfacao = lerInteiro("Introduza o grau de satisfação:",1,3);
                    (*quantidadeVisitas)++;
                }
            }
        }
    }
}


//listar clientes e respetivos agendamentos - listar todos os dados de cada utilizador e os seus agendamentos
void consultarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoCliente cliente[MAX], int quantidadeClientes)
{

    tipoData data;
    tipoHorario horario;
    int posAgendamento;
    int i;

    if(quantidadeClientes < 0)
    {
        printf("Erro - Nao existem agendamentos.\n");
    }
    else
    {
        //pede a data ao utilizador
        data = lerData();
        horario = lerHorario();
        posAgendamento= procurarAgendamento(vetorAgendamentos, quantidadeAgendamentos, data, horario);

        if(posAgendamento == -1)
        {
            printf("Erro - Nao existem agendamentos");
        }
        else
        {
            for(i = 0; i < quantidadeAgendamentos; i++)
            {
                //colocar o print dos agendamentos feitos neste dia
            }
        }
    }

    //falta listar a quantidade total de agendamentos de uma determinada data...
}


//Clientes com mais agendamentos registados
void melhoresClientes(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *agendamentos, int quantidadeAgendamentos){
    int i, j, maxAgendamentos = 0;
    printf("\n\nMelhor(es) Cliente(s):\n");

    for (i = 0; i < quantidadeClientes; i++)
    {
        for (j=0; j < quantidadeAgendamentos; j++)
        {
            if (agendamentos[j].numContribuinte == clientes[i].numContribuinte)
            {
                clientes[i].quantidadeAgendamentos++;
            }
        }
        if (clientes[i].quantidadeAgendamentos > maxAgendamentos)
        {
            maxAgendamentos = clientes[i].quantidadeAgendamentos;
        }
    }

    for (i = 0; i < quantidadeClientes; i++)
    {
        if (clientes[i].quantidadeAgendamentos == maxAgendamentos)
        {
            escreverCliente(clientes[i]);
        }
    }
}


//Percentagem de satisfacao dos clientes
void percSatisfacao(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *agendamentos, int quantidadeAgendamentos){
    int i, soma1, soma2, soma3, somaTotal;
    soma1 = 0;
    soma2 = 0;
    soma3 = 0;
    somaTotal = 0;

    float percentagem1, percentagem2, percentagem3;
    percentagem1 = 0;
    percentagem2 = 0;
    percentagem3 = 0;

    for (i=0; i < quantidadeAgendamentos; i++)
    {
        if (agendamentos[i].grauSatisfacao == 1)
        {
            soma1++;
        }
        else{
            if (agendamentos[i].grauSatisfacao == 2)
            {
                soma2++;
            }
            else{
                soma3++;
            }
        }
        somaTotal++;
    }

    percentagem1 = (float)soma1/somaTotal*100;
    percentagem2 = (float)soma2/somaTotal*100;
    percentagem3 = (float)soma3/somaTotal*100;

    printf("\nGrau de Satisfacao 1: %.2f%%\n", percentagem1);
    printf("Grau de Satisfacao 2: %.2f%%\n", percentagem2);
    printf("Grau de Satisfacao 3: %.2f%%\n", percentagem3);
}

void escreverAgendamento(tipoAgendamento *vetorAgendamento)
{
    printf("\n\nContribuinte: %d\t\tID: %d\n", vetorAgendamento->numContribuinte, vetorAgendamento->id);
    printf("\n\nCusto: %.2f\t\tGrau de satisfacao: %d\n", vetorAgendamento->custo, vetorAgendamento->grauSatisfacao);
    printf("\n\nData: %d/%d/%d\t\tHora: %d:%d\n", vetorAgendamento->data.dia, vetorAgendamento->data.mes, vetorAgendamento->data.ano , vetorAgendamento->horario.horas, vetorAgendamento->horario.minutos);
    printf("Descricao: %s\n",vetorAgendamento->descricao);
}


/*
    primeiro procurar qual o agendamento
    ver se existe
        se nao existir
        printf de erro
        se existir
            verificar se tem ja algum grau colocado
            se existir
                printf erro
            se nao existir
                fazer a pergunta de qual o grau de stasfa�ao
                guardar la
//Listar todos os agendamentos de uma determinada data - total de agendamentos nessa data
void consultarAgendamentosData(){

}*/
