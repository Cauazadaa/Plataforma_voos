#ifndef VOO_H
#define VOO_H
#include "tripulacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    int codcop;
    int codpil;
    char origem[50];
    char destino[50];
    char data[10];
    char hora[5];
    float tarifa;
    int status;
    char aviao[50]; // 1 para ativo, 0 para inativo
    Tripulacao tripulacao[10]; 
} Voo;

   void cadastro_voo(Voo voos[], int *currentCount, Tripulacao tripulacao[], int *currentCounttrip);

#endif