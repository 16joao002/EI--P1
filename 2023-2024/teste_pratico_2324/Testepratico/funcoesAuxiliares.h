#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED

#define MAX_CHAR 80

int lerInteiro (char msg[MAX_CHAR], int limMin, int limMax);
float lerFloat (char msg[MAX_CHAR], float limMin, float limMax);
void lerString(char msg[MAX_CHAR], char str[MAX_CHAR], int tamanho);
void limparBuffer (void);
void pressionarContinuar();
void erro(int numErro, char msg[MAX_CHAR]);
void limparEcra();

#endif // FUNCOESAUXILIARES_H_INCLUDED
