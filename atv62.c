#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
typedef struct {
    char nome[50];
    int eliminacoes;
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
        scanf("%s %d", jogadores[i].nome, &jogadores[i].eliminacoes);
    }
    for (int i = 0; i < N - 1; i++) {
        int indice_maior = i; 
        for (int j = i + 1; j < N; j++) {
            if (jogadores[j].eliminacoes > jogadores[indice_maior].eliminacoes) {
                indice_maior = j;
            }
        }
        if (indice_maior != i) {
            Jogador temp = jogadores[i];
            jogadores[i] = jogadores[indice_maior];
            jogadores[indice_maior] = temp;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%s %d\n", jogadores[i].nome, jogadores[i].eliminacoes);
    }
    free(jogadores);
    return 0;
}
