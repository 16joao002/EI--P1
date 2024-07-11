#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesAuxiliares.h"
#include "funcoesPrincipais.h"
#include "ficheiros.h"

int main()
{
    int quantidadePortateis = 0;
    int portateisDisponiveis = 0;
    int quantidadeRequisicoes = 0;
    int quantidadeRequesicoesAtivas = 0;
    int quantidadeAvarias = 0;
    int reqAtivas = 0;

    tipoPc portateis[MAX_PORTATIL];
    tipoRequisicao arrayReq[MAX_PORTATIL];

    setlocale(LC_ALL,"");

    //lerFicheiroBinario();

    char op;

    do{
      op = menu(&quantidadePortateis, &portateisDisponiveis, &quantidadeRequisicoes, &reqAtivas);
      limpaBufferStdin();
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
            requisitarPortatil(portateis, &quantidadePortateis, arrayReq, &quantidadeRequisicoes, &reqAtivas);
            break;
        case 'E'://renovar requisicao
            renovarPortatil(portateis,quantidadePortateis,arrayReq);
            break;
        case 'F'://listar requisicoes
            listarRequisicao(portateis,arrayReq,quantidadePortateis,quantidadeRequisicoes);
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
            registarDevolucao(portateis,quantidadePortateis, &reqAtivas);
            break;
        case 'K'://registar reparacao
            registarReparacao(portateis, quantidadePortateis, arrayReq);
            break;
        case 'L'://Armazenar informação portateis e requisicoes em ficheiro binario
            gravarFicheiroBinario(portateis, quantidadePortateis, arrayReq, quantidadeRequisicoes);
            break;
        case 'M'://Mostrar (ler) dados armazenados em ficheiro binarios
            quantidadeAvarias = leFicheiroBinario(portateis);
            break;
        case 'N'://dados estatisticos
            dadosEstatisticos(portateis,quantidadePortateis,quantidadeRequisicoes);
            break;
        case 'S':// SAIR
            printf("A sair.......");
            break;
        default:
            printf("ERRO | OPCAO INVALIDA\n");
            pressionarContinuar();
        }
    }while(op != 'S');
}

//funcoes auxiliares e depois fazer por ordem as funcoes do menu

