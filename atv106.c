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
void pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: A pilha ja esta vazia!\n");
        return;
    }
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    printf("Feitico '%s' removido.\n", temp->feitico.nome);
    free(temp);
}
void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("A pilha de comandos esta vazia.\n");
        return;
    }
    No *atual = p->topo;
    printf("\n--- Grimorio Atual (Do Topo para a Base) ---\n");
    while (atual != NULL) {
        printf("- %s (Mana: %d)\n", atual->feitico.nome, atual->feitico.custo_mana);
        atual = atual->proximo;
    }
    printf("--------------------------------------------\n");
}
void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
    // Abre o arquivo no modo de escrita binária ("wb")
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel criar ou abrir o arquivo '%s'!\n", nome_arquivo);
        return;
    }
    No *aux = p->topo;
    while (aux != NULL) {
        fwrite(&(aux->feitico), sizeof(Feitico), 1, arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    printf("Sucesso: Sequencia de feiticos salva permanentemente em '%s'!\n", nome_arquivo);
}

int main() {
    Pilha p;
    p.topo = NULL;
    int opcao;
    No *f1 = (No*) malloc(sizeof(No));
    strcpy(f1->feitico.nome, "Misseis Magicos"); f1->feitico.custo_mana = 10; f1->proximo = NULL; p.topo = f1;
    No *f2 = (No*) malloc(sizeof(No));
    strcpy(f2->feitico.nome, "Escudo Arcano"); f2->feitico.custo_mana = 20; f2->proximo = p.topo; p.topo = f2;
    No *f3 = (No*) malloc(sizeof(No));
    strcpy(f3->feitico.nome, "Bola de Fogo"); f3->feitico.custo_mana = 30; f3->proximo = p.topo; p.topo = f3;
    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar feitico (Push)\n");
        printf("2. Lancar feitico (Pop)\n");
        printf("3. Visualizar pilha\n");
        printf("4. Consultar Proximo Feitico (Top)\n");
        printf("5. Salvar Sequencia no Grimorio\n"); 
        printf("6. Verificar Status da Pilha\n");
        printf("7. Sair\n");                    
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Opcao push em desenvolvimento...\n");
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                mostrar_pilha(&p);
                break;
            case 4:
                if (!vazia(&p)) {
                    printf("Proximo feitico: %s\n", p.topo->feitico.nome);
                } else {
                    printf("Pilha vazia.\n");
                }
                break;
            case 5:
                salvar_pilha_em_arquivo(&p, "grimorio.bin");
                break;
            case 6:
                if (vazia(&p)) {
                    printf("A pilha de comandos esta vazia.\n");
                } else {
                    printf("A pilha de comandos possui feiticos pendentes.\n");
                }
                break;
            case 7:
                printf("Encerrando o grimorio e guardando os pergaminhos...\n");
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
