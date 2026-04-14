#include <stdio.h>
#include <locale.h>
void aplicar_powerup_pontuacao_dupla(int *ponteiro_pontuacao) {
    *ponteiro_pontuacao = (*ponteiro_pontuacao) * 2;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    int pontuacao_jogador = 1500;
    printf("Pontuação antes do power-up: %d\n", pontuacao_jogador);
    aplicar_powerup_pontuacao_dupla(&pontuacao_jogador);
    printf("Pontuação apos o power-up: %d\n", pontuacao_jogador);
    return 0;
}
