#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char nome[100];
} Ward;
typedef struct no {
    Ward ward;
    struct no *prox;
} No;
typedef struct {
    No *inicio;
} Lista;

void inicializar_lista(Lista *lista);
void adicionar_ward(Lista *lista, Ward w);
void deletar_apos(Lista *lista, int id_referencia);
void mostrar_wards(Lista *lista);
void liberar_lista(Lista *lista);
int main() {
    Lista minhas_wards;
    inicializar_lista(&minhas_wards);
    int opcao, id_alvo;
    Ward novo_ward;
    do {
        printf("\n=== Menu do Mago Arcano ===\n");
        printf("1. Adicionar Ward (no final)\n");
        printf("2. Lancar 'Ward Shatter' (deletar apos ID)\n");
        printf("3. Mostrar Wards Ativos\n");
        printf("4. Sair\n");
        printf("Escolha sua magia: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("\nDigite o ID numérico do Ward: ");
                scanf("%d", &novo_ward.id);
                getchar(); 
                printf("Digite o nome do Ward: ");
                scanf("%[^\n]s", novo_ward.nome); 
                adicionar_ward(&minhas_wards, novo_ward);
                printf("Ward '%s' conjurado com sucesso!\n", novo_ward.nome);
                break;
            case 2:
                printf("\nDigite o ID do Ward de referencia para o Shatter: ");
                scanf("%d", &id_alvo);
                deletar_apos(&minhas_wards, id_alvo);
                break;
            case 3:
                mostrar_wards(&minhas_wards);
                break;            
            case 4:
                printf("\nDesfazendo todas as magias e saindo...\n");
                liberar_lista(&minhas_wards);
                break; 
            default:
                printf("\nMagia desconhecida! Tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
}
void adicionar_ward(Lista *lista, Ward w) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Falta de mana (Erro de alocacao de memoria)!\n");
        return;
    }
    novo->ward = w;
    novo->prox = NULL; 
    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *aux = lista->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo; // O último vagão agora aponta para o novo
    }
}
// O feitiço principal: Deletar o nó DEPOIS do ID passado
void deletar_apos(Lista *lista, int id_referencia) {
    if (lista->inicio == NULL) {
        printf("Aviso: Nenhuma ward ativa! O Ward Shatter falhou.\n");
        return;
    }
    No *aux = lista->inicio;
    while (aux != NULL && aux->ward.id != id_referencia) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        printf("Aviso: Ward com ID %d nao encontrado. O feitiço falhou.\n", id_referencia);
        return;
    }
    if (aux->prox == NULL) {
        printf("Aviso: O Ward %d e o ultimo da sequencia! Nao ha nenhum ward apos ele para ser destruido.\n", id_referencia);
        return;
    }
    No *alvo_destruicao = aux->prox;    
    aux->prox = alvo_destruicao->prox; 
    printf("BOOM! Ward Shatter ativou! O ward '%s' (ID: %d) foi destruido.\n", alvo_destruicao->ward.nome, alvo_destruicao->ward.id);
    free(alvo_destruicao); 
void mostrar_wards(Lista *lista) {
    printf("\n--- Sequencia de Wards Ativos ---\n");
    if (lista->inicio == NULL) {
        printf("Nenhum escudo magico ativo no momento.\n");
    } else {
        No *aux = lista->inicio;
        while (aux != NULL) {
            printf("[ID: %d | Nome: %s] ", aux->ward.id, aux->ward.nome);
            if (aux->prox != NULL) {
                printf("-> "); 
            }
            aux = aux->prox;
        }
        printf("\n");
    }
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
