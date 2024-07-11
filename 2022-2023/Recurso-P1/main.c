//------------Bibliotecas utilizadas------------

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "declaracoes.h"
#include "funcoesaux.h"
#include "menus.h"

//----------Main----------

int main()
{
    tipoCliente cliente[MAX];
    tipoAgendamento agendamento[MAX];
    int quantidadeCliente = 0, opcao, quantidadeAgendamentos = 0, quantidadeVisitas = 0, opcSubMenu;

    do{
        opcao = menuPrinc(&quantidadeAgendamentos, &quantidadeVisitas);

        switch(opcao)
        {
            case 1:
                opcSubMenu = menuClientes();

                switch (opcSubMenu)
                {
                    case 1:
                        inserirCliente(cliente, &quantidadeCliente);
                    break;

                    case 2:
                        listarClientes(cliente, quantidadeCliente);
                    break;

                    case 3:
                        listarClienteData(cliente, quantidadeCliente, agendamento);
                    break;
                }
                break;

            case 2:
                    opcSubMenu = menuAgendamento();

                    switch (opcSubMenu)
                {
                    case 1:
                        adicionarAgendamento( &quantidadeCliente, &quantidadeAgendamentos, cliente, agendamento);
                    break;

                    case 2:

                    break;
                }
            break;


            case 3:
                opcSubMenu = menuFicheiros();

                switch (opcSubMenu)
                {
                    case 1:
                       escreverFicheiroBinario(cliente, quantidadeCliente);
                    break;

                    case 2:
                        lerFicheiroBinario(cliente, &quantidadeCliente);
                    break;
                }
            break;

            case 4:
                opcSubMenu = menuEstatistico();

                switch (opcSubMenu)
                {
                case 1:
                  //  melhoresClientes();
                break;

                case 2:
                   // percentagemSatisfacao();
                break;
                }
            break;

            default:
            break;
        }
    } while(opcao < 5);

    return 0;
}
