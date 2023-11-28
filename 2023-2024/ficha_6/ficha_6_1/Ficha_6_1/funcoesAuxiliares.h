#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED



int lerInteiro (char msg[LONG_CHAR], int limMin, int limMax);
float lerFloat (char msg[LONG_CHAR], float limMin, float limMax);
void lerString(char msg[LONG_CHAR], char str[LONG_CHAR], int tamanho);
void limparBuffer (void);
void pressionarContinuar();
void erro(int numErro, char msg[LONG_CHAR]);
void limparEcra();
tipoData lerData (void);

#endif // FUNCOESAUXILIARES_H_INCLUDED
