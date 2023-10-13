#include <stdio.h>
#include <stdlib.h>

int main() {
    int contPrego = 0, contCachorro = 0, contBatata = 0, contBolo = 0, contSumo = 0, opc, numDoses = 0;
    float numPrego = 0, numCachorro = 0, numBatata = 0, numBolo = 0, numSumo = 0, total;
    int totalDosesPrego = 0, totalDosesCachorro = 0, totalDosesBatata = 0, totalDosesBolo = 0, totalDosesSumo = 0;

    printf("Restaurante relâmpago\n");
    printf("Descrição | Preço\n");
    printf("Prego | 2,40$\n");
    printf("Cachorro | 1$\n");
    printf("Batata Frita | 1,80$\n");
    printf("Bolo | 0,50$\n");
    printf("Sumo | 0,60$\n");

    do {
        printf("Quantos pregos quer? ");
        scanf("%d", &contPrego);
        numPrego = (float)contPrego * 2.4;
        totalDosesPrego += contPrego;

        printf("Quantos cachorros quer? ");
        scanf("%d", &contCachorro);
        numCachorro = (float)contCachorro * 1;
        totalDosesCachorro += contCachorro;

        printf("Quantas batatas fritas quer? ");
        scanf("%d", &contBatata);
        numBatata = (float)contBatata * 1.8;
        totalDosesBatata += contBatata;

        printf("Quantos bolos quer? ");
        scanf("%d", &contBolo);
        numBolo = (float)contBolo * 0.5;
        totalDosesBolo += contBolo;

        printf("Quantos sumos quer? ");
        scanf("%d", &contSumo);
        numSumo = (float)contSumo * 0.6;
        totalDosesSumo += contSumo;

        total += numPrego + numCachorro + numBatata + numBolo + numSumo;
        numDoses += contPrego + contCachorro + contBatata + contBolo + contSumo;

        printf("Pretende repetir? Se sim pressione 0: ");
        scanf("%d", &opc);
    } while (opc == 0);

    printf("\nReceita Total: %.2f Euros\n", total);
    printf("Número Total de Doses Encomendadas: %d\n", numDoses);

    float percentPrego = (totalDosesPrego / (float)numDoses) * 100;
    float percentCachorro = (totalDosesCachorro / (float)numDoses) * 100;
    float percentBatata = (totalDosesBatata / (float)numDoses) * 100;
    float percentBolo = (totalDosesBolo / (float)numDoses) * 100;
    float percentSumo = (totalDosesSumo / (float)numDoses) * 100;

    printf("Numero de Doses de Prego: %d (%.2f%%)\n", totalDosesPrego, percentPrego);
    printf("Numero de Doses de Cachorro: %d (%.2f%%)\n", totalDosesCachorro, percentCachorro);
    printf("Numero de Doses de Batata Frita: %d (%.2f%%)\n", totalDosesBatata, percentBatata);
    printf("Numero de Doses de Bolo: %d (%.2f%%)\n", totalDosesBolo, percentBolo);
    printf("Numero de Doses de Sumo: %d (%.2f%%)\n", totalDosesSumo, percentSumo);

    return 0;
}
