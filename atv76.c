#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int particao(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; 
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[fim]);
    return i + 1;
}
int particaoAleatoria(int arr[], int inicio, int fim) {
    int indice_aleatorio = inicio + rand() % (fim - inicio + 1);
    trocar(&arr[indice_aleatorio], &arr[fim]);
    return particao(arr, inicio, fim);
}
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particaoAleatoria(arr, inicio, fim);        
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fim);
    }
}
int main() {
    srand(time(NULL));
    int N;
    scanf("%d", &N);   
    int pontuacoes[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    quickSort(pontuacoes, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");
    return 0;
}
