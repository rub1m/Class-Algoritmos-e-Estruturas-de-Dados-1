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
void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }
    No *atual = p->topo;
    printf("\n--- Grimorio Atual ---\n");
    while (atual != NULL) {
        printf("- %s (Mana: %d)\n", atual->feitico.nome, atual->feitico.custo_mana);
        atual = atual->proximo;
    }
    printf("----------------------\n");
}
void inverter_pilha(Pilha *p) {
    Pilha auxiliar;
    auxiliar.topo = NULL; 
    while (!vazia(p)) {
        No *temp = p->topo;
        Feitico f = temp->feitico;
        p->topo = p->topo->proximo;
        free(temp); 
        No *novo = (No*) malloc(sizeof(No));
        novo->feitico = f;
        novo->proximo = auxiliar.topo;
        auxiliar.topo = novo;
    }
    p->topo = auxiliar.topo;
}

int main() {
    Pilha p;
    p.topo = NULL;
    int opcao;
    No *f1 = (No*) malloc(sizeof(No));
    strcpy(f1->feitico.nome, "Misseis Magicos");
    f1->feitico.custo_mana = 10;    
    No *f2 = (No*) malloc(sizeof(No));
    strcpy(f2->feitico.nome, "Escudo Arcano");
    f2->feitico.custo_mana = 20;
    No *f3 = (No*) malloc(sizeof(No));
    strcpy(f3->feitico.nome, "Bola de Fogo");
    f3->feitico.custo_mana = 30;
    f1->proximo = NULL;
    f2->proximo = f1;
    f3->proximo = f2;
    p.topo = f3;
    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar feitico\n");
        printf("2. Lancar feitico (pop)\n");
        printf("3. Visualizar pilha\n");
        printf("4. Consultar Proximo Feitico (Top)\n");
        printf("5. Verificar Status da Pilha\n");
        printf("6. Inverter Ordem dos Feiticos\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Opcao de adicionar (push) em construcao...\n");
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                mostrar_pilha(&p);
                break;
            case 4: {
                Feitico proximo = top(&p);
                if (proximo.custo_mana != -1) {
                    printf("\n--- Espiando o Topo ---\n");
                    printf("Proximo feitico: %s (Mana: %d)\n", proximo.nome, proximo.custo_mana);
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
                if (vazia(&p)) {
                    printf("Nao ha nada para inverter. A pilha esta vazia!\n");
                } else {
                    inverter_pilha(&p);
                    printf("Sucesso! Ordem dos feiticos invertida. Use a opcao 3 para conferir.\n");
                }
                break;
            case 7:
                printf("Saindo do grimorio...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 7);
    while(!vazia(&p)) {
        pop(&p);
    }
    return 0;
}
