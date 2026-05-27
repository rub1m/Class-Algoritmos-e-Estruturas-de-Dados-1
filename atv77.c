#include <stdio.h>
struct Jogador {
    int id;
    int pontuacao;
};
typedef struct Jogador Jogador; 
int particao(Jogador arr[], int inicio, int fim) {
    int pivo = arr[fim].pontuacao; 
    int i = (inicio - 1);            
    for (int j = inicio; j < fim; j++) {       
        if (arr[j].pontuacao >= pivo) {
            i++;           
            Jogador temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Jogador temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;
    return (i + 1); 
}
void quickSort(Jogador arr[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particao(arr, inicio, fim);
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fim);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    Jogador jogadores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &jogadores[i].id, &jogadores[i].pontuacao);
    }
    quickSort(jogadores, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", jogadores[i].id, jogadores[i].pontuacao);
    }  
    return 0;
}
