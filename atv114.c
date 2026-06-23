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
void inserir(Fila *f, Jogador j) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->dados = j;
    novo->proximo = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}
void carregarFila(Fila *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Aviso: Arquivo de salvamento '%s' nao encontrado.\n", nomeArquivo);
        printf("Iniciando o sistema com uma fila vazia.\n");
        return; //deixa a fila como estava
    }
    Jogador jogadorLido;
    while (fread(&jogadorLido, sizeof(Jogador), 1, arquivo) == 1) {
        inserir(f, jogadorLido);
    }
    fclose(arquivo);
    printf("Sucesso: Fila de matchmaking restaurada com sucesso a partir do arquivo!\n");
}

int main() {
    Fila minhaFila;
    minhaFila.inicio = NULL;
    minhaFila.fim = NULL;
    carregarFila(&minhaFila, "matchmaking_queue.bin");
    int opcao;
    do {
        printf("\n--- MENU MATCHMAKING SYSTEM ---\n");
        printf("1. Adicionar Jogador\n");
        printf("2. Remover Jogador\n");
        printf("3. Verificar se a Fila esta Vazia\n");
        printf("4. Ver quem e o proximo da Fila\n");
        printf("5. Salvar Fila em Arquivo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: case 2: case 3: case 4: case 5:
                printf("Executando operacoes do menu...\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    return 0;
}
