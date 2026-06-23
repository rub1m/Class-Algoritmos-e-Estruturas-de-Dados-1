#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    char nickname[50];
} Jogador;
typedef struct Node {
    Jogador dados;
    struct Node *proximo;
} Node;
typedef struct Fila {
    Node *inicio;
    Node *fim;
} Fila;
Jogador verInicio(Fila *f) {
    Jogador jogadorVazio;
    jogadorVazio.id = -1;
    strcpy(jogadorVazio.nickname, "");
    if (f->inicio == NULL) {
        return jogadorVazio;
    } else {
        return f->inicio->dados; 
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
        printf("4. Ver quem e o proximo da Fila\n"); // Nova opção integrada!
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Opcao de adicionar ainda nao testada aqui.\n");
                break;
            case 2:
                printf("Opcao de remover ainda nao testada aqui.\n");
                break;
            case 3:
                printf("Opcao de verificar fila vazia (feita no exercicio anterior).\n");
                break;
            case 4: { 
                Jogador proximo = verInicio(&minhaFila);

                if (proximo.id == -1) {
                    printf("Aviso: A fila de matchmaking esta vazia no momento.\n");
                } else {
                    printf("O proximo jogador a entrar na partida e: %s (ID: %d)\n", proximo.nickname, proximo.id);
                }
                break;
            }
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
    return 0;
}
