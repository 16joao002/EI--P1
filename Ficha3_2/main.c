#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numI=0,soma=0,i=0,contP=0,contN=0;
    float media=0,percP=0,percN=0;
    do{
        printf("Introduza um valor inteiro\n");
        scanf("%d", &numI);
        i++;                    //Conta quantos numeros foram introduzidos
        soma += numI;
        /*if (numI>0){
            contP++;            //Conta os numeros positivos introduzidos
        }
        else{
            if (numI<0){
            contN++;            //Conta os numeros negativos introduzidos
            }
        }*/
    }while(numI!=0);
    media = soma/(i-1);         //media de todos os numeros introduzidos
    percP = (contP/contN)*100;
    printf("A soma dos numeros introduzidos e %d\n", soma);
    printf("A media dos numeros introduzidos e %.2f\n", media);
    printf("Foram introduzidos %d numeros positivos.\n", contP);
    printf("Foram introduzidos %d numeros negativos.\n", contN);
    printf("A percentagem de numeros positivos e de %f.\n",percP);
    printf("A percentagem de numeros positivos e de %f.\n",percN);
    return 0;
}
