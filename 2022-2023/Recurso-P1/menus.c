#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "declaracoes.h"
#include "funcoesaux.h"

//----------Funcoes dos Menus----------

int menuPrinc(int *quantidadeAgendamentos, int *quantidadeVisitas)
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("----------------------------Tecnico de Reparacoes----------------------------\n\n");
    printf("Total de agendamentos: %d \t Total de visitas realizadas: %d \n\n", *quantidadeAgendamentos, *quantidadeVisitas);
    printf("\n\t1 - Menu Clientes");
    printf("\n\t2 - Menu Agendamentos");
    printf("\n\t3 - Menu Ficheiros");
    printf("\n\t4 - Menu Estatistica");
    printf("\n\t5 - Sair");
    printf("\n\nOpcao--> ");

    scanf("%d", &opc);

    return opc;
}


int menuClientes()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    printf("\t\tMenu Clientes\n");
    printf("\n\t1 - Adicionar Novo Cliente");
    printf("\n\t2 - Listar Clientes");
    printf("\n\t3 - Listar Clientes e respetivos agendamentos");
    printf("\n\t4 - Voltar");

    opc = lerInteiro("\nOpcao",1,4);

    return opc;
}

int menuFicheiros()
{
    //Declaracao de variaveis
    int opc;

    //Menu
    while (opc != 3)
    {
    printf("\t\tMenu Ficheiros\n");
    printf("\n\t1 - Guardar Ficheiro");
    printf("\n\t2 - Ler Ficheiro");
    printf("\n\t3 - Voltar");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }

    return opc;
}

int menuEstatistico()
{
    //Declaracao de variaveis
    int opc;

    //Menu

    while (opc != 3)
    {
    printf("\t\tMenu Estatistico\n");
    printf("\n\t1 - Melhores Clientes");
    printf("\n\t2 - Percentagem com grau de satisfacao");
    printf("\n\t3 - Voltar");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }
    return opc;
}

int menuAgendamento()
 {
    //Declaracao de variaveis
    int opc;

    //Menu
    while(opc != 4)
    {
    printf("\t\tMenu Agendamento\n");
    printf("\n\t1 - Adicionar Novo Agendamento");
    printf("\n\t2 - Registar visita");
    printf("\n\t3 - Consultar Agendamentos (por data)");
    printf("\n\t4 - Voltar");
    printf("\nOpcao--> ");

    scanf("%d", &opc);
    }
    return opc;
 }
