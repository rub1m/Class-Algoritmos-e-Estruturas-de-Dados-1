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
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    printf("Jogador '%s' adicionado com sucesso!\n", j.nickname);
}
void mostrar(Fila *f) {
    if (f->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No *aux = f->inicio;
    int posicao = 1;
    printf("\n--- Fila de Espera Atual ---\n");
    while (aux != NULL) {
        printf("Posicao %d: ID %d - %s\n", posicao, aux->jogador.id, aux->jogador.nickname);
        aux = aux->proximo;
        posicao++;
    }
    printf("----------------------------\n");
}

int main() {
    Fila fila_moba;
    fila_moba.inicio = NULL;
    fila_moba.fim = NULL;

    int opcao;
    Jogador novo_jogador;
    do {
        printf("\n--- Menu Matchmaking ---\n");
        printf("1. Adicionar Jogador na Fila\n");
        printf("2. Mostrar Fila\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do jogador: ");
                scanf("%d", &novo_jogador.id);
                getchar(); 
                printf("Digite o Nickname: ");
                fgets(novo_jogador.nickname, 50, stdin);
                novo_jogador.nickname[strcspn(novo_jogador.nickname, "\n")] = '\0';
                inserir(&fila_moba, novo_jogador);
                break;
            case 2:
                mostrar(&fila_moba);
                break;
            case 3:
                printf("Desconectando do servidor...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);
    No *atual = fila_moba.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    return 0;
}
