#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include "constantes.h"

typedef struct{
    int dia,mes,ano;
}tipoData;

typedef struct{
    int id;
    int processador; //ENUM 0-I3 1-I5 2-I7
    char designacao[MAX_STRING];
    int ram; //ENUM 0-4 1-8 2-16 3-32
    int estado; //ENUM 0- disponivel 1- requisitado 2- avariado
    int localizacao; //ENUM 0- residencias 1- campus1 2- campus2 3-campus5
    int tipoUtente; //ENUM 0 - Estudante  1 - Docente  2 - Tecnico administrativo)
    tipoData dataAquisicao;
    float valor;
    int quantAvarias;
    int diasRequi;
    int quantRequisicoes;
    int tipoAvarias;
}tipoPc;

typedef struct{
    char cod[5];
    int id;
    char nomeUtente[MAX_STRING];
    int tipoUtente; //ENUM 0-estudante 1-docente  2-t�cnico administrativo
    tipoData dataRequisicao;
    int prazo; //if(prazo <= 30) TA CERTO else ERRADO
    int estadoRequisicao; //ENUM 0-ativa 1-concluida
    int localDevolucao; //ENUM  0- residencias 1- campus1 2- campus2 3-campus5
    float multa;
    tipoData dataDevolucao;
}tipoRequisicao;

#endif // ESTRUTURAS_H
