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
void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    novo->feitico = f;
    novo->proximo = p->topo;
    p->topo = novo;
}
void pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: A pilha ja esta vazia!\n");
        return;
    }
    No *temp = p->topo;
    p->topo = p->topo->proximo;
    printf("Feitico '%s' executado e removido da pilha.\n", temp->feitico.nome);
    free(temp);
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
void inverter_pilha(Pilha *p) {
    Pilha auxiliar;
    auxiliar.topo = NULL; 

    while (!vazia(p)) {
        No *temp = p->topo;
        Feitico f = temp->feitico;
        p->topo = p->topo->proximo;
        free(temp); 
        push(&auxiliar, f); 
    }
    p->topo = auxiliar.topo;
}
void salvar_pilha_em_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao salvar o grimorio!\n");
        return;
    }
    No *aux = p->topo;
    while (aux != NULL) {
        fwrite(&(aux->feitico), sizeof(Feitico), 1, arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    printf("Sucesso: Sequencia salva no grimorio!\n");
}
void carregar_pilha_de_arquivo(Pilha *p, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Nenhum grimorio encontrado, iniciando com uma pilha vazia.\n");
        return;
    }
    Feitico f_temp;
    while (fread(&f_temp, sizeof(Feitico), 1, arquivo) == 1) {
        push(p, f_temp);
    }
    fclose(arquivo);
    inverter_pilha(p);
    printf("Conhecimento ancestral recuperado! Grimorio carregado.\n");
}
int main() {
    Pilha p;
    p.topo = NULL;
    int opcao;
    carregar_pilha_de_arquivo(&p, "grimorio.bin");
    do {
        printf("\n--- Menu do Arcanista ---\n");
        printf("1. Adicionar feitico (Push)\n");
        printf("2. Lancar feitico (Pop)\n");
        printf("3. Visualizar pilha\n");
        printf("4. Consultar Proximo Feitico (Top)\n");
        printf("5. Salvar Sequencia no Grimorio\n"); 
        printf("6. Inverter Ordem dos Feiticos\n"); 
        printf("7. Verificar Status da Pilha\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch (opcao) {
            case 1: {
                Feitico novo_feitico;
                printf("Digite o nome do feitico: ");
                fgets(novo_feitico.nome, 50, stdin);
                novo_feitico.nome[strcspn(novo_feitico.nome, "\n")] = '\0';    
                printf("Digite o custo de mana: ");
                scanf("%d", &novo_feitico.custo_mana);        
                push(&p, novo_feitico);
                printf("Feitico adicionado a pilha!\n");
                break;
            }
            case 2:
                pop(&p);
                break;
            case 3:
                mostrar_pilha(&p);
                break;
            case 4: {
                Feitico proximo = top(&p);
                if (proximo.custo_mana != -1) {
                    printf("Proximo feitico: %s (Mana: %d)\n", proximo.nome, proximo.custo_mana);
                }
                break;
            }
            case 5:
                salvar_pilha_em_arquivo(&p, "grimorio.bin");
                break;
            case 6:
                if (!vazia(&p)) {
                    inverter_pilha(&p);
                    printf("A ordem da sua pilha de feiticos foi invertida!\n");
                } else {
                    printf("A pilha esta vazia, nada para inverter.\n");
                }
                break;
            case 7:
                if (vazia(&p)) {
                    printf("A pilha de comandos esta vazia.\n");
                } else {
                    printf("A pilha de comandos possui feiticos pendentes.\n");
                }
                break;
            case 8:
                printf("Saindo e guardando os pergaminhos...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 8);
    while(!vazia(&p)) {
        No *temp = p.topo;
        p.topo = p.topo->proximo;
        free(temp);
    }
    return 0;
}
