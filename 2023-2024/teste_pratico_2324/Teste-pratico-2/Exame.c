#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "exame.h"


/** ------------------- Funções dos AGENDAMENTOS ------------------- **/

// Função que permite inserir um agendamento
tipoAgendamento *inserirAgendamentos (tipoAgendamento *vetorAgendamentos,tipoCliente cliente[MAX], int *quantAgendamentos, int quantClientes, tipoVisita *vetorVisitas)
{
    int posicao, numContribuinte2;
    int n, codigo, existente;

    tipoData vetorData;
    tipoHorario vetorHorario;
    tipoAgendamento *pAgendamentos;

    pAgendamentos=vetorAgendamentos;

    int i = (*quantAgendamentos);

    vetorAgendamentos = realloc(vetorAgendamentos,(i+1)*sizeof(tipoAgendamento));
    if(vetorAgendamentos == NULL)
    {
        printf("Erro - impossivel registar um novo agendamento");
        vetorAgendamentos = pAgendamentos;
        free(pAgendamentos);
    }
    else
    {
        vetorData = lerData();
        vetorHorario = lerHorario();
        for(n= 0; n < *quantAgendamentos; n++)
        {
            if(vetorData.dia == vetorAgendamentos[n].diaVisita.dia &&
                vetorData.mes == vetorAgendamentos[n].diaVisita.mes &&
                vetorData.ano ==  vetorAgendamentos[n].diaVisita.ano &&
                vetorHorario.horas == vetorAgendamentos[n].horaVisita.horas &&
                vetorHorario.minutos == vetorAgendamentos[n].horaVisita.minutos)
            {
                existente = 0;
                n = *quantAgendamentos;
            }
        }
        if(existente != 0)
        {
            numContribuinte2 = lerInteiro("\nInsira o numero de contribuinte do cliente: ", CONTRIBUITE_MIN, CONTRIBUITE_MAX);
            posicao = procurarCliente(cliente,quantClientes,numContribuinte2);
            for(n=0; n<quantClientes ; n++)
            {
                if(cliente[n].numContribuinte == numContribuinte2)
                {

                    codigo = *quantAgendamentos;
                    codigo++;
                    vetorAgendamentos[i].numContribuinte = numContribuinte2;
                    vetorAgendamentos[i].codigo = codigo;
                    printf("\n\n*********** NOVO AGENDAMENTO ***********\n\n");
                    printf("ID: %d",vetorAgendamentos[i].codigo);
                    vetorAgendamentos[i].diaVisita = vetorData;
                    vetorAgendamentos[i].horaVisita = vetorHorario;

                    vetorVisitas[i].custo = 0;
                    strcpy(vetorVisitas[i].satisfacaoCliente, "");

                    lerString("\nDescricao do problema do eletrodomestico: ",vetorAgendamentos[i].descricaoProblema,TEXTO_LONGO);
                    (*quantAgendamentos)++;
                    n=quantClientes;
                    posicao=-1;
                }

            }

        }
        else{
            printf("Erro - Ja existe um agendamento com essa data.\n");
        }
    }
    if(posicao != -1)
    {
        printf("\nERRO: O nr. contribuinte inserido nao existe!");
    }
    return vetorAgendamentos;
}

// Função que lista no ecra os dados de todos os clientes inseridos no vetor
void listarClientesAgendamentos (tipoCliente vetorClientes[MAX],tipoAgendamento *vetorAgendamentos,tipoVisita *visita, int quantClientes, int quantAgendamentos)
{
    int i,n;
    if(quantClientes == 0)
    {
        printf("\nERRO: Sem clientes para mostrar de momento");
    }
    else
    {
        for (i=0; i < quantClientes; i++)
        {
            printf("\n********************************* INFORMACOES REFERENTES AO CONTRIBUINTE: %9d *********************************\n\n", vetorClientes[i].numContribuinte);
            printf("\nNome: %s",vetorClientes[i].nome);
            printf("\nMorada: %s",vetorClientes[i].morada);
            printf("\nTelefone: %d",vetorClientes[i].telefone);

            for (n=0; n < quantAgendamentos; n++)
            {
                if(vetorAgendamentos[n].numContribuinte == vetorClientes[i].numContribuinte)
                {
                    printf("\n\nCodigo de agendamento --> %d\t",vetorAgendamentos[n].codigo);
                    printf("\nData do agendamento --> ");
                    escreverData(vetorAgendamentos[n].diaVisita);
                    printf("\nHora do agendamento --> ");
                    escreverHora(vetorAgendamentos[n].horaVisita);
                    printf("\nProblema encontrado: %s", vetorAgendamentos[n].descricaoProblema);

                    printf("\n\nCusto da visita: %.2f",visita[n].custo);
                    printf("\nSatisfacao cliente: %s",visita[n].satisfacaoCliente);
                }
                else
                {
                    printf("\n\nNao foram encontrados agendamentos para este cliente!");
                }

            }

        }
    }

}

void escreverData (tipoData data)
{
    printf("%2d-%2d-%4d", data.dia, data.mes, data.ano);
}

void escreverHora (tipoHorario hora)
{
    printf("%2d:%2d", hora.horas, hora.minutos);
}

//**  VISITA **//
tipoVisita *registarVisita (tipoVisita *vetorVisita,tipoAgendamento *vetorAgendamentos, int quantAgendamentos, int *quantVisitas)
{
    int posicao,codigo2,n,op;

    tipoVisita *pVisita;

    pVisita=vetorVisita;

    int i = (*quantVisitas);

    vetorVisita = realloc(vetorVisita,(i+1)*sizeof(tipoVisita));
    if(vetorVisita == NULL)
    {
        printf("Erro - impossivel registar um novo agendamento");
        vetorVisita = pVisita;
    }
    else
    {
        codigo2 = lerInteiro("\nInsira o codigo/id do agendamento: ",1,999);

        for(n=0; n<quantAgendamentos ; n++)
        {
            if(vetorAgendamentos[n].codigo == codigo2)
            {

                vetorVisita[i].codigo = codigo2;
                printf("\n\n*********** NOVA VISITA ***********\n\n");
                printf("Nr. Contribuinte: %d",vetorAgendamentos[i].numContribuinte);

                vetorVisita[i].custo = lerFloat("\nIndique o custo da visita: ",0,999);

                op = lerInteiro("Indique a satisfacao do cliente (1)-Fraco (2)-Bom (3)-Excelente: ",1,3);
                switch(op)
                {
                case 1:
                    strcpy(vetorVisita[i].satisfacaoCliente,"Fraco");
                    break;
                case 2:
                    strcpy(vetorVisita[i].satisfacaoCliente,"Bom");
                    break;
                case 3:
                    strcpy(vetorVisita[i].satisfacaoCliente,"Excelente");
                    break;
                default:
                    printf("\nPor favor indique um valor dentro do intervalo solicitado");
                }
                (*quantVisitas)++;
                n=quantAgendamentos;
                posicao=-1;
            }

        }

    }
    if(posicao != -1)
    {
        printf("\nERRO: O codigo inserido nao existe!");
    }
    return vetorVisita;
}


void percentagemSatisfacao(tipoVisita *visita, int quantclientes, int *quantVisitas)
{

    int quantF=0;
    int quantBom=0;
    int quantExe=0;

    float percentagemFraco=0, percentagemBom=0, percentagemExcelente=0;

    int i;

    if(quantclientes !=0)
    {
        if(*quantVisitas != 0 )
        {


            for(i=0; i<quantclientes; i++)
            {

                if(strcmp(visita[i].satisfacaoCliente,"Fraco")==0)
                {
                    quantF++;
                }
                else
                {
                    if(strcmp(visita[i].satisfacaoCliente,"Bom")==0)
                    {
                        quantBom++;
                    }
                    else
                    {
                        if(strcmp(visita[i].satisfacaoCliente,"Excelente")==0)
                        {
                            quantExe++;
                        }
                    }
                }
            }

            percentagemFraco = (float)quantF/ *quantVisitas * 100;
            percentagemBom = (float)quantBom/ *quantVisitas * 100;
            percentagemExcelente = (float)quantExe/ *quantVisitas * 100;

            printf("\n\tFraco=%.2f  Bom=%.2f  Excelente=%.2f\n",percentagemFraco,percentagemBom,percentagemExcelente);
        }
        else
        {
            printf("\nNao existem visitas!");
        }
    }
    else
    {
        printf("\nNao existem clientes!");
    }
}

void melhorCliente (tipoCliente vetorClientes[MAX],tipoAgendamento *vetorAgendamentos, int quantClientes, int quantAgendamentos)
{
    int maior = 0, temp, i,j;

    if(quantClientes > 0 && quantAgendamentos > 0)
    {
        for(i = 0; i < quantClientes; i++)
        {
            temp = 0;
            for(j = 0; j < quantAgendamentos; j++)
            {
                if(vetorClientes[i].numContribuinte == vetorAgendamentos[j].numContribuinte)
                {
                    temp++;
                }
            }
            if(temp > maior)
            {
                maior = temp;
            }

        }
        printf("\nTop agendamentos, com %d agendamentos\n", maior);

        for (i = 0; i < quantClientes; i++)
        {
            temp = 0;
            for(j = 0; j < quantAgendamentos; j++)
            {
                if(vetorClientes[i].numContribuinte == vetorAgendamentos[j].numContribuinte)
                {
                    temp++;
                }
            }
            if ( temp == maior)
            {
                printf("\n********************************* MELHOR CLIENTE *********************************\n\n");
                printf("\nNome: %s",vetorClientes[i].nome);
                printf("\nNr. Contribuinte: %d",vetorClientes[i].numContribuinte);
                printf("\nMorada: %s",vetorClientes[i].morada);
                printf("\nTelefone: %d",vetorClientes[i].telefone);
                printf("\nQuantidade agendamentos: %d",maior);
            }
        }
    }
    else
    {
        printf("Erro - Nao existem Agendamentos\n");
    }
}

void consultaAgendamentoData(tipoAgendamento *vetorAgendamentos, int quantAgendamentos, tipoCliente vetorClientes[MAX])
{
    tipoData data;
    int total = 0, i;

    printf("\nInsira a data para consulta: ");
    data = lerData();

    printf("\nConsulta do dia %d/%d/%d", data.ano, data.mes, data.dia);
    for(i = 0; i < quantAgendamentos; i++)
    {
        if(data.ano == vetorAgendamentos[i].diaVisita.ano &&
                data.mes == vetorAgendamentos[i].diaVisita.mes &&
                data.dia == vetorAgendamentos[i].diaVisita.dia)
        {
            total++;
            printf("\n\nCodigo de agendamento --> %d\t",vetorAgendamentos[i].codigo);
            printf("\nData do agendamento --> ");
            escreverData(vetorAgendamentos[i].diaVisita);
            printf("\nHora do agendamento --> ");
            escreverHora(vetorAgendamentos[i].horaVisita);
            printf("\nProblema encontrado: %s", vetorAgendamentos[i].descricaoProblema);
        }
    }
    printf("\nTotal: %d", total);
}

///////////////////////////////
//** CONSULTA AGENDAMENTOS **////////////BERNA////////////////
///////////////////////////////
/*
void consultaAgendamento(tipoAgendamento *vetorAgendamento, int quantAgendamentos, tipoCliente vetorClientes[MAX]){
    tipoData diaVisita;
    int total = 0, i;

    printf("\nInsira a data para consulta: ");
    diaVisita = lerData();

    printf("\nConsulta do dia %d/%d/%d", diaVisita.ano, diaVisita.mes, diaVisita.dia);
    for( int i = 0; i < quantAgendamentos; i++){
        if(diaVisita.ano == vetorAgendamento[i].diaVisita.ano &&
                diaVisita.mes == vetorAgendamento[i].diaVisita.mes &&
                    diaVisita.dia == vetorAgendamento[i].diaVisita.dia){
                        total++;
                        escreverAgendamento(vetorAgendamento[i], vetor);
                    }
    }
    printf("\nTotal: %d", total);
}


int procurarData(tipoAgendamento *vetorAgendamento, int quantAgendamentos){
    int i,diaC,mesC,anoC,horaC,minutoC,procurarData;
    procurarData = -1;

    for(int i = 0; i < quantAgendamentos; i++){
        diaC = vetorAgendamento[i].diaVisita.dia;
        mesC = vetorAgendamento[i].diaVisita.mes;
        anoC = vetorAgendamento[i].diaVisita.ano;
        horaC = vetorAgendamento[i].horaVisita.horas;
        minutoC = vetorAgendamento[i].horaVisita.minutos;

        if(diaC == vetorAgendamento[i].diaVisita.dia &&
                mesC == vetorAgendamento[i].diaVisita.mes &&
                    anoC == vetorAgendamento[i].diaVisita.ano &&
                        horaC == vetorAgendamento[i].horaVisita.horas &&
                            minutoC == vetorAgendamento[i].horaVisita.minutos)
                            {
                                    procurarData = i;
                                    i = quantAgendamentos;
                            }
    }
    return procurarData;
}


void listarAgendamentos(tipoCliente vetorClientes[MAX], int quantClientes, tipoAgendamento *vetorAgendamento, int quantAgendamentos){
    int i, j;

    if(quantClientes > 0)
    {
        printf("\nLista Clientes/Agendamentos");
        for( int i = 0; i < quantClientes; i++)
        {
            escreverClienteA(vetorClientes[i]);
            if(quantAgendamentos > 0){
                for(int j = 0; j < quantAgendamentos; j++){
                    if(vetorAgendamento[j].numContribuinte == vetorClientes[i].numContribuinte){
                        printf("\nAgendamentos do Cliente");
                        escreverAgendamento(vetorAgendamento[j]);
                        printf("\n-----------------------\n");
                    }
                }
            }
        }
    }
    else
    {
        printf("\nAtencao: nao existem clientes inseridos\n");
    }
}

void escreverAgendamento(tipoAgendamento agendamento, tipoVisita visita){
    printf("\nCodigo do agendamento: %d", agendamento.codigo);
    printf("\nNr. contribuinte: %d", agendamento.numContribuinte);
    printf("\nData: %d/%d/%d", agendamento.diaVisita.ano, agendamento.diaVisita.mes, agendamento.diaVisita.dia);
    printf("\nHora: %d/%d", agendamento.horaVisita.horas, agendamento.horaVisita.minutos);
    printf("\nDescricao: %s", agendamento.descricaoProblema);
    if (visita.custo == -1){
        printf("\nCusto: N/A");
    }
    else{
        printf("\nCusto: %.2f", visita.custo);
    }
    if (visita.satisfacaoCliente == -1){
        printf("\nGrau de satisfacao: N/A");
    }
    else{
        printf("\nGrau de satisfacao: %d", visita.satisfacaoCliente);
    }
}
*/
