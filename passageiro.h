#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H



typedef struct {
    int codigo;
    char nome[100];
    int pontosFidelidade;
} Passageiro;


#endif