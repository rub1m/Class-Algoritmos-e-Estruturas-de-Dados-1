#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int idJogador;
    struct Node *proximo;
} Node;
typedef struct Fila {
    Node *inicio;
    Node *fim;
} Fila;
int estaVazia(Fila *f) {
    if (f->inicio == NULL) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    Fila minhaFila;
    minhaFila.inicio = NULL;
    minhaFila.fim = NULL;
    int opcao;
    do {
        printf("\n--- MENU MATCHMAKING ---\n");
        printf("1. Adicionar Jogador\n");
        printf("2. Remover Jogador\n");
        printf("3. Verificar se a Fila esta Vazia\n"); 
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Opcao de adicionar ainda nao integrada no teste.\n");
                break;
            case 2:
                printf("Opcao de remover ainda nao integrada no teste.\n");
                break;
            case 3:
                if (estaVazia(&minhaFila) == 1) {
                    printf("SIM, a fila esta vazia.\n");
                } else {
                    printf("NAO, a fila contem jogadores.\n");
                }
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
    return 0;
}
