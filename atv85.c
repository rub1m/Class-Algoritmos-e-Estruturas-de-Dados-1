#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Item;

typedef struct No {
    Item item;
    struct No *prox;
} No;

void inserirInicio(No **inicio) {
    No *novo = (No*) malloc(sizeof(No));

    printf("ID: ");
    scanf("%d", &novo->item.id);

    printf("Nome: ");
    scanf(" %49[^\n]", novo->item.nome);

    novo->prox = *inicio;
    *inicio = novo;

    printf("Item inserido no inicio!\n");
}

void inserirFim(No **inicio) {
    No *novo = (No*) malloc(sizeof(No));

    printf("ID: ");
    scanf("%d", &novo->item.id);

    printf("Nome: ");
    scanf(" %49[^\n]", novo->item.nome);

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

    printf("Item inserido no final!\n");
}

void inserirApos(No **inicio) {

    int idBusca;

    No *novo = (No*) malloc(sizeof(No));

    printf("ID do novo item: ");
    scanf("%d", &novo->item.id);

    printf("Nome do novo item: ");
    scanf(" %49[^\n]", novo->item.nome);

    printf("Inserir apos qual ID? ");
    scanf("%d", &idBusca);

    No *atual = *inicio;

    while (atual != NULL && atual->item.id != idBusca) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Fragmento nao encontrado!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;

    printf("Catalisador inserido com sucesso!\n");
}

void mostrarInventario(No *inicio) {

    if (inicio == NULL) {
        printf("\nInventario vazio!\n");
        return;
    }

    printf("\n=== INVENTARIO ===\n");

    while (inicio != NULL) {
        printf("ID: %d\n", inicio->item.id);
        printf("Nome: %s\n\n", inicio->item.nome);

        inicio = inicio->prox;
    }
}

int main() {

    No *inicio = NULL;
    int opcao;

    do {

        printf("\n=== MENU ===\n");
        printf("1 - Inserir item no inicio\n");
        printf("2 - Inserir item no final\n");
        printf("3 - Inserir catalisador apos fragmento\n");
        printf("4 - Mostrar inventario\n");
        printf("5 - Sair\n");
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
                inserirApos(&inicio);
                break;

            case 4:
                mostrarInventario(inicio);
                break;

            case 5:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    No *atual = inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
