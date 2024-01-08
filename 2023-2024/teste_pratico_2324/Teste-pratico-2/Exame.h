#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

#define CUSTO_MAX 500
#define CUSTO_MIN 50

typedef struct{
    int id;
    int numContribuinte;
    tipoData data;
    tipoHorario horario;
    char descricao[TEXTO_LONGO];
    float custo;
    int grauSatisfacao;
}tipoAgendamento;

tipoAgendamento inserirNovoAgendamento(tipoAgendamento *vetorAgendamentos,int *quantidadeAgendamentos,tipoCliente clientes[MAX], int quantidadeClientes);
int procurarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoData data, tipoHorario horario);

#endif // EXAME_H_INCLUDED
