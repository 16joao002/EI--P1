#include <stdlib.h>
#include <stdio.h>

#include "funcoesPrincipais.h"

void gravarFicheiroBinario(tipoPc portateis[MAX_PORTATIL], int quantidadePortateis, tipoRequisicao* requisicao, int quantidadeRequisicoes) {
    FILE *file;

    file = fopen("dados.dat", "wb");

    if(file != NULL) {
            fwrite(&quantidadePortateis, sizeof(int), 1, file);
            fwrite(&quantidadeRequisicoes,sizeof(int),1,file);
            fwrite(requisicao,sizeof(int),1,file);
            fwrite(portateis, sizeof(tipoPc), quantidadePortateis, file);
            fclose(file);
    } else {
        printf("\nERRO AO ABRIR O FICHEIRO\n\n");
    }
}

int leFicheiroBinario(tipoPc arrayPc[])
{
    FILE *ficheiro_portateis;
    int tamanho, lido;
    ficheiro_portateis = fopen("dados.dat", "rb");

    if(ficheiro_portateis != NULL)
    {
        lido = fread(&tamanho, sizeof(int),1,ficheiro_portateis);
        lido = fread(arrayPc,sizeof(tipoPc),30,ficheiro_portateis);
        if(lido!=1)
        {
            printf("ERRO NA LEITURA DA QUANTIDADE DE ESTUDANTES");
        }
        else
        {
            lido = fread(arrayPc, sizeof(tipoPc), tamanho, ficheiro_portateis);
            if(lido!=tamanho)
            {
                printf("ERRO NA LEITURA DE DADOS DO VETOR");
            }
        }
        fclose(ficheiro_portateis);
    }
    else
    {
        printf("ERRO A ABRIR FICHEIRO");
    }
    return tamanho;
}
