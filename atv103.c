#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int id_feitico;
    struct No *proximo;
} No;
typedef struct {
    No *topo;
} Pilha;

int vazia(Pilha *p) {
    if (p->topo == NULL) {
        return 1; 
    } else {
        return 0; 
    }
}
void pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: A pilha ja esta vazia!\n");
        return;
    }
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    printf("Feitico removido com sucesso.\n");
}
void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }
    No *atual = p->topo;
    printf("Feiticos na pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->id_feitico);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    Pilha p;
    p.topo = NULL;
    int opcao;
    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar feitico\n");
        printf("2. Lancar feitico (pop)\n");
        printf("3. Visualizar pilha\n");
        printf("4. Verificar Status da Pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                mostrar_pilha(&p);
                break;
            case 4:
                if (vazia(&p)) {
                    printf("A pilha de comandos esta vazia.\n");
                } else {
                    printf("A pilha de comandos possui feiticos pendentes.\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
    return 0;
}
