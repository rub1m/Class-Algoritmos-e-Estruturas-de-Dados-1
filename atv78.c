/* =========================
   ARQUIVO: combate.h
   ========================= */

#ifndef COMBATE_H
#define COMBATE_H

int calcular_ataque_total(int ataque_base, int bonus_arma);
int aplicar_dano(int vida_atual, int dano);

#endif
/* =========================
   ARQUIVO: combate.c
   ========================= */

#include "combate.h"
int calcular_ataque_total(int ataque_base, int bonus_arma)
{
    return ataque_base + bonus_arma;
}

int aplicar_dano(int vida_atual, int dano)
{
    int vida_restante = vida_atual - dano;

    if (vida_restante < 0)
    {
        return 0;
    }

    return vida_restante;
}

/* =========================
   ARQUIVO: main.c
   ========================= */

#include <stdio.h>
#include "combate.h"

int main()
{
    int ataque_base;
    int bonus_arma;
    int vida_inimigo;
    int ataque_total;
    int vida_restante;

    printf("Digite o ataque base do heroi: ");
    scanf("%d", &ataque_base);

    printf("Digite o bonus da arma: ");
    scanf("%d", &bonus_arma);

    printf("Digite a vida inicial do inimigo: ");
    scanf("%d", &vida_inimigo);

    ataque_total = calcular_ataque_total(ataque_base, bonus_arma);

    vida_restante = aplicar_dano(vida_inimigo, ataque_total);

    printf("\nAtaque total do heroi: %d\n", ataque_total);
    printf("Vida restante do inimigo: %d\n", vida_restante);

    return 0;
}
