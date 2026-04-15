#include <stdio.h>
#include <locale.h>
struct Heroi {
    int saude;
    int pontuacao;
    int posX;
    int posY;
};
int main() {
  setlocale(LC_ALL,"Portuguese");
    struct Heroi meuHeroi;
    meuHeroi.saude = 100;
    meuHeroi.pontuacao = 0;
    meuHeroi.posX = 0;
    meuHeroi.posY = 0;
    printf("--- ESTADO INICIAL ---\n");
    printf("Saude: %d, Pontos: %d, Posição: (%d,%d)\n\n", 
            meuHeroi.saude, meuHeroi.pontuacao, meuHeroi.posX, meuHeroi.posY);
    
  struct Heroi *ptrHeroi = &meuHeroi;
    ptrHeroi->saude = ptrHeroi->saude - 25;
    printf("O heroi sofreu dano! Nova saúde: %d\n", ptrHeroi->saude);
    ptrHeroi->pontuacao = ptrHeroi->pontuacao + 50;
    printf("Moedas coletadas! Nova pontuação: %d\n", ptrHeroi->pontuacao);
    ptrHeroi->posX = ptrHeroi->posX + 10;
    ptrHeroi->posY = ptrHeroi->posY - 5;
    printf("O heroi se moveu para: (%d, %d)\n\n", ptrHeroi->posX, ptrHeroi->posY);
    printf("--- ESTADO FINAL---\n");
    printf("Saúde: %d\n", ptrHeroi->saude);
    printf("Pontuação: %d\n", ptrHeroi->pontuacao);
    printf("Posição X: %d\n", ptrHeroi->posX);
    printf("Posição Y: %d\n", ptrHeroi->posY);
    return 0;
}
