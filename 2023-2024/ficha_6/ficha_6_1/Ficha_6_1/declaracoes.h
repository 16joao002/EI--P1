#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

#define LONG_CHAR 80
#define MAX_ESTUDANTES 100
#define SHORT_CHAR 20

typedef struct
{
    int dia;
    int mes;
    int ano;
}tipoData;

typedef struct
{
    int numero;
    char nome[LONG_CHAR];
    float nota;
    tipoData dataAval;
}tipoEstudante;


#endif // DECLARACOES_H_INCLUDED
