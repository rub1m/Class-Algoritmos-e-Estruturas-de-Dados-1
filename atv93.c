#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

typedef struct No {
    Membro membro;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista);
void inserir_fim(Lista *lista, Membro m);
void mostrar_lista(Lista *lista);
No* pesquisar(Lista *lista, int id); 
void alterar_nome(Lista *lista, int id, char novo_nome[]);
void liberar_lista(Lista *lista);

int main() {
    Lista guilda;
    inicializar_lista(&guilda);
    int opcao, id_busca;
    Membro novo_membro;
    char novo_nome[100];
    do {
        printf("\n=== Registro da Guilda ===\n");
        printf("1. Adicionar Membro\n");
        printf("2. Mostrar Registro\n");
        printf("3. Alterar Nome de Membro\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do membro: ");
                scanf("%d", &novo_membro.id);
                getchar(); 
                printf("Digite o nome do membro: ");
                scanf("%99[^\n]", novo_membro.nome);                 
                inserir_fim(&guilda, novo_membro);
                break;             
            case 2:
                mostrar_lista(&guilda);
                break;               
            case 3:
                printf("\nDigite o ID do membro que vai mudar de nome: ");
                scanf("%d", &id_busca);
                getchar(); 
                printf("Digite o NOVO nome para este membro: ");
                scanf("%99[^\n]", novo_nome);            
                alterar_nome(&guilda, id_busca, novo_nome);
                break;             
            case 4:
                printf("\nFechando o registro da guilda...\n");
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
void inserir_fim(Lista *lista, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
    novo->membro = m;
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
    printf("Membro '%s' adicionado com sucesso!\n", m.nome);
}
void mostrar_lista(Lista *lista) {
    printf("\n--- Membros Oficiais ---\n");
    if (lista->inicio == NULL) {
        printf("A guilda ainda nao tem membros.\n");
        return;
    }
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->membro.id, aux->membro.nome);
        aux = aux->prox;
    }
    printf("------------------------\n");
}
No* pesquisar(Lista *lista, int id) {
    No *aux = lista->inicio;
    while (aux != NULL && aux->membro.id != id) {
        aux = aux->prox;
    }
    return aux; 
}
void alterar_nome(Lista *lista, int id, char novo_nome[]) {
    No *membro_encontrado = pesquisar(lista, id);
    if (membro_encontrado == NULL) {
        printf("Erro: Membro com ID %d nao encontrado no registro!\n", id);
        return;
    }
    printf("Nome atualizado! '%s' agora e conhecido como '%s'.\n", membro_encontrado->membro.nome, novo_nome);
    strcpy(membro_encontrado->membro.nome, novo_nome);
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
