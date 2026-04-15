#include <stdio.h>
#include <locale.h>
struct Personagem {
    int posX;
    int posY;
    int moedas;
};
void atualizarPersonagemComPonteiro(struct Personagem *p) {
    p->posX = 10;
    p->posY = 5;
    p->moedas = p->moedas + 1;
}
int main() {
   setlocale(LC_ALL,"Portuguese");
    struct Personagem jogador;
    jogador.posX = 0;
    jogador.posY = 0;
    jogador.moedas = 0;
    printf("Posição inicial: (%d, %d) - Moedas: %d\n", 
            jogador.posX, jogador.posY, jogador.moedas);
    atualizarPersonagemComPonteiro(&jogador);
    printf("Posição atualizada: (%d, %d) - Moedas: %d\n", 
            jogador.posX, jogador.posY, jogador.moedas);
    return 0;
}
