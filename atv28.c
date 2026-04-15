#include <stdio.h>
#include <string.h>
#include <locale.h>
struct Jogador {
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};
int main() {
   setlocale(LC_ALL,"Portuguese");
    struct Jogador heroi;
    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;
    printf("Inicio da fase! ");
    printf("Posição X: %.1f, Pontos: %d, Pulo Duplo: ", heroi.pos_x, heroi.pontuacao);
    if (heroi.tem_pulo_duplo == 1) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
    heroi.pontuacao = heroi.pontuacao + 10;
    heroi.tem_pulo_duplo = 1;
    printf("Itens coletados! ");
    printf("Posição X: %.1f, Pontos: %d, Pulo Duplo: ", heroi.pos_x, heroi.pontuacao);
    if (heroi.tem_pulo_duplo == 1) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }
    return 0;
}
