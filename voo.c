#include "voo.h"
#include "tripulacao.h"

void cadastro_voo(Voo voos[], int *currentCount,Tripulacao tripulacao[],int *currentCounttrip){//função para cadastrar voo, recebe o vetor de voos e o tamanho do vetor
    printf("digite o numero do voo: ");
    scanf("%d", &voos[*currentCount].numero);
    printf("digite o codigo do copiloto: ");
    scanf("%d", &voos[*currentCount].codcop);
    printf("digite o codigo do piloto: ");
    scanf("%d", &voos[*currentCount].codpil);
    printf("digite a origem do voo: ");
    scanf("%s", voos[*currentCount].origem);
    printf("digite o destino do voo: ");
    scanf("%s", voos[*currentCount].destino);
    printf("digite a data do voo: ");
    scanf("%s", voos[*currentCount].data);
    printf("digite a hora do voo: ");
    scanf("%s", voos[*currentCount].hora);
    printf("digite a tarifa do voo: ");
    scanf("%f", &voos[*currentCount].tarifa);
    printf("digite o avião do voo: ");
    scanf("%s", voos[*currentCount].aviao);
    
    int haspilot = 0;//verifica se o voo tem piloto
    int hascopilot = 0;//verifica se o voo tem copiloto
    for(int i = 0; i < *currentCounttrip; i++){
        if(tripulacao[i].codigot == voos[*currentCount].codpil){//se tiver piloto marca como 1
            haspilot = 1;
        }
        if(tripulacao[i].codigot == voos[*currentCount].codcop){//se tiver copiloto marca como 1
            hascopilot = 1;
        }
    }
    if (haspilot && hascopilot){//se tiver piloto e copiloto marca como 1
        voos[*currentCount].status = 1;
        printf("voo cadastrado com sucesso\n");
    }else {
        voos[*currentCount].status = 0;
        printf("Erro , tripulação em falta\n");
    }


    (*currentCount++);
}