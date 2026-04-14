#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LINHAS 5
#define COLUNAS 10
int main() {
   setlocale(LC_ALL,"Portuguese");
    int *level_map;
    level_map = malloc(LINHAS * COLUNAS * sizeof(int));
    if (level_map == NULL) {
        printf("Erro: Falha ao carregar o mapa do jogo!\n");
        return 1;
    }
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == LINHAS - 1) {              
                *(level_map + (i * COLUNAS + j)) = 1;
            } else {              
                *(level_map + (i * COLUNAS + j)) = 0;
            }
        }
    }
    printf("Mapa da Fase Gerado:\n\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {     
            printf("%d ", *(level_map + (i * COLUNAS + j)));
        }     
        printf("\n");
    }
    free(level_map);
    level_map = NULL;
    return 0;
}
