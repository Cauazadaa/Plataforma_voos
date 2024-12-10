#ifndef ASSENTO_H
#define ASSENTO_H

#include "passageiro.h"


typedef struct {
    int codvoo;
    int numero;
    int ocupado; // 1 para ocupado, 0 para livre
    Passageiro passageiro;
} Assento;


#endif
