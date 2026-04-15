#include <stdio.h>
#include <locale.h>
struct Posicao {
    int x;
    int y;
};
void mover_personagem(struct Posicao *p, int movimento_x, int movimento_y) {
    p->x = p->x + movimento_x;
    p->y = p->y + movimento_y;
}
int main() {
  setlocale(LC_ALL,"Portuguese");
    struct Posicao posicao_jogador;
    posicao_jogador.x = 0;
    posicao_jogador.y = 0;
    struct Posicao *ponteiro_posicao = &posicao_jogador;
    printf("Posição inicial do jogador: X=%d, Y=%d\n", posicao_jogador.x, posicao_jogador.y);
    mover_personagem(ponteiro_posicao, 10, 5);
    printf("Posição final do jogador: X=%d, Y=%d\n", posicao_jogador.x, posicao_jogador.y);
    return 0;
}
