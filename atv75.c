#include <stdio.h>
int particao(int arr[], int inicio, int fim) {
    int pivo = arr[fim]; 
    int i = (inicio - 1); 
    for (int j = inicio; j < fim; j++) {      
        if (arr[j] < pivo) {
            i++; 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;
    return (i + 1);
}
void quickSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {      
        int pi = particao(arr, inicio, fim);
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fim);
    }
}
int main() {
    int N;
    scanf("%d", &N);   
    int mmrs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &mmrs[i]);
    }
    quickSort(mmrs, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", mmrs[i]);
    }
    printf("\n");
    return 0;
}
