#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
struct Moeda {
    int posicao_x;
    int posicao_y;
    int valor;
};
int main() {
  setlocale(LC_ALL,"Portuguese");
    int quantidade;
    int total_pontos = 0;
    int i;
    printf("Quantas moedas existem no nivel? ");
    scanf("%d", &quantidade);
    struct Moeda *vetor_moedas;
    vetor_moedas = (struct Moeda *) malloc(quantidade * sizeof(struct Moeda));
    for(i = 0; i < quantidade; i++) {
        printf("\n--- Cadastrando Moeda %d ---\n", i + 1);
        printf("Posição X: ");
        scanf("%d", &vetor_moedas[i].posicao_x);
        printf("Posição Y: ");
        scanf("%d", &vetor_moedas[i].posicao_y);
        printf("Valor em pontos: ");
        scanf("%d", &vetor_moedas[i].valor);
    }
    for(i = 0; i < quantidade; i++) {
        total_pontos = total_pontos + vetor_moedas[i].valor;
    }
    printf("\nPontuação maxima do nivel: %d\n", total_pontos);
    free(vetor_moedas);
    return 0;
}
