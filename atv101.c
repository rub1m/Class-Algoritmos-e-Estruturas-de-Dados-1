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
void mostrar_pilha(No *topo) {
    if (topo == NULL) {
        printf("\n--- A pilha de comandos esta vazia. ---\n");
        return;
    }
    printf("\n--- Ordem de Execucao (Topo para Base) ---\n");
    No *atual = topo;
    while (atual != NULL) {
        printf("Feitico: %s | Custo: %d\n", atual->dados.nome, atual->dados.custo_mana);
        atual = atual->prox;
    }
}
void empilhar(No **topo, char nome[], int mana) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->dados.nome, nome);
    novo->dados.custo_mana = mana;
    novo->prox = *topo;
    *topo = novo;
    printf("Feitico '%s' adicionado.\n", nome);
}

int main() {
    No *topo = NULL;
    int opcao, mana;
    char nome[50];
    do {
        printf("\n1: Adicionar | 2: Mostrar | 3: Sair: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Nome: "); scanf("%s", nome);
            printf("Mana: "); scanf("%d", &mana);
            empilhar(&topo, nome, mana);
        } else if (opcao == 2) {
            mostrar_pilha(topo);
        }
    } while (opcao != 3);
    return 0;
}
