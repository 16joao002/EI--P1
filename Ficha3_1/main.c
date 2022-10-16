#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1=0,soma=0,num2=0,num3=0,cicloE;   /*variaveis*/
    printf("Este programa faz a soma dos numeros inteiros positivos ate ao numero introduzido\n\n");
    printf("Qual o ciclo que pretende utilizar?\n");
    printf("(W)Ciclo While\n");
    printf("(D)Ciclo do While\n");
    printf("(F)Ciclo For\n");
    printf("(S)Sair\n");
    scanf(" %c",&cicloE);
    printf("Introduza um numero inteiro positivo.\n");
    scanf("%d",&num1);
    num2=num1;
    num3=num1;
    if(cicloE=='s' && cicloE=='S'){
        return 0;
    }
    else {
    if(num1<0)
    {
        printf("Este numero nao e positivo");
    }
    else
    {
        do{
        switch(cicloE)
        {
case 'W':
case 'w':
            while(num1>0)   /*ciclo while*/
            {
                soma=soma+num1;
                num1--;
            }
            printf("A soma total e %d.\n", soma);
            soma=0;
            break;
case 'D':
case 'd':
            do             /*Ciclo do while*/
            {
                soma+=num2;
                num2--;
            }
            while(num2>0);
            printf("A soma total e %d.\n", soma);
            soma=0;
            break;
case 'F':
case 'f':
            for (int numero = 0; numero <= num3; numero++)
            {
                soma += numero;
            }
            printf("A soma total e %d.\n", soma);
            break;
        }
        }while(cicloE!='S' && cicloE!='s');
    }
    }
    return 0;
}
