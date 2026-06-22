#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char titulo[50];
    char status[30];
} Missao;

typedef struct No {
    Missao missao;
    struct No *prox;
} No;

void adicionarMissao(No **inicio) {

    No *novo = (No*) malloc(sizeof(No));

    printf("ID da missao: ");
    scanf("%d", &novo->missao.id);

    printf("Titulo: ");
    scanf(" %49[^\n]", novo->missao.titulo);

    printf("Status: ");
    scanf(" %29[^\n]", novo->missao.status);

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

    printf("Missao adicionada com sucesso!\n");
}

void mostrarMissoes(No *inicio) {

    if (inicio == NULL) {
        printf("\nNenhuma missao cadastrada!\n");
        return;
    }

    printf("\n=== MISSOES ===\n");

    while (inicio != NULL) {
        printf("ID: %d\n", inicio->missao.id);
        printf("Titulo: %s\n", inicio->missao.titulo);
        printf("Status: %s\n\n", inicio->missao.status);

        inicio = inicio->prox;
    }
}

No* pesquisar_missao(No *inicio, int id) {

    while (inicio != NULL) {

        if (inicio->missao.id == id) {
            return inicio;
        }

        inicio = inicio->prox;
    }

    return NULL;
}

int main() {

    No *inicio = NULL;
    No *resultado;
    int opcao;
    int idBusca;

    do {

        printf("\n=== MENU ===\n");
        printf("1 - Adicionar Missao\n");
        printf("2 - Mostrar Missoes\n");
        printf("3 - Buscar Missao por ID\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                adicionarMissao(&inicio);
                break;

            case 2:
                mostrarMissoes(inicio);
                break;

            case 3:
                printf("Digite o ID da missao: ");
                scanf("%d", &idBusca);

                resultado = pesquisar_missao(inicio, idBusca);

                if (resultado != NULL) {
                    printf("\nMissao encontrada!\n");
                    printf("ID: %d\n", resultado->missao.id);
                    printf("Titulo: %s\n", resultado->missao.titulo);
                    printf("Status: %s\n", resultado->missao.status);
                } else {
                    printf("\nMissao nao encontrada!\n");
                }

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
