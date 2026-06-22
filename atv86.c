#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Heroi;


typedef struct No {
    Heroi heroi;
    struct No *prox;
} No;

void adicionarFim(No **inicio) {

    No *novo = (No*) malloc(sizeof(No));

    printf("ID do heroi: ");
    scanf("%d", &novo->heroi.id);

    printf("Nome do heroi: ");
    scanf(" %49[^\n]", novo->heroi.nome);

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

    printf("Heroi adicionado com sucesso!\n");
}

void inserirAntes(No **inicio) {

    int idVIP;

    No *novo = (No*) malloc(sizeof(No));

    printf("ID do guarda-costas: ");
    scanf("%d", &novo->heroi.id);

    printf("Nome do guarda-costas: ");
    scanf(" %49[^\n]", novo->heroi.nome);

    printf("ID do VIP: ");
    scanf("%d", &idVIP);
    if (*inicio == NULL) {
        printf("Formacao vazia!\n");
        free(novo);
        return;
    }
    if ((*inicio)->heroi.id == idVIP) {
        novo->prox = *inicio;
        *inicio = novo;
        printf("Guarda-costas inserido com sucesso!\n");
        return;
    }
    No *anterior = *inicio;
    No *atual = (*inicio)->prox;
    while (atual != NULL && atual->heroi.id != idVIP) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("VIP nao encontrado!\n");
        free(novo);
        return;
    }
    novo->prox = atual;
    anterior->prox = novo;
    printf("Guarda-costas inserido com sucesso!\n");
}
void mostrarFormacao(No *inicio) {
    if (inicio == NULL) {
        printf("\nFormacao vazia!\n");
        return;
    }
    printf("\n=== FORMACAO ===\n");
    while (inicio != NULL) {
        printf("ID: %d\n", inicio->heroi.id);
        printf("Nome: %s\n\n", inicio->heroi.nome);
        inicio = inicio->prox;
    }
}
int main() {
    No *inicio = NULL;
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar Heroi no Fim\n");
        printf("2 - Adicionar Guarda-Costas\n");
        printf("3 - Mostrar Formacao\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                adicionarFim(&inicio);
                break;
            case 2:
                inserirAntes(&inicio);
                break;
            case 3:
                mostrarFormacao(inicio);
                break;
            case 4:
                printf("Encerrando programa...\n");
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
