#include <stdio.h>
typedef struct {
    int id;
    int pontuacao;
} Jogador;
int main() {
    int N;
    scanf("%d", &N);
    Jogador jogadores[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {          
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {           
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }
    return 0;
}
