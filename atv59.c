#include <stdio.h>
typedef struct {
    int id;           
    char nome[50];     
    int hp;           
    int ataque;       
} Monstro;
int buscaBinariaRecursiva(int idBusca, Monstro vetor[], int inicio, int fim) {
    if (inicio > fim) {
        return -1; 
    }
    int meio = (inicio + fim) / 2;
    if (vetor[meio].id == idBusca) {
        return meio; 
    }
    if (idBusca < vetor[meio].id) {
        return buscaBinariaRecursiva(idBusca, vetor, inicio, meio - 1);
    } 
    else {
        return buscaBinariaRecursiva(idBusca, vetor, meio + 1, fim);
    }
}
int main() {
    int n;
    printf("Quantos monstros vamos registrar? ");
    scanf("%d", &n);
    Monstro bestiario[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d", &bestiario[i].id, bestiario[i].nome, &bestiario[i].hp, &bestiario[i].ataque);
    }
    int idDesejado = -1;
    while (1) { 
        printf("\nDigite o ID para buscar (ou 0 para sair): ");
        scanf("%d", &idDesejado);
        if (idDesejado == 0) {
            break; 
        }
        int indiceEncontrado = buscaBinariaRecursiva(idDesejado, bestiario, 0, n - 1);
        if (indiceEncontrado != -1) {
            printf("Monstro Encontrado: %s (ID: %d) - HP: %d, Ataque: %d\n", 
                   bestiario[indiceEncontrado].nome, 
                   bestiario[indiceEncontrado].id, 
                   bestiario[indiceEncontrado].hp, 
                   bestiario[indiceEncontrado].ataque);
        } else {
            printf("Monstro com ID %d nao encontrado.\n", idDesejado);
        }
    }
    return 0;
}
