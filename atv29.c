#include <stdio.h>
#include <string.h>
#include <locale.h>
struct ItemColetavel {
    int valor_pontos;
    float peso;
};
int main() {
 setlocale(LC_ALL,"Portuguese");
    struct ItemColetavel moeda_bronze = {10, 0.5};
    struct ItemColetavel moeda_prata = {50, 0.7};
    struct ItemColetavel moeda_ouro = {100, 1.0};
    int pontuacao_jogador = 0;
    pontuacao_jogador = pontuacao_jogador + moeda_ouro.valor_pontos;
    printf("Moeda de ouro coletada! Pontuação atual: %d\n", pontuacao_jogador);
    return 0;
}
