#include <stdio.h>
#include <stdlib.h>

int main()
{
    int comp1,comp2,comp3;
    printf("Introduz um comprimento: \n");
    scanf("%d", &comp1);
    printf("Introduz um comprimento: \n");
    scanf("%d", &comp2);
    printf("Introduz um comprimento: \n");
    scanf("%d", &comp3);

    if(abs(comp1-comp2)< comp3 && comp3 < comp1 + comp2){
        if(comp1 == comp2 && comp2 == comp3)
        {
            printf("Triangulo equilatero.\n");
        }
        else
        {
            if(comp1 == comp2 || comp1 == comp3 || comp2 == comp3)
            {
                printf("Triangulo iscosceles.\n");
            }
            else
            {
                printf("Triangulo escaleno");
            }
        }
    }
    else{
        printf("Nao e possivel formar um triangulo.");
    }
    return 0;
}
