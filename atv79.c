/* =========================
   ARQUIVO: heroi/heroi.h
   ========================= */

#ifndef HEROI_H
#define HEROI_H

typedef struct Heroi Heroi;

Heroi* criar_herois(int quantidade);
void ler_herois(Heroi* herois, int quantidade);
void imprimir_herois(Heroi* herois, int quantidade);

#endif


/* =========================
   ARQUIVO: heroi/heroi.c
   ========================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heroi.h"

struct Heroi
{
    char nome[50];
    int hp;
    int ataque;
};

Heroi* criar_herois(int quantidade)
{
    return (Heroi*) malloc(quantidade * sizeof(Heroi));
}

void ler_herois(Heroi* herois, int quantidade)
{
    int i;

    for(i = 0; i < quantidade; i++)
    {
        printf("\nHeroi %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", herois[i].nome);

        printf("HP: ");
        scanf("%d", &herois[i].hp);

        printf("Ataque: ");
        scanf("%d", &herois[i].ataque);
    }
}

void imprimir_herois(Heroi* herois, int quantidade)
{
    int i;

    printf("\n=== ROSTER DE HEROIS ===\n");

    for(i = 0; i < quantidade; i++)
    {
        printf("\nHeroi %d\n", i + 1);
        printf("Nome: %s\n", herois[i].nome);
        printf("HP: %d\n", herois[i].hp);
        printf("Ataque: %d\n", herois[i].ataque);
    }
}


/* =========================
   ARQUIVO: main.c
   ========================= */

#include <stdio.h>
#include <stdlib.h>
#include "heroi.h"

int main()
{
    int quantidade;

    printf("Quantos herois farao parte da equipe? ");
    scanf("%d", &quantidade);

    Heroi* equipe = criar_herois(quantidade);

    ler_herois(equipe, quantidade);

    imprimir_herois(equipe, quantidade);

    free(equipe);

    return 0;
}
