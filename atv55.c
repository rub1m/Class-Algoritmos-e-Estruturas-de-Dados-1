#include <stdio.h>
typedef struct {
    int id;
    char nickname[50];
    int reputacao;
} Jogador;
int buscaBinaria(int idBusca, Jogador vetor[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2; 
        if (vetor[meio].id == idBusca) {
            return meio;   
        } else if (vetor[meio].id < idBusca) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1;
        }
    }
    return -1; 
}
int main() {
    int n;
    scanf("%d", &n);
    Jogador jogadores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &jogadores[i].id, jogadores[i].nickname, &jogadores[i].reputacao);
    }
    int opcao = 0;
    while (opcao != 2) {
        printf("1 - Adicionar Reputacao\n");
        printf("2 - Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            int id_pesquisado;
            scanf("%d", &id_pesquisado);
            int indice = buscaBinaria(id_pesquisado, jogadores, n);
            if (indice != -1) {
                jogadores[indice].reputacao += 100; 
                printf("Nickname: %s, Nova Reputacao: %d\n", jogadores[indice].nickname, jogadores[indice].reputacao);
            } else {
                printf("Jogador com ID %d nao encontrado.\n", id_pesquisado);
            }
        }
    }
    return 0;
}
