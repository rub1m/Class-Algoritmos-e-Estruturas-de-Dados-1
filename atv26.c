#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL,"Portuguese");
    int *mochila;
    int i;
    mochila = (int *)malloc(3 * sizeof(int));
    if (mochila == NULL) {
        printf("Erro: Faltou memória para criar a mochila!\n");
        return 1;
    }
    printf("--- Primeira Coleta (3 itens) ---\n");
    for (i = 0; i < 3; i++) {
        printf("Digite o valor do item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    printf("\nItens atuais na mochila: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", mochila[i]);
    }
    printf("\n\n");
    printf("Você encontrou um item de expansão! Aumentando a mochila...\n\n");
    mochila = (int *)realloc(mochila, 6 * sizeof(int));
    if (mochila == NULL) {
        printf("Erro: Faltou memória para expandir a mochila!\n");
        return 1;
    }
    printf("--- Segunda Coleta (mais 3 itens) ---\n");
    for (i = 3; i < 6; i++) {
        printf("Digite o valor do novo item %d: ", i + 1);
        scanf("%d", &mochila[i]);
    }
    printf("\nSua mochila completa agora tem os itens:\n[ ");
    for (i = 0; i < 6; i++) {
        printf("%d ", mochila[i]);
    }
    printf("]\n");
    free(mochila);
    printf("\nMemoria liberada com sucesso. Fim da aventura!\n");
    return 0;
}
