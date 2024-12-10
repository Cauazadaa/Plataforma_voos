#include "assento.h"
#include "voo.h"
#include "passageiro.h"
#include "tripulacao.h"
#include <stdio.h>
#include <stdlib.h>

   

int cadastro_assento(Assento assento[], int *currentCountass, Passageiro passageiro[]) {//função para cadastrar assento, recebe o vetor de assentos, o tamanho do vetor e o vetor de passageiros
    printf("Digite o codigo do voo: ");
    scanf("%d", &assento[*currentCountass].codvoo);
    printf("Digite o numero do assento: ");
    scanf("%d", &assento[*currentCountass].numero);//numero do assento
    assento[*currentCountass].ocupado = 0;//ocupado
    //  lógica de ocupação
    if (assento[*currentCountass].ocupado == 0) {
        assento[*currentCountass].ocupado = 1;
        assento[*currentCountass].passageiro = passageiro[*currentCountass];
        (*currentCountass)++;
        printf("Assento cadastrado com sucesso\n");
    } else {
        printf("Assento ocupado\n");
    }
    return 1;
}
