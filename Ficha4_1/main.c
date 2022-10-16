#include <stdio.h>
#include <stdlib.h>
int lenumeros();
int areaRetangulo();
int leDadosRetangulo();
int main()
{
    int lado1,lado2,lado3,lado4,dado1,dado2,area;
    lado1 = lenumeros();
    lado2 = lenumeros();
    lado3 = lenumeros();
    lado4 = lenumeros();
    dado1 = leDadosRetangulo(lado1,lado2,lado3,lado4);
    dado2 = leDadosRetangulo(lado1,lado2,lado3,lado4);
    area = areaRetangulo(dado1,dado2);
    printf("A area do retangulo e %d.",area);
    return 0;
}
int lenumeros(){
    int num1;
    printf("Introduza um numero inteiro.\n");
    scanf("%d", &num1);
    return num1;
}
int leDadosRetangulo(int aresta1, int aresta2, int aresta3, int aresta4){
        int larg, compri;
        if (aresta1 == aresta2 && aresta1>aresta3){
            compri = aresta1;
        }
        else{
            if(aresta1>aresta3 && aresta1>aresta4){
                compri = aresta1;
            }
            else{
                compri = aresta2;
                larg = aresta3;
            }
        }
        return larg,compri;
}
int areaRetangulo(int comprimen, int largu){
    int area=0;
    area = comprimen*largu;
    return area;
}
//
