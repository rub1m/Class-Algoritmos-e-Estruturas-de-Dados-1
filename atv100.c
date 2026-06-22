#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;
typedef struct No {
    Feitico dados;
    struct No *prox;
} No;
void empilhar(No **topo, char nome[], int mana) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->dados.nome, nome);
    novo->dados.custo_mana = mana;
    novo->prox = *topo;
    *topo = novo;
    printf("Feitico '%s' adicionado ao topo da pilha.\n", nome);
}

int main() {
    No *topo = NULL;
    int opcao, mana;
    char nome[50];
    do {
        printf("\n--- Sistema de Comandos do Arcanista ---\n");
        printf("1: Adicionar feitiço à pilha\n");
        printf("2: Finalizar e sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nome do feitiço: ");
            scanf("%s", nome);
            printf("Custo de mana: ");
            scanf("%d", &mana);
            empilhar(&topo, nome, mana);
        }
    } while (opcao != 2);
    printf("Sequência finalizada. Preparando para execução futura...\n");
    return 0;
}
