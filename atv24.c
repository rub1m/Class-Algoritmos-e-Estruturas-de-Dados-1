#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL,"Portuguese");
    int linhas, colunas;
    int **mapa; 
    int contador_tijolos = 0;
    printf("Digite o numero de linhas do mapa: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas do mapa: ");
    scanf("%d", &colunas);
    mapa = malloc(linhas * sizeof(int *)); 
    if (mapa == NULL) {
        printf("Erro ao alocar linhas!\n");
        return 1;
    }
    for (int i = 0; i < linhas; i++) {
        mapa[i] = malloc(colunas * sizeof(int)); 
        if (mapa[i] == NULL) {
            printf("Erro ao alocar colunas na linha %d!\n", i);
            return 1;
        }
    }
    printf("\nPreencha o mapa (0: Vazio, 1: Tijolo, 2: Moeda):\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mapa[i][j]);
        }
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mapa[i][j] == 1) {
                contador_tijolos++;
            }
        }
    }
    printf("\n--- Resultado ---");
    printf("\nO mapa possui %d blocos de tijolo.\n", contador_tijolos);
 
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
    mapa = NULL;
    return 0;
}
