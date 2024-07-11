#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

///Declaracoes de estruturas

typedef struct
{
    int dia, mes, ano;

}tipoData;


typedef struct
{
    int horas, minutos;
}tipoHorario;


typedef struct
{
    int contribuinte;
    char nome[80];
    char morada[80];
    int contactoTele;
    tipoData data;

}tipoCliente;

typedef struct
{
    tipoData data;
    tipoHorario horario;
    int grauSatis;
    char descricao[500];
    int custo;

}tipoAgendamento;

typedef struct
{
    tipoData data;

}tipoDias;


///Declaracoes de constantes
#define MIN_CONTRIBUINTE 111111111

#define MAX_CONTRIBUINTE 999999999

#define MIN_TELE 111111111

#define MAX_TELE 999999999

#define CLIENTES "cliente"

#define AGENDAMENTO "agendamento"

#define MAX 150

#endif // DECLARACOES_H_INCLUDED
