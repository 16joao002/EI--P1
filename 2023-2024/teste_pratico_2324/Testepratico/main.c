#include <stdio.h>
#include <stdlib.h>
#include "funcoesAuxiliares.h"

#define MAX_FUNCIONARIOS 50

typedef struct
{
    int numero;
    char nome[MAX_CHAR];
    float venc;
    tipoData dataAdm;
} tipoFuncionario;

int menu(int *quantidadeFuncionarios, float *mediaVenc, int *quantidadeFuncNovem);
int procuraFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios, int numero);
void adicionarFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int *quantidadeFuncionarios, int *quantidadeFuncNovem);
void listarFuncionarios(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int *quantidade);
void mostrarDadosFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios);
void calculaVencimentos(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios, int *contadorVenc1000, float *mediaVenc);

int main()
{
    int contadorVenc1000, quantidadeFuncNovem, opc, quantidadeFuncionarios;
    float mediaVenc;

    tipoFuncionario funcionarios[MAX_FUNCIONARIOS] = {0};
    quantidadeFuncionarios = 0;
    mediaVenc = 0;
    quantidadeFuncNovem = 0;
    contadorVenc1000 = 0;

    do
    {
        opc = menu(&quantidadeFuncionarios, &mediaVenc, &quantidadeFuncNovem);
        switch(opc)
        {
        case 1:
            //Novo funcionario
            adicionarFuncionario(funcionarios, &quantidadeFuncionarios, &quantidadeFuncNovem);
            break;
        case 2:
            //Listar todos os funcionarios
            listarFuncionarios(funcionarios, &quantidadeFuncionarios);
            break;
        case 3:
            //Mostrar apenas um funcionario
            mostrarDadosFuncionario(funcionarios, quantidadeFuncionarios);
            break;
        case 4:
            //percentagem de funcionarios com 1000 de venc
            calculaVencimentos(funcionarios,quantidadeFuncionarios, &contadorVenc1000, &mediaVenc);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
        }
    }
    while(opc != 0);
    return 0;
}

int menu(int *quantidadeFuncionarios, float *mediaVenc, int *quantidadeFuncNovem)
{
    int opc;
    printf("************ MENU ************\n");
    printf("\nQuantidade Funcionarios: %d\t\tMedia de vencimentos mensais: %.2f\n", *quantidadeFuncionarios, *mediaVenc);
    printf("\nQuantidade de Funcionarios admitidos no mes de novembro: %d\n", *quantidadeFuncNovem);
    printf("1 - Novo Funcionario\n");
    printf("2 - Listar dados funcionario\n");
    printf("3 - Mostrar dados funcionario(indiv)\n");
    printf("4 - Percentagem funcionarios com vencimento superior a 1000$\n");
    printf("0 - Sair\n");
    scanf("%d", &opc);
    return opc;
}

void adicionarFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int *quantidadeFuncionarios, int *quantidadeFuncNovem, int )
{
    if (*quantidadeFuncionarios == MAX_FUNCIONARIOS)
    {
        printf("\nLimite de funcionarios excedido!!\n");
    }
    else
    {
        printf("\nInsira os dados dos funcionarios\n");

        int numero, posicao;
        numero = lerInteiro("Insira o numero do funcionario: ", 1, 9999);

        posicao = procuraFuncionario(funcionarios, *quantidadeFuncionarios, numero);
        if (posicao == -1)
        {
            lerString("Nome:", funcionarios[*quantidadeFuncionarios].nome, 80);
            funcionarios[*quantidadeFuncionarios].numero = numero;
            funcionarios[*quantidadeFuncionarios].venc = lerFloat("Vencimento:",1, 9999);
            funcionarios[*quantidadeFuncionarios].dataAdm = lerData();
            if(funcionarios[*quantidadeFuncionarios].dataAdm.mes == 11)
            {
                (*quantidadeFuncNovem)++;
            }
            (*quantidadeFuncionarios)++;
        }
        else
        {
            printf("\nFuncionario com o número %d ja existe.\n", numero);
        }
    }
}


void listarFuncionarios(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int *quantidadeFuncionarios)
{
    int i;
    if (*quantidadeFuncionarios > 0 && *quantidadeFuncionarios < MAX_FUNCIONARIOS)
    {
        for(i = 0; i < *quantidadeFuncionarios; i++)
        {
            printf("\n-----------------------------------\n");
            printf("\nNome: %s\n", funcionarios[i].nome);
            printf("\nNumero: %d\n", funcionarios[i].numero);
            printf("\nVencimento: %.2f\n", funcionarios[i].venc);
            printf("\nData de Admissao: %d/%d/%d\n", funcionarios[i].dataAdm.dia, funcionarios[i].dataAdm.mes, funcionarios[i].dataAdm.ano);
        }
    }
    else
    {
        printf("\n Nao existem funcionarios!\n");
    }
}


int procuraFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios, int numero)
{
    int posicao, i;
    posicao = -1;

    for(i=0; i< quantidadeFuncionarios; i++)
    {
        if(funcionarios[i].numero == numero)
        {
            posicao = i;
        }
    }
    return posicao;
}


void mostrarDadosFuncionario(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios)
{
    int posicao, numero;
    printf("Introduza o numero do funcionario que pretende visualizar os dados:\n");
    numero = lerInteiro("Numero:", 0, 9999);

    posicao = procuraFuncionario(funcionarios, quantidadeFuncionarios, numero);
    if (posicao == -1)
    {
        printf("Funcionario inexistente!\n");
    }
    else
    {
        printf("\nNome: %s\n", funcionarios[posicao].nome);
        printf("\nNumero: %d\n", funcionarios[posicao].numero);
        printf("\nVencimento: %.2f\n", funcionarios[posicao].venc);
        printf("\nData de Admissao: %d/%d/%d\n", funcionarios[posicao].dataAdm.dia, funcionarios[posicao].dataAdm.mes, funcionarios[posicao].dataAdm.ano);
    }

}


void calculaVencimentos(tipoFuncionario funcionarios[MAX_FUNCIONARIOS], int quantidadeFuncionarios, int *contadorVenc1000, float *mediaVenc)
{
    int i, somaVenc;
    float superior1000;
    somaVenc = 0;
    *contadorVenc1000 = 0;
    if(quantidadeFuncionarios > 0 && quantidadeFuncionarios < MAX_FUNCIONARIOS)
    {
        for(i=0; i <quantidadeFuncionarios; i++)
        {
            somaVenc += funcionarios[i].venc;
            if (funcionarios[i].venc >= 1000)
            {
                (*contadorVenc1000)++;
            }
        }

        //*mediaVenc = (float)somaVenc/quantidadeFuncionarios;

        superior1000 = (float)*contadorVenc1000*100/(quantidadeFuncionarios);

        //printf("\nA media dos vencimentos e %.2f.\n", *mediaVenc);
        printf("Existem %.2f(%%) com o vencimento igual ou superior a 1000 euros.\n", superior1000);
    }
    else
    {
        printf("Erro - Nao existem funcionarios\n\n");
    }
}
