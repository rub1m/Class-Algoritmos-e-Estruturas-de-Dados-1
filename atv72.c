#include <stdio.h>
typedef struct {
    int posicao;
    char nome[50];
} Piloto;
void intercala(Piloto arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1; 
    int n2 = fim - meio;    
    Piloto esquerda[n1];
    Piloto direita[n2];
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
        if (esquerda[i].posicao <= direita[j].posicao) {
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
void mergeSort(Piloto arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        intercala(arr, inicio, meio, fim);
    }
}

int main() {
    int total_pilotos;
    scanf("%d", &total_pilotos);
    Piloto pilotos[total_pilotos];
    for (int i = 0; i < total_pilotos; i++) {
        scanf("%d %s", &pilotos[i].posicao, pilotos[i].nome);
    }
    mergeSort(pilotos, 0, total_pilotos - 1);
    for (int i = 0; i < total_pilotos; i++) {
        printf("%d %s\n", pilotos[i].posicao, pilotos[i].nome);
    }
    return 0;
}
