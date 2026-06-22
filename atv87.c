#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Jogador;
typedef struct No {
    Jogador jogador;
    struct No* proximo;
} No;
typedef struct {
    No* inicio;
} Lista;
void inicializarLista(Lista* l) {
    l->inicio = NULL;
}
void adicionarJogador(Lista* l) {
    No* novoNo = (No*)malloc(sizeof(No));
    printf("\nDigite o ID do jogador: ");
    scanf("%d", &novoNo->jogador.id);
    printf("Digite o nome do jogador: ");
    scanf(" %49[^\n]", novoNo->jogador.nome); 
    novoNo->proximo = NULL; 
    if (l->inicio == NULL) {
        l->inicio = novoNo;
    } else {
        No* atual = l->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
    printf(">> Jogador %s adicionado a fila com sucesso!\n", novoNo->jogador.nome);
}
void iniciarPartida(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n>> Nao ha jogadores na fila.\n");
    } else {
        No* noRemover = l->inicio;
        printf("\n>> Iniciando partida para o jogador: %s (ID: %d)\n", noRemover->jogador.nome, noRemover->jogador.id);
        l->inicio = l->inicio->proximo;
        free(noRemover);
    }
}
void mostrarFila(Lista* l) {
    if (l->inicio == NULL) {
        printf("\n>> A fila esta vazia no momento.\n");
        return;
    }
    printf("\n--- Fila de Matchmaking ---\n");
    No* atual = l->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("%dº da fila - ID: %d | Nome: %s\n", posicao, atual->jogador.id, atual->jogador.nome);
        atual = atual->proximo;
        posicao++;
    }
    printf("---------------------------\n");
}
int main() {
    Lista filaMatchmaking;
    inicializarLista(&filaMatchmaking);
    int opcao;
    do {
        printf("\n=== MENU DO SISTEMA ===\n");
        printf("1: Adicionar jogador ao fim da fila\n");
        printf("2: Iniciar partida\n");
        printf("3: Mostrar fila de espera\n");
        printf("4: Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                adicionarJogador(&filaMatchmaking);
                break;
            case 2:
                iniciarPartida(&filaMatchmaking);
                break;
            case 3:
                mostrarFila(&filaMatchmaking);
                break;
            case 4:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\n>> Opcao invalida! Tenta de novo.\n");
        }
    } while(opcao != 4);
    return 0;
}
