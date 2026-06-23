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
        f->inicio = Profiler_novo; 
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    printf("Jogador '%s' entrou na fila de espera.\n", j.nickname);
}
void mostrar(Fila *f) {
    if (f->inicio == NULL) {
        printf("A fila de matchmaking esta vazia.\n");
        return;
    }
    No *aux = f->inicio;
    int posicao = 1;
    printf("\n--- Fila de Matchmaking Atual ---\n");
    while (aux != NULL) {
        printf("%d. %s (ID: %d)\n", posicao, aux->jogador.nickname, aux->jogador.id);
        aux = aux->proximo;
        posicao++;
    }
    printf("---------------------------------\n");
}
Jogador remover(Fila *f) {
    if (f->inicio == NULL) {
        printf("Aviso: Nao ha ninguem na fila para remover!\n");
        Jogador jogador_invalido;
        jogador_invalido.id = -1; // ID inválido para indicar falha
        strcpy(jogador_invalido.nickname, "");
        return jogador_invalido;
    }
    No *no_removido = f->inicio;
    Jogador jogador_dados = no_removido->jogador;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) {
        f->fim = NULL; 
    }
    free(no_removido);
    return jogador_dados;
}

int main() {
    Fila fila_moba;
    fila_moba.inicio = NULL;
    fila_moba.fim = NULL;
    int opcao;
    Jogador novo_jogador;
    do {
        // Menu com as 4 opções obrigatórias
        printf("\n--- Arena Matchmaking ---\n");
        printf("1. Adicionar Jogador na Fila (Enqueue)\n");
        printf("2. Mostrar Fila\n");
        printf("3. Remover Jogador da Fila / Iniciar Partida (Dequeue)\n");
        printf("4. Sair\n");
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
            case 3: {
                Jogador removido = remover(&fila_moba);
                if (removido.id != -1) {
                    printf("O jogador %s (ID: %d) foi removido da fila e entrou em uma partida.\n", 
                           removido.nickname, removido.id);
                }
                break;
            }
            case 4:
                printf("Saindo do sistema de matchmaking...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    while (fila_moba.inicio != NULL) {
        remover(&fila_moba);
    }

    return 0;
}
