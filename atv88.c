#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome[100];
} Estudante;

typedef struct No {
    Estudante dado;
    struct No *prox;
} No;

// Estrutura da lista, que contém o ponteiro para o início
typedef struct {
    No *inicio;
} Lista;

// Função para exibir o menu de opções
void menu() {
    printf("\n======== Gerenciador de Party =========\n");
    printf("1 - Adicionar jogador no inicio da party\n");
    printf("2 - Adicionar jogador no fim da party\n");
    printf("5 - Mostrar membros da party\n");
    printf("7 - Remover primeiro jogador da party\n");
    printf("8 - Remover ultimo jogador da party\n");
    printf("9 - Sair\n");
    printf("=======================================\n");
}

// Função para ler os dados de um novo jogador
void ler(Estudante *e) {
    printf("Digite a matricula: ");
    scanf("%d", &e->mat);
    printf("Digite o nome: ");
    scanf(" %[^\n]s", e->nome);
}

// Insere um nó no início da lista
void inserir_inicio(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = plista->inicio;
    plista->inicio = novo;
}

// Insere um nó no fim da lista
void inserir_fim(Lista *plista, Estudante dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    
    if (plista->inicio == NULL) { // Lista vazia
        plista->inicio = novo;
    } else {
        No *pi;
        for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
        pi->prox = novo;
    }
}

// Mostra todos os elementos da lista
void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("A party esta vazia!\n");
        return;
    }
    No *pi;
    printf("\n--- Membros da Party ---\n");
    for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
        printf("Matricula: %d | Nome: %s\n", pi->dado.mat, pi->dado.nome);
    }
    printf("------------------------\n");
}

// Deleta o primeiro nó da lista
void deletar_inicio(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("A lista ja esta vazia!\n");
    } else {
        No *pi = plista->inicio;
        plista->inicio = pi->prox;
        free(pi);
    }
}

// Função para deletar o último nó da lista
void deletar_fim(Lista *plista) {
    // Caso 1 (Lista Vazia): 
    if (plista->inicio == NULL) {
        printf("\n>> Nao e possivel remover: A party ja esta vazia!\n");
        return; // Sai da função pra não dar erro
    }
    // Caso 2 (Apenas um Jogador): 
    // Se o 'prox' do primeiro cara é NULL, significa que ele é o único na lista
    if (plista->inicio->prox == NULL) {
        No *noRemover = plista->inicio;
        plista->inicio = NULL; // O ponteiro de início agora fica vazio
        free(noRemover); // Libera a memória
        printf("\n>> Jogador removido. A party agora esta vazia!\n");
        return;
    }
    // Caso 3 (Vários Jogadores):
    // Precisamos de dois ponteiros pra caminhar pela lista juntos
    No *atual = plista->inicio;
    No *anterior = NULL;
    // Percorre a lista. Quando o 'atual' chegar no último nó, 
    // o 'anterior' vai estar exatamente no penúltimo.
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }
    // O penúltimo cara agora aponta pra NULL, virando o novo final da lista
    anterior->prox = NULL;
    // Libera a memória do jogador que estava no final
    free(atual);
    printf("\n>> Ultimo jogador removido da party com sucesso!\n");
}
}
int main() {
    Lista lista;
    lista.inicio = NULL;
    int op;
    do {
        menu();
        scanf("%d", &op);
        switch(op) {
            case 1: {
                Estudante e;
                ler(&e);
                inserir_inicio(&lista, e);
                break;
            }
            case 2: {
                Estudante e;
                ler(&e);
                inserir_fim(&lista, e);
                break;
            }
            case 5:
                mostrar(lista);
                break;
            case 7:
                deletar_inicio(&lista);
                break;
            case 8:
                deletar_fim(&lista);
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (op != 9);
    return 0;
}
