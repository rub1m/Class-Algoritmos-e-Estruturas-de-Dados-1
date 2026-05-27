#include <stdio.h>
int encontrarMaximo(int vetor[], int inicio, int fim) {
    if (inicio == fim) {
        return vetor[inicio];
    }
    int meio = (inicio + fim) / 2;
    int maxEsquerda = encontrarMaximo(vetor, inicio, meio);
    int maxDireita = encontrarMaximo(vetor, meio + 1, fim);
    if (maxEsquerda > maxDireita) {
        return maxEsquerda;
    } else {
        return maxDireita;
    }
}
int main() {
    int N;
    scanf("%d", &N);  
    int fragmentos[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &fragmentos[i]);
    }
    int poderMaximo = encontrarMaximo(fragmentos, 0, N - 1);
    printf("%d\n", poderMaximo);
    return 0;
}
