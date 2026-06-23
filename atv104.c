#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;
typedef struct No {
    Feitico feitico;
    struct No *proximo;
} No;
typedef struct {
    No *topo;
} Pilha;
int vazia(Pilha *p) {
    return (p->topo == NULL);
}
Feitico top(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Nao ha nenhum feitico na pilha para espiar!\n");
        Feitico erro;
        strcpy(erro.nome, "Falha");
        erro.custo_mana = -1; 
        return erro;
    }
    return p->topo->feitico;
}
void pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: A pilha ja esta vazia!\n");
        return;
    }
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    printf("Feitico '%s' executado e removido.\n", temp->feitico.nome);
    free(temp);
}

int main() {
    Pilha p;
    p.topo = NULL;
    int opcao;
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->feitico.nome, "Bola de Fogo");
    novo->feitico.custo_mana = 30;
    novo->proximo = NULL;
    p.topo = novo;
    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar feitico\n");
        printf("2. Lancar feitico (pop)\n");
        printf("3. Visualizar pilha\n");
        printf("4. Consultar Proximo Feitico (Top)\n"); 
        printf("5. Verificar Status da Pilha\n");        
        printf("6. Sair\n");                          
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                break;
            case 4: {
                Feitico proximo = top(&p);
                if (proximo.custo_mana != -1) {
                    printf("\n--- Espiando o Topo ---\n");
                    printf("Proximo feitico: %s\n", proximo.nome);
                    printf("Custo de Mana: %d\n", proximo.custo_mana);
                    printf("------------------------\n");
                }
                break;
            }
            case 5:
                if (vazia(&p)) {
                    printf("A pilha de comandos esta vazia.\n");
                } else {
                    printf("A pilha de comandos possui feiticos pendentes.\n");
                }
                break;
            case 6:
                printf("Saindo do grimorio...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    while(!vazia(&p)) {
        pop(&p);
    }

    return 0;
}
