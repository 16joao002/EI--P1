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

//inserir agendamento
tipoAgendamento inserirNovoAgendamento(tipoAgendamento *vetorAgendamento,int *quantidadeAgendamentos,tipoCliente clientes[MAX], int quantidadeClientes);
//procurar
int procurarAgendamento(tipoAgendamento *vetorAgendamento, int *quantidadeAgendamentos, tipoData data, tipoHorario horario);
//visita
void registarVisita(tipoAgendamento *vetorAgendamento, int *quantidadeAgendamentos, tipoCliente clientes[MAX], int quantidadeClientes, int *quantidadeVisitas);
//consultar
void consultarAgendamento(tipoAgendamento *vetorAgendamento, int quantidadeAgendamentos, tipoCliente cliente[MAX], int quantidadeClientes);
//melhores cleintes
void melhoresClientes(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *vetorAgendamento, int quantidadeAgendamentos);
//satisfacao
void percSatisfacao(tipoCliente clientes[MAX], int quantidadeClientes, tipoAgendamento *vetorAgendamento, int quantidadeAgendamentos);
//escrever agendamento
void escreverAgendamento(tipoAgendamento *vetorAgendamento);

#endif // EXAME_H_INCLUDED
