#ifndef FUNCOES_PRINCIPAIS_H
#define FUNCOES_PRINCIPAIS_H

#include "estruturas.h"
#include "constantes.h"

///PROTOTIPOS
tipoPc infoPc();
void adicionarPortatil(tipoPc arrayPC[MAX_PORTATIL],int *quantidade);
void infoPortatil();
void dadosEstatisticos(tipoPc arrayPc[MAX_PORTATIL],int quantidade, int quantidadeReq);
void registarDevolucao(tipoPc arrayPc[MAX_PORTATIL],int quantidade, int *reqAtivas);
void registarAvaria(tipoPc arrayPc[MAX_PORTATIL], int quantidade);
void alterarLocalizacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade);
void listarRequisicao(tipoPc arrayPc[MAX_PORTATIL], tipoRequisicao arrayReq[MAX_PORTATIL], int quantidade, int quantidadeReq);
void listarPortatil(tipoPc arrayPc[MAX_PORTATIL], int quantidade);
void listarAvaria(tipoPc arrayPc[MAX_PORTATIL], int quantidade);
void requisitarPortatil(tipoPc arrayPC[MAX_PORTATIL],int *quantidade,tipoRequisicao arrayReq[MAX_PORTATIL], int *contadorReq, int *reqAtivas);
void renovarPortatil(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL]);
void registarReparacao(tipoPc arrayPc[MAX_PORTATIL],int quantidade, tipoRequisicao arrayReq[MAX_PORTATIL]);




#endif // FUNCOES_PRINCIPAIS_H
