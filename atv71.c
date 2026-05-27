#include <stdio.h>
typedef struct {
    int id;
    int nivel_ameaca;
} Nave;
void merge(Nave arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1; 
    int n2 = fim - meio;     
    Nave esquerda[n1];
    Nave direita[n2];
    for (int i = 0; i < n1; i++) {
        esquerda[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        direita[j] = arr[meio + 1 + j];
    }
    int i = 0;     
    int j = 0;     
    int k = inicio; 
    while (i < n1 && j < n2) {
        if (esquerda[i].nivel_ameaca <= direita[j].nivel_ameaca) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = direita[j];
        j++;
        k++;
    }
}
void mergeSort(Nave arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        merge(arr, inicio, meio, fim);
    }
}
int main() {
    int N;
    scanf("%d", &N);
    Nave naves[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &naves[i].id, &naves[i].nivel_ameaca);
    }
    mergeSort(naves, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", naves[i].id);
    }
    printf("\n");
    return 0;
}
