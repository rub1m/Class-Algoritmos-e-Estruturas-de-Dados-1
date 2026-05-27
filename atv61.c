#include <stdio.h>
#include <stdlib.h> 
int main() {
    int N;
    scanf("%d", &N);
    int *scores = (int *)malloc(N * sizeof(int));
    if (scores == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1; 
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        int indice_menor = i; 
        for (int j = i + 1; j < N; j++) {
            if (scores[j] < scores[indice_menor]) {
                indice_menor = j; 
            }
        }
        if (indice_menor != i) {
            int temp = scores[i];
            scores[i] = scores[indice_menor];
            scores[indice_menor] = temp;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n"); 
    free(scores);
    return 0;
}
