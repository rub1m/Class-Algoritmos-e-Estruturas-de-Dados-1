#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    int pontos;
} Conquista;
int main() {
    FILE *arquivo = fopen("player_log.txt", "r+");
    if (arquivo == NULL) {
        printf("Ops! Nao consegui abrir o arquivo 'player_log.txt'.\n");
        printf("Lembra de criar ele na pasta antes de rodar!\n");
        return 1;
    }
    int N;
    fscanf(arquivo, "%d", &N);
    int total_xp = 0;
    Conquista atual; 
    for (int i = 0; i < N; i++) {
        fscanf(arquivo, "%d %d", &atual.id, &atual.pontos);
        total_xp += atual.pontos; 
    }
    printf("--- Resumo da Sessao ---\n");
    printf("Total de XP ganho: %d pontos\n", total_xp);
    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "\n--- SESSION CONCLUDED ---");
    fclose(arquivo);
    printf("\nLog atualizado com sucesso no arquivo 'player_log.txt'!\n");
    return 0; 
}
