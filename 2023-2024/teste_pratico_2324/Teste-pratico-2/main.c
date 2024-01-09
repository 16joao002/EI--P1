/*
* @folder numeroNome_ExP1
* @brief Gestão da agenda de um técnico de reparações de eletrodomésticos ao domicílio
* @date 31-01-2017
* @author (COLOCAR O NUMERO, NOME E EMAIL)
*/


#include <stdio.h>
#include <stdlib.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"
#include "exame.h"

/** ------------------------ Funções dos menus ----------------------- **/
int menu(int totalClientes);
int menuClientes(void);
int menuAgendamentos(void);
int menuEstatisticas(void);
int menuFicheiros(void);


///** ------------------- Funções das Funcionalidades ------------------- **/

void inserirNovoCliente (tipoCliente vetorClientes[MAX], int *quantClientes);
int procurarCliente (tipoCliente vetorClientes[MAX], int quantCliente, int numContribuinte);
void escreverCliente (tipoCliente cliente);
void listarClientes (tipoCliente vetorClientes[MAX], int quantClientes);



void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes, tipoAgendamento *vetorAgendamentos, int quantAgendamentos, tipoVisita *vetorVisita, int quantVisitas);
void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes, tipoAgendamento **vetorAgendamentos, int *quantAgendamentos, tipoVisita **vetorVisita, int *quantVisitas);
//void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes);
//void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes);

/** ------------------------------ main ------------------------------ **/

int main(void)
{
    //alterado
    tipoCliente vetorClientes[MAX];
    tipoAgendamento *vetorAgendamentos = NULL;
    tipoVisita *vetorVisita = NULL;

    int quantVisitas,quantClientes,quantAgendamentos, opcao, opcao2;

    quantClientes = 0;
    quantAgendamentos = 0;

    vetorVisita = calloc(0, sizeof(tipoVisita));

    do
    {
        opcao = menu(quantClientes);
        switch (opcao)
        {
            case 1: // menu CLIENTES
                do
                {
                    opcao2 = menuClientes();
                    switch (opcao2)
                    {
                        case 1:  // inserir novo cliente
                            inserirNovoCliente(vetorClientes, &quantClientes);
                            break;
                        case 2 : // Listar Clientes
                            listarClientes(vetorClientes, quantClientes);
                            break;
                        case 3:  // Listar Clientes e respetivas marcacoes
                            listarClientesAgendamentos (vetorClientes,vetorAgendamentos,vetorVisita,quantClientes,quantAgendamentos);
                            break;
                    }
                } while (opcao2 != 0);
                break;

            case 2: // menu AGENDAMENTOS
                do
                {
                    opcao2 = menuAgendamentos();
                    switch (opcao2)
                    {
                        case 1:  // Adicionar novo agendamento
                            vetorAgendamentos = inserirAgendamentos(vetorAgendamentos,vetorClientes, &quantAgendamentos, quantClientes, vetorVisita);
                            break;
                        case 2 : // Registar Visita
                            vetorVisita = registarVisita (vetorVisita,vetorAgendamentos,quantAgendamentos,&quantVisitas);

                            break;
                        case 3:  // Consultar Agendamentos (por data)
                            consultaAgendamentoData(vetorAgendamentos,quantAgendamentos,vetorClientes);
                            break;
                    }
                } while (opcao2 != 0);
                break;

            case 3: // menu ESTATISTICA
                do
                {
                    opcao2 = menuEstatisticas();
                    switch (opcao2)
                    {
                        case 1:  // Melhor(es) Cliente(s) - os que têm mais agendamentos
                            melhorCliente (vetorClientes,vetorAgendamentos,quantClientes,quantAgendamentos);
                            break;
                        case 2 : // Índice/Percentagens por graus de satisfacao dos clientes
                            percentagemSatisfacao(vetorVisita, quantClientes,&quantVisitas);
                            break;
                    }
                } while (opcao2 != 0);
                break;

            case 4: // menu FICHEIROS
                do
                {
                    opcao2 = menuFicheiros();
                    switch (opcao2)
                    {
                        case 1:  // Guardar no ficheiro
                            escreverFicheiroBinario(vetorClientes, quantClientes, vetorAgendamentos, quantAgendamentos, vetorVisita, quantVisitas);
                            break;
                        case 2 : // Ler do ficheiro
                            lerFicheiroBinario(vetorClientes, &quantClientes, &vetorAgendamentos, &quantAgendamentos, &vetorVisita, &quantVisitas);
                            break;
                    }
                } while (opcao2 != 0);
                break;
        }


    } while (opcao != 0);

    free (vetorAgendamentos); // Alterado
    free(vetorVisita);
    return 0;
}





/** ------------------- Funções dos CLIENTES ------------------- **/

// Função que permite inserir um novo cliente no vetorClientes
void inserirNovoCliente (tipoCliente vetorClientes[MAX], int *quantClientes)
{
    int posicao, numContribuinte;

    if (*quantClientes < MAX)
    {
        printf("\n\n*********** NOVO CLIENTE ***********\n\n");
        numContribuinte = lerInteiro("\nNumero de contribuinte: ", CONTRIBUITE_MIN, CONTRIBUITE_MAX);
        posicao = procurarCliente(vetorClientes, *quantClientes, numContribuinte);

        if (posicao > -1)
        {
            printf("\n\nATENCAO: o nr. contribuinte inserido ja existe.\n");
            escreverCliente(vetorClientes[posicao]);
        }
        else
        {
            vetorClientes[*quantClientes].numContribuinte = numContribuinte;
            lerString("\nNome: ", vetorClientes[*quantClientes].nome, TEXTO_BREVE);
            lerString("\nMorada: ", vetorClientes[*quantClientes].morada, TEXTO_LONGO);
            vetorClientes[*quantClientes].telefone = lerInteiro("\nTelefone: ", TELEFONE_MIN, TELEFONE_MAX);
            (*quantClientes)++;
        }
    }
    else
    {
        printf("\n\nATENCAO: o limite maximo de clientes ja foi atingido\n\n");
    }
}


// Função que procura um cliente pelo nº de contribuinte. A função devolve -1 se não encontrar o cliente ou devolve a posição do cliente no vetor
int procurarCliente (tipoCliente vetorClientes[MAX], int quantCliente, int numContribuinte)
{
    int posicao = -1, i;

    for (i=0; i < quantCliente;  i++)
    {
        if (vetorClientes[i].numContribuinte == numContribuinte)
        {
            posicao = i;
            i = quantCliente;
        }
    }

    return posicao;
}


// Função que lista no ecra os dados de todos os clientes inseridos no vetor
void listarClientes (tipoCliente vetorClientes[MAX], int quantClientes)
{
    int i;

    if (quantClientes > 0)
    {
        printf("\n\n*********** LISTAGEM dos CLIENTES ***********\n\n");
        for (i=0; i < quantClientes; i++)
        {
            escreverCliente(vetorClientes[i]);
        }
    }
    else
    {
        printf("\n\nATENCAO: Nao existem clientes inseridos.\n\n");
    }
}


// Função que escreve no ecra os dados de um cliente
void escreverCliente (tipoCliente cliente)
{
    printf("\n\nContribuinte: %9d\t\tNome: %s\n", cliente.numContribuinte, cliente.nome);
    printf("Telefone: %13d\t\tMorada: %s\n", cliente.telefone, cliente.morada);
}



/** ------------------- Funções dos FICHEIROS ------------------- **/


void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes, tipoAgendamento *vetorAgendamentos, int quantAgendamentos, tipoVisita *vetorVisita, int quantVisitas)
{
    FILE *ficheiro;
    int quantValoresEscritos;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        // Write quantity of clients
        quantValoresEscritos = fwrite(&quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresEscritos != 1)
        {
            printf("\n\nERRO: falha na escrita da quantidade de clientes\n\n");
        }
        else
        {
            // Write cliente data
            quantValoresEscritos = fwrite(vetorClientes, sizeof(tipoCliente), quantClientes, ficheiro);
            if (quantValoresEscritos != quantClientes)
            {
                printf("\n\nERRO: falha na escrita dos dados dos clientes\n\n");
            }

            // Write quantity of agendamentos (if any)
            quantValoresEscritos = fwrite(&quantAgendamentos, sizeof(int), 1, ficheiro);
            if (quantValoresEscritos != 1)
            {
                printf("\n\nERRO: falha na escrita da quantidade de agendamentos\n\n");
            }
            else if (quantAgendamentos > 0)
            {
                // Write agendamento data
                quantValoresEscritos = fwrite(vetorAgendamentos, sizeof(tipoAgendamento), quantAgendamentos, ficheiro);
                if (quantValoresEscritos != quantAgendamentos)
                {
                    printf("\n\nERRO: falha na escrita dos dados dos agendamentos\n\n");
                }
            }

            // Write quantity of visitas (if any)
            quantValoresEscritos = fwrite(&quantVisitas, sizeof(int), 1, ficheiro);
            if (quantValoresEscritos != 1)
            {
                printf("\n\nERRO: falha na escrita da quantidade de visitas\n\n");
            }
            else if (quantVisitas > 0)
            {
                // Write visita data
                quantValoresEscritos = fwrite(vetorVisita, sizeof(tipoVisita), quantVisitas, ficheiro);
                if (quantValoresEscritos != quantVisitas)
                {
                    printf("\n\nERRO: falha na escrita dos dados das visitas\n\n");
                }
            }
        }

        fclose(ficheiro);
    }
}


void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes, tipoAgendamento **vetorAgendamentos, int *quantAgendamentos, tipoVisita **vetorVisita, int *quantVisitas)
{
    FILE *ficheiro;
    int quantValoresLidos, erro = 0;

    ficheiro = fopen("dados.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        // Read quantity of clients
        quantValoresLidos = fread(quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresLidos != 1)
        {
            printf("\n\nERRO: falha na leitura da quantidade de clientes\n\n");
            erro = 1;
        }
        else
        {
            // Read cliente data
            quantValoresLidos = fread(vetorClientes, sizeof(tipoCliente), *quantClientes, ficheiro);
            if (quantValoresLidos != *quantClientes)
            {
                printf("\n\nERRO: falha na leitura dos dados dos clientes\n\n");
                erro = 1;
            }

            // Read quantity of agendamentos (if any)
            quantValoresLidos = fread(quantAgendamentos, sizeof(int), 1, ficheiro);
            if (quantValoresLidos != 1)
            {
                printf("\n\nCuidado: falha na leitura da quantidade de agendamentos. Considerando 0 agendamentos.\n\n");
                *quantAgendamentos = 0;
            }
            else if (*quantAgendamentos > 0)
            {
                // Allocate memory for agendamento data
                *vetorAgendamentos = (tipoAgendamento *)malloc((*quantAgendamentos) * sizeof(tipoAgendamento));
                if (*vetorAgendamentos == NULL)
                {
                    printf("\n\nERRO: falha na alocação de memória para agendamentos\n\n");
                    erro = 1;
                }
                else
                {
                    // Read agendamento data
                    quantValoresLidos = fread(*vetorAgendamentos, sizeof(tipoAgendamento), *quantAgendamentos, ficheiro);
                    if (quantValoresLidos != *quantAgendamentos)
                    {
                        printf("\n\nERRO: falha na leitura dos dados dos agendamentos\n\n");
                        erro = 1;
                    }
                }
            }

            // Read quantity of visitas (if any)
            quantValoresLidos = fread(quantVisitas, sizeof(int), 1, ficheiro);
            if (quantValoresLidos != 1)
            {
                printf("\n\nCuidado: falha na leitura da quantidade de visitas. Considerando 0 visitas.\n\n");
                *quantVisitas = 0;
            }
            else if (*quantVisitas > 0)
            {
                // Allocate memory for visita data
                *vetorVisita = (tipoVisita *)malloc((*quantVisitas) * sizeof(tipoVisita));
                if (*vetorVisita == NULL)
                {
                    printf("\n\nERRO: falha na alocação de memória para visitas\n\n");
                    erro = 1;
                }
                else
                {
                    // Read visita data
                    quantValoresLidos = fread(*vetorVisita, sizeof(tipoVisita), *quantVisitas, ficheiro);
                    if (quantValoresLidos != *quantVisitas)
                    {
                        printf("\n\nERRO: falha na leitura dos dados das visitas\n\n");
                        erro = 1;
                    }
                }
            }
        }

        if (erro == 1)
        {
            *quantClientes = 0;
            free(*vetorAgendamentos);
            *quantAgendamentos = 0;
            free(*vetorVisita);
            *quantVisitas = 0;
        }

        fclose(ficheiro);
    }
}



/*
void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes)
{
    FILE *ficheiro;
    int quantValoresEscritos;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresEscritos = fwrite(&quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresEscritos != 1)
        {
            printf("\n\nERRO: falha na escrita da quantidade de clientes\n\n");
        }
        else
        {
           quantValoresEscritos = fwrite(vetorClientes, sizeof(tipoCliente), quantClientes, ficheiro);
           if (quantValoresEscritos != quantClientes)
           {
               printf("\n\nERRO: falha na escrita dos dados dos clientes\n\n");
           }
        }

        fclose(ficheiro);
    }
}


void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes)
{
    FILE *ficheiro;
    int quantValoresLidos, erro = 0;

    ficheiro = fopen("dados.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresLidos = fread(quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresLidos != 1)
        {
            printf("\n\nERRO: falha na leitura da quantidade de clientes\n\n");
            erro = 1;
        }
        else
        {
           quantValoresLidos = fread(vetorClientes, sizeof(tipoCliente), *quantClientes, ficheiro);
           if (quantValoresLidos != *quantClientes)
           {
               printf("\n\nERRO: falha na leitura dos dados dos clientes\n\n");
               erro = 1;
           }

        }

        if (erro == 1)
        {
            *quantClientes = 0;
        }

        fclose(ficheiro);
    }
}
*/
/** ----------------------- Funções dos MENUS ------------------------- **/

int menu(int totalClientes)
{
    int opcao;

    printf("\n\n---------------- TECNICO DE REPARACOES - AGENDA ----------------\n\n");
    printf("Total de Clientes: %d\n\n", totalClientes);
    printf("\t1 - Clientes\n\t2 - Agendamentos\n\t3 - Estatisticas\n\t4 - Ficheiros\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 4);

    return opcao;
}

int menuClientes(void)
{
    int opcao;

    printf("\n\n--------------------- MENU CLIENTES --------------------------\n\n");
    printf("\t1 - Adicionar novo cliente\n\t2 - Listar Clientes\n\t3 - Listar Clientes e respetivos agendamentos\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 3);

    return opcao;
}


int menuAgendamentos(void)
{
    int opcao;

    printf("\n\n------------------- MENU AGENDAMENTOS ------------------------\n\n");
    printf("\t1 - Adicionar novo agendamento\n\t2 - Registar Visita\n\t3 - Consultar Agendamentos (por data)\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 3);

    return opcao;
}


int menuEstatisticas(void)
{
    int opcao;

    printf("\n\n------------------- MENU ESTATISTICAS ------------------------\n\n");
    printf("\t1 - Melhor(es) Cliente(s)\n\t2 - Percentagens por grau de satisfacao dos clientes\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 2);

    return opcao;
}


int menuFicheiros(void)
{
    int opcao;

    printf("\n\n------------------- MENU FICHEIROS ------------------------\n\n");
    printf("\t1 - Guardar no ficheiro\n\t2 - Ler do ficheiro\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 2);

    return opcao;
}


