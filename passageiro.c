#include "passageiro.h"



int cadastro_pass(Passageiro passageiro[], int *currentCountpass){ //funcao para cadastro de passageiro, recebe o vetor de passageiros e o tamanho do vetor
    printf("Digite o codigo do passageiro: ");
    scanf("%d", &passageiro[*currentCountpass].codigo);
    printf("Digite o nome do passageiro: ");
    scanf("%s", passageiro[*currentCountpass].nome);//nome do passageiro
    (*currentCountpass)++;
    printf("Passageiro cadastrado com sucesso\n");
    return 1;
}
