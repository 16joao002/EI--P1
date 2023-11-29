#ifndef FUNCOESPRINCIPAIS_H_INCLUDED
#define FUNCOESPRINCIPAIS_H_INCLUDED

tipoEstudante lerDadosEstudantes();
int leQuantidadeEstudantes();
int acrescentaEstudantes(tipoEstudante estudantes[MAX_ESTUDANTES], int quantidadeEstudantes);
void leNotas(tipoEstudante estudantes[MAX_ESTUDANTES], int quantidadeEstudantes, int *contadorAvalidados, float *percPositivas);
int procurarEstudante(tipoEstudante estudante[MAX_ESTUDANTES], int quantidadeEstudantes, int numeroEstudante);
void mostrarDados(tipoEstudante estudante[MAX_ESTUDANTES], int quantidadeEstudantes);

#endif // FUNCOESPRINCIPAIS_H_INCLUDED
