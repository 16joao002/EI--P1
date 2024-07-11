#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include "estruturas.h"
#include "constantes.h"


///PROTOTIPOS
char menu(int *quantidadePortateis, int *portateisDisponiveis, int *quantidadeRequisicoes, int *quantidadeRequisicoesAtivas);
int procurarRequisicao(tipoPc arrayPc[MAX_PORTATIL], tipoRequisicao arrayReq[MAX_PORTATIL],int quantidade, int id);
int procurarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade, int id);
int lerProcessador();
int lerEstado();
int lerLocalizacao();
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
tipoData lerData();
void limpaBufferStdin(void);
void pressionarContinuar();
void limpaEcra();
int verificaMenor(int primeira,int segunda, int terceira);

#endif // FUNCOES_AUXILIARES_H
