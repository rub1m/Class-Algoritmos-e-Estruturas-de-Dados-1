/**************************************
 * ARQUIVO: personagem.h
 **************************************/

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

typedef struct personagem Personagem;

Personagem* cria_party(int num_membros);
void registrar_membros(Personagem* party, int num_membros);
void exibe_relatorio(const Personagem* party, int num_membros);
void libera_party(Personagem** party);

#endif


/**************************************
 * ARQUIVO: personagem.c
 **************************************/

/*

#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

struct personagem {
    char nome[50];
    char classe[50];
    int nivel;
    int hp;
};

Personagem* cria_party(int num_membros) {
    Personagem* party;

    party = (Personagem*) malloc(num_membros * sizeof(Personagem));

    if (party == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    return party;
}

void registrar_membros(Personagem* party, int num_membros) {
    int i;

    for (i = 0; i < num_membros; i++) {
        printf("\n--- Personagem %d ---\n", i + 1);

        printf("Nome: ");
        scanf("%s", party[i].nome);

        printf("Classe: ");
        scanf("%s", party[i].classe);

        printf("Nivel: ");
        scanf("%d", &party[i].nivel);

        printf("HP: ");
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    int i;

    printf("\n===== EQUIPE =====\n");

    for (i = 0; i < num_membros; i++) {
        printf("\nPersonagem %d\n", i + 1);
        printf("Nome: %s\n", party[i].nome);
        printf("Classe: %s\n", party[i].classe);
        printf("Nivel: %d\n", party[i].nivel);
        printf("HP: %d\n", party[i].hp);
    }
}

void libera_party(Personagem** party) {
    free(*party);
    *party = NULL;
}

*/


/**************************************
 * ARQUIVO: main.c
 **************************************/

#include <stdio.h>
#include "personagem.h"

int main() {
    int num_membros;
    Personagem* party;

    printf("Quantos membros tera a equipe? ");
    scanf("%d", &num_membros);

    party = cria_party(num_membros);

    registrar_membros(party, num_membros);

    exibe_relatorio(party, num_membros);

    libera_party(&party);

    return 0;
}
