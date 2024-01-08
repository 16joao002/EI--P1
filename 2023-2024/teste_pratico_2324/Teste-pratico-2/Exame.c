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
                do
                {
                    printf("Introduza a data do agendamento.\n");
                    data = lerData();
                    printf("Introduza o horario do agendamento.\n");
                    horario = lerHorario();

                    posAgendamentos = procurarAgendamento(vetorAgendamentos, *quantidadeAgendamentos, data, horario);
                    if(posAgendamentos == -1)
                    {
                        printf("Erro - Ja existem agendamentos com essa data.\n");
                    }
                }
                while(posAgendamentos != -1);

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
void registarVisita(tipoAgendamento *vetorAgendamentos, int *quantidadeAgendamentos, tipoCliente clientes[MAX], int quantidadeClientes){
    int pos;
    int numContribuinte;
    int posCli = -1;

    if(quantidadeClientes <= 0){
        printf("Erro - Nao existem clientes");
    }
    else{
        if(vetorAgendamentos == NULL){
            printf("Erro - Nao foi possivel alocar a memoria.\n");
        }
        else{
            numContribuinte = lerInteiro("Introduza o numero de contribuinte: ", 111111111, 999999999);
            posCli = procurarCliente(clientes, quantidadeClientes, numContribuinte);
            if (posCli == -1){
                printf("Erro - Nao existem esse numero de contribuinte.\n");
            }
            else{
                vetorAgendamentos.custo = lerFloat("Introduza o custo da reparação:", 1, 5000);
                vetorAgendamentos.grauSatisfacao = lerInteiro("Introduza o grau de satisfação:",1,3);
            }
        }
    }
}

/*
//listar clientes e respetivos agendamentos - listar todos os dados de cada utilizador e os seus agendamentos
void consultarAgendamento(){

}


//Listar todos os agendamentos de uma determinada data - total de agendamentos nessa data
void consultarAgendamentosData(){

}

//Clientes com mais agendamentos registados
void melhoresClientes(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *agendamentos){
    int pos, i;
    int melhor;


    if(quantidadeClientes <= 0){
        printf("Erro - Nao existem Clientes");
    }
    else{
        melhor = clientes[0]
        for(i = 1; i< quantidadeClientes; i++){
            //se o cliente tiver mais agendamentos vira o melhor
            if( >= melhor){

            }
        }
        printf("\nClientes com mais agendamentos: \n");
        for(i = 0; i < quantidadeClientes; i++){
            //se existirem clientes com o mesmo numero de agendamentos
            if(clientes.){
                escreverCliente(clientes[i])
            }
        }
    }
}

//Percentagem de satisfacao dos clientes
void percSatisfacao(){
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
}*/
