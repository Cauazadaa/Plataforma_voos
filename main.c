#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "passageiro.h"
#include "voo.h"
#include "tripulacao.h"
#include "assento.h"
#include "reserva.h"
#include "assento.h"


// Protótipos de função
void cadastro_pass(Passageiro passageiro[], int *currentCountpass);
void cadastro_trip(Tripulacao tripulacao[], int *currentCounttrip);
void cadastro_assento(Assento assento[], int *currentCountass, Passageiro passageiro[]);
int reserva_assento(Reserva reservas[], int *currentCountreserva, int codvoo, int numAssento, Passageiro passageiro[], int numPassageiros);
void baixa_reserva(Reserva reservas[], int *currentCountreserva, int id, Voo voos[], int currentCountvoo,Passageiro passageiro[], int numPassageiros);
   void cadastro_voo(Voo voos[], int *currentCount, Tripulacao tripulacao[], int *currentCounttrip);



void listarVoosPorPassageiro(Passageiro passageiro[], int numPassageiros, int codigoPassageiro, Reserva reservas[], int numReservas, Voo voos[], int numVoos) {
    (void)numVoos;//função para listar os voos por passageiro
    for (int i = 0; i < numPassageiros; i++) {
        if (passageiro[i].codigo == codigoPassageiro) {//verifica se o passageiro está no vetor de passageiros
            printf("Passageiro: %s\n", passageiro[i].nome);
            for (int j = 0; j < numReservas; j++) {
                if (reservas[j].reservado && reservas[j].codvoo == voos[j].numero) {//verifica se o voo está reservado através do codigo do voo
                    printf("Voo: %d, Origem: %s, Destino: %s\n", voos[j].numero, voos[j].origem, voos[j].destino);
                }
            }
            return;
        }
    }
    printf("Passageiro não encontrado.\n");
}




void menu() {//função para o menu
    printf("1. Cadastrar Passageiro\n");
    printf("2. Cadastrar Tripulação\n");
    printf("3. Cadastrar Voo\n");
    printf("4. Cadastrar Assento\n");
    printf("5. Fazer Reserva\n");
    printf("6. Baixa em Reserva\n");
    printf("7. Pesquisa\n");
    printf("8. sair\n");
    
}


int main() {
    int opcao;
    int id;
    Reserva reservas[100];
    int currentCountpass = 0;
    int currentCounttrip = 0;
    int currentCountvoo = 0;
    int currentCountass = 0;
    int currentCountreserva = 0;
    Passageiro passageiro[100];
    Tripulacao tripulacao[100];
    Voo voos[100];
    Assento assento[100];

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                cadastro_pass(passageiro, &currentCountpass);//função para cadastrar passageiro
                break;
            case 2:
                cadastro_trip(tripulacao, &currentCounttrip);//função para cadastrar tripulação
                break;
            case 3:
                cadastro_voo(voos, &currentCountvoo,tripulacao ,&currentCounttrip);//função para cadastrar voo
                break;
            case 4:
                cadastro_assento(assento, &currentCountass, passageiro);//função para cadastrar assento
                break;
            case 5:
                printf("Digite o código do voo: ");
                int codvoo;
                scanf("%d", &codvoo);
                printf("Digite o número do assento: ");
                int numAssento;
                scanf("%d", &numAssento);
                int resultado = reserva_assento(reservas, &currentCountreserva, codvoo, numAssento, passageiro, currentCountpass);//função para reservar assento
                if (resultado == -1) {
                    printf("Assento já reservado.\n");
                } else {
                    printf("Reserva realizada com sucesso. ID da reserva: %d\n", resultado);
                }
                break;
            case 6:
                printf("Digite o id da reserva que deseja dar baixa: ");
                scanf("%d", &id);
                baixa_reserva(reservas, &currentCountreserva, id, voos, currentCountvoo, passageiro, currentCountpass);//função para dar baixa em reserva
                break;
            case 7:
                printf("Digite o código do passageiro: ");
                int codigoPassageiro;
                scanf("%d", &codigoPassageiro);
                listarVoosPorPassageiro(passageiro, currentCountpass, codigoPassageiro, reservas, currentCountreserva, voos, currentCountvoo);//função para listar os voos por passageiro
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 8);
    return 0;
}