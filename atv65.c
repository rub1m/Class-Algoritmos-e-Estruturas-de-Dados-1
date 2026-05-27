#include <stdio.h>
#include <stdlib.h> 
typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;
int main() {
    int N;
    scanf("%d", &N);
    Jogador *jogadores = (Jogador *)malloc(N * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%s %d", jogadores[i].nome, &jogadores[i].pontuacao);
    }
    for (int i = 1; i < N; i++) {
        Jogador chave = jogadores[i]; 
        int j = i - 1;
        while (j >= 0 && jogadores[j].pontuacao < chave.pontuacao) {
            jogadores[j + 1] = jogadores[j]; 
            j--;
        }
        jogadores[j + 1] = chave;
    }
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", jogadores[i].pontuacao, jogadores[i].nome);
    }
    free(jogadores);
    return 0;
}
