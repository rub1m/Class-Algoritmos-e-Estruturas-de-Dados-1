#include <stdio.h>
#include <locale.h>
struct Atributos {
    int vida;
    int pontuacao;
};
struct Personagem {
    char nome[50];
    struct Atributos stats; 
};
int main() {
  setlocale(LC_ALL,"Portuguese");
    struct Personagem jogador;
    printf("Digite o nome do personagem: ");
    scanf("%s", jogador.nome);
    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;
    printf("\nStatus Inicial -> Nome: %s | Vida: %d | Pontuação: %d\n", 
            jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    jogador.stats.pontuacao = jogador.stats.pontuacao + 10;
    jogador.stats.vida = jogador.stats.vida - 25;
    printf("Status Final   -> Nome: %s | Vida: %d | Pontuação: %d\n", 
            jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);
    return 0;
}
