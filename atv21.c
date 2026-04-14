#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
int main() {
    setlocale(LC_ALL,"Portuguese");
    int *duracao_fumaca;
    duracao_fumaca = malloc(sizeof(int));
    if (duracao_fumaca != NULL) {
        *duracao_fumaca = 5;
        printf("Bomba de fumaça ativada! Duração: %d segundos.\n", *duracao_fumaca);
        free(duracao_fumaca); 
        duracao_fumaca = NULL;
        printf("A fumaca se dissipou.\n");
    } else {
        printf("Erro: Falha ao usar a bomba de fumaça (sem memória)!\n");
    }
    return 0;
}
