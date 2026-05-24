#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int pontuacao; 
} Jogador;
int main() {
    int n;
    printf("Quantos jogadores participaram da corrida? ");
    scanf("%d", &n);
    Jogador *lista_jogadores = (Jogador *) malloc(n * sizeof(Jogador));
    if (lista_jogadores == NULL) {
        printf("Ops! Erro ao alocar memoria.\n");
        return 1;
    }
    printf("\n--- Digite os dados dos jogadores ---\n");
    for(int i = 0; i < n; i++) {
        printf("Nome do jogador %d: ", i + 1);
        scanf("%s", lista_jogadores[i].nome);
        printf("Pontuacao de %s: ", lista_jogadores[i].nome);
        scanf("%d", &lista_jogadores[i].pontuacao);
    }
    int indice_melhor = 0; 
    for(int i = 1; i < n; i++) {
        if (lista_jogadores[i].pontuacao > lista_jogadores[indice_melhor].pontuacao) {
            indice_melhor = i; 
        }
    }
    FILE *arquivo = fopen("highscore.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo 'highscore.txt'.\n");
        free(lista_jogadores); 
        return 1;
    }
    fprintf(arquivo, "Nome: %s, Pontuacao: %d\n", lista_jogadores[indice_melhor].nome, lista_jogadores[indice_melhor].pontuacao);
    fclose(arquivo);
    free(lista_jogadores);
    printf("\nShow! O recorde de %s foi salvo no arquivo 'highscore.txt' com sucesso.\n", lista_jogadores[indice_melhor].nome);
    return 0;
}
