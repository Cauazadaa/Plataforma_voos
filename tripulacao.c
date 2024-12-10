

#include "tripulacao.h"
#include <stdio.h>




int cadastro_trip(Tripulacao tripulacao[], int *currentCounttrip){ //funcao para cadastro de tripulacao, recebe o vetor de tripulação e o tamanho do vetor
     int codigo;
    char cargo[50];
    int i;

printf("digite o codigo da tripulacao: ");
scanf("%d", &codigo);
//verifica se o codigo ja existe
for(i = 0;i < *currentCounttrip;i++){
    if(tripulacao[i].codigot == codigo){
        printf(" Erro,codigo ja existe");
        return 0;
    }
}
//cadastro do codigo,nome e cargo
tripulacao[*currentCounttrip].codigot = codigo;
printf("digite o nome da tripulacao: ");
scanf("%s", tripulacao[*currentCounttrip].nome);//nome da tripulação
printf("digite o cargo da tripulacao: ");
scanf("%s", tripulacao[*currentCounttrip].cargo);//cargo da tripulação
(*currentCounttrip)++;
printf("Tripulação cadastrada com sucesso\n");
return 1;

}