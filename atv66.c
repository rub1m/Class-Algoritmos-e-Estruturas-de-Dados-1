#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    int pontuacoes[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (pontuacoes[j] < pontuacoes[j + 1]) {
                int temp = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", pontuacoes[i]);
    }   
    printf("\n"); 
    return 0;
}
