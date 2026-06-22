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
Feitico pop(No **topo) {
    Feitico falha = {"", -1}; 
    if (*topo == NULL) {
        printf("A pilha de comandos esta vazia!\n");
        return falha;
    }
    No *temp = *topo;
    Feitico removido = temp->dados;
    *topo = (*topo)->prox;
    free(temp);
    return removido;
}
void liberar_pilha(No **topo) {
    while (*topo != NULL) {
        pop(topo);
    }
}

int main() {
    No *topo = NULL;
    int opcao;    
    do {
        printf("\n1: Adicionar | 2: Lançar | 3: Mostrar | 4: Sair: ");
        scanf("%d", &opcao);
        if (opcao == 2) {
            Feitico f = pop(&topo);
            if (f.custo_mana != -1) {
                printf("Feitico '%s' lancado com sucesso!\n", f.nome);
            }
        }
    } while (opcao != 4);
    liberar_pilha(&topo);
    return 0;
}
