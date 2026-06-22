#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
} Jogador;

typedef struct No {
    Jogador jogador;
    struct No *prox;
} No;

void inserirInicio(No **inicio) {
    No *novo = (No *) malloc(sizeof(No));

    printf("Matricula: ");
    scanf("%d", &novo->jogador.matricula);

    printf("Nome: ");
    scanf(" %49[^\n]", novo->jogador.nome);

    novo->prox = *inicio;
    *inicio = novo;

    printf("Jogador adicionado no inicio!\n");
}

void inserirFim(No **inicio) {
    No *novo = (No *) malloc(sizeof(No));

    printf("Matricula: ");
    scanf("%d", &novo->jogador.matricula);

    printf("Nome: ");
    scanf(" %49[^\n]", novo->jogador.nome);

    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No *atual = *inicio;

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    printf("Jogador adicionado no final!\n");
}


void mostrarFila(No *inicio) {

    if (inicio == NULL) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\n=== FILA DE JOGADORES ===\n");

    while (inicio != NULL) {
        printf("Matricula: %d\n", inicio->jogador.matricula);
        printf("Nome: %s\n\n", inicio->jogador.nome);

        inicio = inicio->prox;
    }
}

int main() {

    No *inicio = NULL;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar jogador no inicio\n");
        printf("2 - Adicionar jogador no final\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                inserirInicio(&inicio);
                break;

            case 2:
                inserirFim(&inicio);
                break;

            case 3:
                mostrarFila(inicio);
                break;

            case 4:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 4);

   
    No *atual = inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
