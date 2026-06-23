#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;
typedef struct No {
    Jogador jogador;
    struct No *proximo;
} No;
typedef struct {
    No *inicio;
    No *fim;
} Fila;
void inserir(Fila *f, Jogador j) {
    No *novo = (No*) malloc(sizeof(No));
    novo->jogador = j;
    novo->proximo = NULL; 
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo; 
    } 
    else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    printf("Sucesso: Jogador '%s' (ID: %d) entrou na fila de matchmaking!\n", j.nickname, j.id);
}

int main() {
    Fila fila_moba;
    fila_moba.inicio = NULL;
    fila_moba.fim = NULL;
    int opcao;
    Jogador novo_jogador;
    do {
        printf("\n--- Sistema de Matchmaking (Fila) ---\n");
        printf("1. Adicionar jogador a fila (Enqueue)\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID numérico do jogador: ");
                scanf("%d", &novo_jogador.id);
                getchar(); 
                printf("Digite o Nickname do jogador: ");
                fgets(novo_jogador.nickname, 50, stdin);
                novo_jogador.nickname[strcspn(novo_jogador.nickname, "\n")] = '\0'; 
                inserir(&fila_moba, novo_jogador);
                break;
            case 2:
                printf("Encerrando o sistema de matchmaking...\n");
                break;
                
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 2);
    return 0;
}
