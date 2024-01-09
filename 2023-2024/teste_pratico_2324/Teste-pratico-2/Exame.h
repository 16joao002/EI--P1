#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

typedef struct
{
    int codigo;
    int numContribuinte;
    tipoData diaVisita;
    tipoHorario horaVisita;
    char descricaoProblema [TEXTO_LONGO];
    int quantidadeAgendamentos;
} tipoAgendamento;

typedef struct
{
    int codigo;
    float custo;
    char satisfacaoCliente[TEXTO_LONGO];
} tipoVisita;

tipoAgendamento *inserirAgendamentos (tipoAgendamento *vetorAgendamentos,tipoCliente cliente[MAX], int *quantAgendamentos, int quantClientes, tipoVisita *vetorVisitas);
int gerarId ();
void listarClientesAgendamentos (tipoCliente vetorClientes[MAX],tipoAgendamento *vetorAgendamentos,tipoVisita *visita, int quantClientes, int quantAgendamentos);
void escreverAgendamentos (tipoAgendamento agendamento, tipoData data);
int procurarCliente (tipoCliente vetorClientes[MAX], int quantCliente, int numContribuinte);
void escreverData (tipoData data);
void escreverHora (tipoHorario hora);
tipoVisita *registarVisita (tipoVisita *vetorVisita,tipoAgendamento *vetorAgendamentos, int quantAgendamentos, int *quantVisitas);
void consultaAgendamento(tipoAgendamento *vetorAgendamento, int quantAgendamentos, tipoCliente vetorClientes[MAX]);
int procurarData(tipoAgendamento *vetorAgendamento, int quantAgendamentos);
void listarAgendamentos(tipoCliente vetorClientes[MAX], int quantClientes, tipoAgendamento *vetorAgendamento, int quantAgendamentos);
void escreverAgendamento(tipoAgendamento agendamento, tipoVisita visita);
void percentagemSatisfacao(tipoVisita *visita, int quantclientes, int *quantVisitas);
void melhorCliente (tipoCliente vetorClientes[MAX],tipoAgendamento *vetorAgendamentos, int quantClientes, int quantAgendamentos);
void consultaAgendamentoData(tipoAgendamento *vetorAgendamentos, int quantAgendamentos, tipoCliente vetorClientes[MAX]);

#endif
