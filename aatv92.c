#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char nome[50];
} Mercenario;
typedef struct No {
    Mercenario mercenario;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;
void inicializar_lista(Lista *lista);
void contratar_mercenario(Lista *lista, Mercenario m);
void exibir_companhia(Lista *lista);
void demitir_todos_mercenarios(Lista *lista);

int main() {
    Lista minha_companhia;
    inicializar_lista(&minha_companhia); 
    int opcao;
    Mercenario m;
    do {
        printf("\n=== MENU DA COMPANHIA DE MERCENARIOS ===\n");
        printf("1. Contratar mercenario (Inserir no fim)\n");
        printf("2. Exibir companhia\n");
        printf("3. Declarar falencia (Demitir todos)\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do mercenario: ");
                scanf("%d", &m.id);
                getchar(); 
                printf("Digite o nome do mercenario: ");
                scanf("%49[^\n]", m.nome); 
                contratar_mercenario(&minha_companhia, m);
                break;            
            case 2:
                exibir_companhia(&minha_companhia);
                break;               
            case 3:
                printf("\n[ALERTA]: O ouro acabou! Falencia declarada!\n");
                demitir_todos_mercenarios(&minha_companhia);
                break;              
            case 4:
                printf("\nFechando o gerenciador... Limpando dados por seguranca.\n");
                demitir_todos_mercenarios(&minha_companhia);
                break;            
            default:
                printf("\nOpcao invalida! Escolha de 1 a 4.\n");
        }
    } while(opcao != 4);

    return 0;
}
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}
void contratar_mercenario(Lista *lista, Mercenario m) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Faltou memoria no sistema!\n");
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
    printf("Mercenario '%s' (ID: %d) entrou para a companhia!\n", m.nome, m.id);
}
void exibir_companhia(Lista *lista) {
    printf("\n--- Membros da Companhia ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda está vazia. Nenhum mercenario ativo.\n");
        return;
    } 
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->mercenario.id, aux->mercenario.nome);
        aux = aux->prox;
    }
    printf("----------------------------\n");
}
void demitir_todos_mercenarios(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A companhia ja esta totalmente vazia. Nada a fazer.\n");
        return;
    }
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *proximo_no = atual->prox; 
        printf("Demitindo %s e liberando memoria...\n", atual->mercenario.nome);
        free(atual); 
        atual = proximo_no; 
    }
    lista->inicio = NULL; 
    if (lista->inicio == NULL) {
        printf("\n[CONFIRMACAO]: Toda a memoria foi liberada. Companhia 100%% dissolvida!\n");
    }
}
