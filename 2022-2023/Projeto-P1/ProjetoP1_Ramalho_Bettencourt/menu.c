#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"
#include "ficheiros.h"


char menu(int *quantidadePortateis, int *portateisDisponiveis, int *quantidadeRequisicoes, int *quantidadeRequisicoesAtivas){
    char op;
    printf("================================================| Bem vindo |===========================================================\n");
    printf("============================| GRCP |  Gestao da Requisicao de Computadores Portateis |==================================\n");
    printf("========================================================================================================================\n");
    printf("=============================================| Menu Principal |=========================================================\n");
    printf("========================================================================================================================\n");
    printf("Portateis existentes: %d\t\t\t\t\t\t\tNumero Total de requisicoes efetuadas: %d", *quantidadePortateis, *quantidadeRequisicoes);
    printf("\nPortateis disponiveis: %d\t\t\t\t\t\t\tNumero de requisicoes ativas: %d", *portateisDisponiveis, *quantidadeRequisicoesAtivas);
    printf("\n\n[A]Adicionar Portatil");
    printf("\n[B]Listar Portateis");
    printf("\n[C]Alterar Localizacao de um portatil");
    printf("\n[D]Requesitar um Portatil");
    printf("\n[E]Renovar requisicao de um portatil");
    printf("\n[F]Listar requesicoes");
    printf("\n[G]Informacao de uma requisicao");
    printf("\n[H]Registar Avaria");
    printf("\n[I]Listar Avarias");
    printf("\n[J]Registar devolucao");
    printf("\n[K]Registar reparacao");
    printf("\n[L]Armazenar informação portateis e requisicoes em ficheiro binario");
    printf("\n[M]Mostrar (ler) dados armazenados em ficheiro binarios ");
    printf("\n[N]Dados Estatisticos");
    printf("\n[S] SAIR");
    printf("\nOpcao >> ");
    op = getchar();
    op = toupper(op);
    return op;

    do{
      op = menu(&quantidadePortateis, &portateisDisponiveis, &quantidadeRequesicoes, &quantidadeRequesicoesAtivas);
        switch(op){
        case 'A'://adicionar portatil
            adicionarPortatil(portateis,&quantidadePortateis);
            break;
        case 'B'://listar portateis
            listarPortatil(portateis, quantidadePortateis);
            break;
        case 'C'://alterar localizacao portatil
            alterarLocalizacao(portateis, quantidadePortateis);
            break;
        case 'D'://requisitar um portatil
            requisitarPortatil(portateis, &quantidadePortateis, arrayReq, &quantidadeRequesicoes);
            break;
        case 'E'://renovar requisicao
            renovarPortatil(portateis,quantidadePortateis,arrayReq);
            break;
        case 'F'://listar requisicoes
            listarRequesicao(portateis,arrayReq,quantidadePortateis,quantidadeRequesicoes);
            break;
        case 'G'://informacao de uma requisicao
            break;
        case 'H'://registar avaria
            registarAvaria(portateis, quantidadePortateis);
            break;
        case 'I'://listar avarias
            listarAvaria(portateis,quantidadePortateis);
            break;
        case 'J'://registar devolucao
            registarDevolucao(portateis,quantidadePortateis);
            break;
        case 'K'://registar reparacao
            registarReparacao(portateis, quantidadePortateis, arrayReq);
            break;
        case 'L'://Armazenar informação portateis e requisicoes em ficheiro binario
            gravarFicheiroBinario(portateis, quantidadePortateis, arrayReq, quantidadeRequesicoes);
            break;
        case 'M'://Mostrar (ler) dados armazenados em ficheiro binarios
            quantidadeAvarias=leFicheiroBinario(portateis);
            break;
        case 'N'://dados estatisticos
            dadosEstatisticos(portateis);
            break;
        case 'S':// SAIR
            printf("A sair.......");
            break;
        default:
            printf("ERRO | OPCAO INVALIDA\n");
        }
    }while(op != 'S');
}
