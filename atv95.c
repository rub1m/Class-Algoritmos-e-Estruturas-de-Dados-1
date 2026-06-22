#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char tipo[50]; 
} Inimigo;
typedef struct No {
    Inimigo inimigo;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;
void inicializar_lista(Lista *lista);
void inserir_fim(Lista *lista, Inimigo ini);
void mostrar_onda(Lista lista);
void liberar_lista(Lista *lista);
Lista criar_lista(int n); 

int main() {
    Lista onda_atual;
    inicializar_lista(&onda_atual);    
    int opcao, n;
    Inimigo ini_avulso;
    do {
        printf("\n=== Central de Defesa da Torre ===\n");
        printf("1. Adicionar inimigo avulso (Inserir no fim)\n");
        printf("2. Mostrar inimigos da onda atual\n");
        printf("3. Iniciar NOVA ONDA (O foco do problema!)\n");
        printf("4. Sair do jogo\n");
        printf("Escolha sua estrategia: ");
        scanf("%d", &opcao);
        getchar(); 
        switch(opcao) {
            case 1:
                printf("\nDigite o ID do inimigo: ");
                scanf("%d", &ini_avulso.id);
                getchar();
                printf("Digite o tipo do inimigo: ");
                scanf("%49[^\n]", ini_avulso.tipo);            
                inserir_fim(&onda_atual, ini_avulso);
                break;               
            case 2:
                mostrar_onda(onda_atual);
                break;                
            case 3:
                printf("\nQuantos inimigos virao nesta nova onda? ");
                scanf("%d", &n);
                getchar(); 
                liberar_lista(&onda_atual); 
                onda_atual = criar_lista(n);           
                printf("\nALERTA: Uma nova onda com %d inimigo(s) comecou!\n", n);
                break;            
            case 4:
                printf("\nEncerrando o jogo e limpando o campo de batalha...\n");
                liberar_lista(&onda_atual);
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
void inserir_fim(Lista *lista, Inimigo ini) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }
    novo->inimigo = ini;
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
}
void mostrar_onda(Lista lista) {
    printf("\n--- Inimigos da Onda Atual ---\n");
    if (lista.inicio == NULL) {
        printf("O campo esta limpo! Nenhum inimigo a vista.\n");
        return;
    } 
    No *aux = lista.inicio;
    while (aux != NULL) {
        printf("ID: %d | Tipo: %s\n", aux->inimigo.id, aux->inimigo.tipo);
        aux = aux->prox;
    }
    printf("------------------------------\n");
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
Lista criar_lista(int n) {
    Lista nova_onda;
    inicializar_lista(&nova_onda);   
    Inimigo novo_ini;
    for (int i = 0; i < n; i++) {
        printf("\n--- Lendo dados do %dº inimigo ---\n", i + 1);
        printf("ID: ");
        scanf("%d", &novo_ini.id);
        getchar();   
        printf("Tipo: ");
        scanf("%49[^\n]", novo_ini.tipo);
        getchar(); 
        inserir_fim(&nova_onda, novo_ini); 
    }
    return nova_onda; 
}
