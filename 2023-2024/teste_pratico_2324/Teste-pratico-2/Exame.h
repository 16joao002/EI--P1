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

void inserirNovoAgendamento(tipoAgendamento *vetorAgendamentos,int *quantidadeAgendamentos,tipoCliente clientes[MAX], int quantidadeClientes);
int procurarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoData data, tipoHorario horario);
void registarVisita(tipoAgendamento *vetorAgendamentos, int *quantidadeAgendamentos, tipoCliente clientes[MAX], int quantidadeClientes, int *quantidadeVisitas);
void consultarAgendamento(tipoAgendamento *vetorAgendamentos, int quantidadeAgendamentos, tipoCliente cliente[MAX], int quantidadeClientes);
void melhoresClientes(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *agendamentos, int quantidadeAgendamentos);
void percSatisfacao(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *agendamentos, int quantidadeAgendamentos);
void escreverAgendamento(tipoAgendamento *vetorAgendamento);

#endif // EXAME_H_INCLUDED
