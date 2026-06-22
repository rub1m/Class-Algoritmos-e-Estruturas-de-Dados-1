#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura do aventureiro */
typedef struct {
    int id;
    char nome[50];
} Aventureiro;

/* Nó da lista encadeada */
typedef struct No {
    Aventureiro aventureiro;
    struct No *prox;
} No;

/* Função para adicionar aventureiro no início */
void adicionar(No **inicio) {
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("Digite o ID do aventureiro: ");
    scanf("%d", &novo->aventureiro.id);

    printf("Digite o nome do aventureiro: ");
    scanf(" %49[^\n]", novo->aventureiro.nome);

    novo->prox = *inicio;
    *inicio = novo;

    printf("Aventureiro adicionado com sucesso!\n");
}

/* Função para mostrar o grupo */
void mostrarGrupo(No *inicio) {

    if (inicio == NULL) {
        printf("\nGrupo vazio!\n");
        return;
    }

    printf("\n=== GRUPO DE AVENTUREIROS ===\n");

    while (inicio != NULL) {
        printf("ID: %d\n", inicio->aventureiro.id);
        printf("Nome: %s\n\n", inicio->aventureiro.nome);

        inicio = inicio->prox;
    }
}

int main() {

    No *inicio = NULL;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Adicionar Aventureiro\n");
        printf("2 - Mostrar Grupo\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                adicionar(&inicio);
                break;

            case 2:
                mostrarGrupo(inicio);
                break;

            case 3:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    /* Liberar memória */
    No *atual = inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
