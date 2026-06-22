#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Mercenario;

typedef struct No {
    Mercenario mercenario;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista);
void inserir_fim(Lista *lista, Mercenario m);
void mostrar_lista(Lista *lista);
int tamanho(Lista *lista); 
void liberar_lista(Lista *lista);

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao;
    int qtd_mercenarios;
    Mercenario novo_mercenario;
    do {
        printf("\n=== Sistema de Gerenciamento da Guilda ===\n");
        printf("1. Recrutar Mercenario\n");
        printf("2. Mostrar Registro\n");
        printf("3. Realizar Censo (Tamanho da Guilda)\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do mercenario: ");
                scanf("%d", &novo_mercenario.id);
                getchar(); 
                printf("Digite o nome do mercenario: ");
                scanf("%99[^\n]", novo_mercenario.nome); 
                inserir_fim(&guilda, novo_mercenario);
                break;     
            case 2:
                mostrar_lista(&guilda);
                break;                
            case 3:
                qtd_mercenarios = tamanho(&guilda);
                printf("\n[CENSO OFICIAL]: A guilda possui %d mercenario(s) sob seu comando no momento.\n", qtd_mercenarios);
                break;   
            case 4:
                printf("\nFechando os registros e liberando a memoria...\n");
                liberar_lista(&guilda);
                break;             
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}
void inserir_fim(Lista *lista, Mercenario m) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->mercenario = m;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *aux = lista->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    printf("Mercenario '%s' recrutado com sucesso!\n", m.nome);
}
void mostrar_lista(Lista *lista) {
    printf("\n--- Registro de Mercenarios ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda esta vazia.\n");
        return;
    } 
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->mercenario.id, aux->mercenario.nome);
        aux = aux->prox;
    }
    printf("-------------------------------\n");
}
int tamanho(Lista *lista) {
    int contador = 0; 
    No *aux = lista->inicio; 
    while (aux != NULL) {
        contador++;      
        aux = aux->prox;
    }
    return contador;
}
void liberar_lista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
}
