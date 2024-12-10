#include "reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include "voo.h"
#include "passageiro.h"
int verifica_reserva(Reserva reserva[], int tamanho, int codvoo, int assento) {//função para verificar se o assento está disponível, recebe o vetor de reservas, o tamanho do vetor, o codigo do voo e o assento
    for (int i = 0; i < tamanho; i++) {//verifica se o assento está disponível
        if (reserva[i].codvoo == codvoo && reserva[i].assento == assento) {
            return reserva[i].reservado == 0; 
        }
    }
    return 1; // Se não encontrado, retorna disponível
}

int reserva_assento(Reserva reservas[], int *tamanho, int codvoo, int assento, Passageiro passageiro[], int numPassageiros) {//função para reservar assento, recebe o vetor de reservas, o tamanho do vetor, o codigo do voo e o assento, e o vetor de passageiros e o numero de passageiros    
    for (int i = 0; i < *tamanho; i++) {//verifica se o assento está disponível
        if (reservas[i].codvoo == codvoo && reservas[i].assento == assento) {
            if (reservas[i].reservado == 0) {
                reservas[i].reservado = 1; // Marca como reservado
                //adicionar pontos de fidelidade
                for(int j = 0; j < numPassageiros; j++){
                    if(passageiro[j].codigo == reservas[i].codpassageiro){
                        passageiro[j].pontosFidelidade += 10;
                        break;
                    }
                }
                return reservas[i].id; // Reserva bem-sucedida
                printf("Reserva realizada com sucesso. ID da reserva: %d\n", reservas[i].id);
            } else {
                return -1; // Assento já reservado
            }
        }
    }
    reservas[*tamanho].id = *tamanho + 1;
    reservas[*tamanho].codvoo = codvoo;
    reservas[*tamanho].assento = assento;
    reservas[*tamanho].reservado = 1;
    reservas[*tamanho].codpassageiro = passageiro[*tamanho].codigo;
    *tamanho += 1;
    return reservas[*tamanho - 1].id;
}

      void baixa_reserva(Reserva reservas[], int *tamanho, int id, Voo voos[], int numVoos, Passageiro passageiro[], int numPassageiros) {
    for (int i = 0; i < *tamanho; i++) {
        if (reservas[i].id == id) {
            reservas[i].reservado = 0;
            
            //remover pontos de fidelidade
            for(int j = 0; j < numPassageiros; j++){
                if(passageiro[j].codigo == reservas[i].codpassageiro){//verifica se o passageiro está no vetor de passageiros
                    passageiro[j].pontosFidelidade -= 10;
                    break;
                }
            }
            
            
            
            
            // Encontre o voo correspondente
            for (int j = 0; j < numVoos; j++) {
                if (voos[j].numero == reservas[i].codvoo) {//verifica se o voo está no vetor de voos   
                    float valorAPagar = voos[j].tarifa; // Valor total a ser pago
                    // Aplicar política de cancelamento
                    printf("Valor a ser pago: %.2f\n", valorAPagar);
                    break;
                }
            }
            printf("reserva baixada com sucesso\n");
            return;
        }
    }
    printf("reserva nao encontrada\n");
}