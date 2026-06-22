#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estrutura para armazenar os dados do movimento */
typedef struct {
    int id;
    char nome[50];
} Movimento;

/* Nó da lista encadeada */
typedef struct No {
    Movimento mov;
    struct No *prox;
} No;

/* Estrutura da lista */
typedef struct {
    No *inicio;
} Lista;

int main() {

    Lista combo;
    combo.inicio = NULL;

    int opcao;

    do {

        printf("\n=== LOG DE COMBO ===\n");
        printf("1 - Inserir movimento\n");
        printf("2 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            No *novo = (No *) malloc(sizeof(No));

            if (novo == NULL) {
                printf("Erro ao alocar memoria!\n");
                return 1;
            }

            printf("Digite o ID do movimento: ");
            scanf("%d", &novo->mov.id);

            printf("Digite o nome do movimento: ");
            scanf(" %49[^\n]", novo->mov.nome);

            /* Inserção no início da lista */
            novo->prox = combo.inicio;
            combo.inicio = novo;

            printf("Movimento inserido com sucesso!\n");
        }

    } while (opcao != 2);

    /* Liberação da memória */
    No *atual = combo.inicio;

    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    printf("Programa encerrado.\n");

    return 0;
}
