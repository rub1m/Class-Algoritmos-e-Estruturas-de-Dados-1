#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Heroi;
typedef struct No {
    Heroi heroi;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista);
void adicionar_heroi(Lista *lista, Heroi h);
void mostrar_herois(Lista lista);
void dispensar_heroi(Lista *lista, int id);
void liberar_lista(Lista *lista);

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_remover;
    Heroi h;
    do {
        printf("\n=== GERENCIADOR DE HEROIS ===\n");
        printf("1 - Adicionar Heroi\n");
        printf("2 - Mostrar Todos os Herois\n");
        printf("3 - Dispensar Heroi por ID\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do heroi: ");
                scanf("%d", &h.id);
                getchar();
                printf("Digite o nome do heroi: ");
                scanf("%99[^\n]", h.nome);
                adicionar_heroi(&guilda, h);
                break;
            case 2:
                mostrar_herois(guilda);
                break;
            case 3:
                printf("\nDigite o ID do heroi a ser dispensado: ");
                scanf("%d", &id_remover);
                dispensar_heroi(&guilda, id_remover);
                mostrar_herois(guilda); 
                break;
            case 4:
                printf("\nFechando taverna e liberando memoria...\n");
                liberar_lista(&guilda);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 4);

    return 0;
}
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}
void adicionar_heroi(Lista *lista, Heroi h) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return;
    novo->heroi = h;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *aux = lista->inicio;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
    printf("Heroi '%s' se juntou a guilda!\n", h.nome);
}
void mostrar_herois(Lista lista) {
    printf("\n--- Registro de Herois Ativos ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhum heroi na guilda atualmente.\n");
        return;
    }
    No *aux = lista.inicio;
    while (aux != NULL) {
        printf("[ID: %d] Nome: %s\n", aux->heroi.id, aux->heroi.nome);
        aux = aux->prox;
    }
    printf("---------------------------------\n");
}
void dispensar_heroi(Lista *lista, int id) {
    if (lista->inicio == NULL) {
        printf("Erro: A guilda esta vazia. Nao ha quem dispensar.\n");
        return;
    }
    No *atual = lista->inicio;
    No *anterior = NULL;
    if (lista->inicio->heroi.id == id) {
        lista->inicio = lista->inicio->prox; 
        printf("Heroi '%s' (ID: %d) se aposentou e deixou a guilda.\n", atual->heroi.nome, id);
        free(atual); 
        return;
    }
    while (atual != NULL && atual->heroi.id != id) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Aviso: Nao existe nenhum heroi com o ID %d na guilda.\n", id);
        return;
    }
    anterior->prox = atual->prox;
    printf("Heroi '%s' (ID: %d) foi dispensado para abrir vaga.\n", atual->heroi.nome, id);
    free(atual);
}
void liberar_lista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}
