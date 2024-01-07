#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"

//inserir dados de um novo agendamento - nao podem haver 2 agendamentos com a mesma data e hora
//ajuda na pagina 5 do ultimo ppt
tipoAgendamento *inserirNovoAgendamento(tipoAgendamento *vetorAgendamentos,int *quantidadeAgendamentos,tipoCliente clientes[MAX], int quantidadeClientes)
{
    tipoAgendamento *oldArrayAddress, agendamentosAux;
    int posClientes, posAgendamentos, i;
    tipoData data;
    tipoHorario horario;

    posClientes = -1;
    posAgendamentos = -1;

    *oldArrayAddress = NULL;
    oldArrayAddress = vetorAgendamentos;

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
            vetorAgendamentos = realloc(vetorAgendamentos, ((*totalAgendamentos) + 1) * sizeof(tipoAgendamento));

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

                agendamentosAux.id++;
                agendamentosAux.data = data;
                agendamentosAux.horario = horario;
                lerString("\nDescricao: ", agendamentosAux.descricao);
                agendamentosAux.numContribuinte = clientes[posClientes].numContribuinte;

                vetorAgendamentos[*quantidadeAgendamentos] = agendamentosAux;
                (*quantidadeAgendamentos)++;
                clientes[posClientes].quantidadeAgendamentos++;
            }
        }
    }
    //falta dar free aqui do vetor agendamentos mas nao sei como fazer, vai dar memory leaks se nao fizer
    //free(vetorAgendamentos);
    return vetorAgendamentos;
}

int procurarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoData data, tipoHorario horario)
{
    int posAgendamentos = -1;

    for (int i = 0; i < quantidadeAgendamentos; i++)
    {
        if (vetorAgendamentos[i].data == data && vetorAgendamentos[i].horario == horario)
        {
            posAgendamentos = i;
            i = quantidadeAgendamentos;
        }
    }
    return posAgendamentos;
}



/*
//Regista o custo da reparacao e o grau de satisfaçao do cliente
void registarVisita(){
    int pos;

    if(quantidadeClientes <= 0){
        printf("Erro - Nao existem clientes");
    }
    else{
        procuraAgendamento()
    }
}

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
                fazer a pergunta de qual o grau de stasfaçao
                guardar la
}*/
