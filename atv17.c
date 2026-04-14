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
    int mapa_fase1[5][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 2, 0, 1, 1},
        {0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 1, 1, 2, 2, 1, 1}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (mapa_fase1[i][j] == 2) {
                printf("Espinho encontrado na linha %d, coluna %d\n", i, j);
            }
        }
    }
    return 0;
}
