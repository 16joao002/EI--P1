#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 25
#define MAX_CARACTERES 200


void leQuantidadeAvaliados(int *quantidadeAlunos);
void erro();
void leNotas(int quantidadeAlunos, int alunos[MAX_ALUNOS]);

int main()
{
    int alunos[MAX_ALUNOS], quantidadeAlunos = 0;
    leQuantidadeAvaliados(&quantidadeAlunos);
    leNotas(quantidadeAlunos, alunos);
    return 0;
}

void leQuantidadeAvaliados(int *quantidadeAlunos)
{
    do
    {
    printf("Introduza a quantidade de alunos avaliados:");
    scanf("%d", &*quantidadeAlunos);
    if(*quantidadeAlunos > MAX_ALUNOS)
    {
        erro("Erro - numero de alunos superior a 25");
    }
    }
    while(*quantidadeAlunos>25 && *quantidadeAlunos < 0);
}

void leNotas(int quantidadeAlunos, int alunos[MAX_ALUNOS])
{
    for(int i = 0; i<quantidadeAlunos; i++)
    {
        printf("\nIntroduza a nota do %d aluno:", i+1);
        scanf("%d", &alunos[i]);
    }
}

void erro(char mensagem[MAX_CARACTERES])
{
    printf(mensagem);
}
/*
c) A função lerNotas() que solicite ao utilizador, e obtenha, as notas finais dos
estudantes avaliados.

d) A função mostrarDados() que apresente no monitor as notas dos estudantes
avaliados.

e) A função calculaMedia() que calcule, e devolva, a média das notas obtidas
pelos estudantes.

f) A função alteraNota() que permita alterar uma determinada nota.
*/
