#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    char nickname[50];
} Jogador;
typedef struct Node {
    Jogador dados;
    struct Node *proximo;
} Node;
typedef struct Fila {
    Node *inicio;
    Node *fim;
} Fila;
void salvarFila(Fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro critico: Nao foi possivel criar ou abrir o arquivo de persistencia!\n");
        return; 
    }
    Node *aux = f->inicio;
    while (aux != NULL) {
        fwrite(&(aux->dados), sizeof(Jogador), 1, arquivo);
        aux = aux->proximo;
    }
    fclose(arquivo);
    printf("Sucesso: Estado da fila salvo em '%s'.\n", nomeArquivo);
}

int main() {
    Fila minhaFila;
    minhaFila.inicio = NULL;
    minhaFila.fim = NULL;
    int opcao;
    do {
        printf("\n--- MENU MATCHMAKING (PERSISTENCIA) ---\n");
        printf("1. Adicionar Jogador\n");
        printf("2. Remover Jogador\n");
        printf("3. Verificar se a Fila esta Vazia\n");
        printf("4. Ver quem e o proximo da Fila\n");
        printf("5. Salvar Fila em Arquivo\n"); // nova opção 
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: case 2: case 3: case 4:
                printf("Opcoes dos exercicios anteriores mantidas no sistema principal.\n");
                break;
            case 5:
                // Chamando a nova função com o nome de arquivo fixo
                salvarFila(&minhaFila, "matchmaking_queue.bin");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
    return 0;
}
