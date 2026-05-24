#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    float hp;
    float atk;
} Inimigo;
int main() {
    Inimigo lista_inimigos[3];
    FILE *arquivo = fopen("inimigos.txt", "r");
    if (arquivo == NULL) {
        printf("Ops! Nao consegui encontrar o arquivo 'inimigos.txt'.\n");
        printf("Ele esta na mesma pasta do codigo em C?\n");
        return 1; 
    }
    for(int i = 0; i < 3; i++) {
        fscanf(arquivo, "%s %f %f", lista_inimigos[i].nome, &lista_inimigos[i].hp, &lista_inimigos[i].atk);
    }
    fclose(arquivo);
    printf("--- Procurando Inimigos de Elite ---\n");
    for(int i = 0; i < 3; i++) {
        float nivel_ameaca = lista_inimigos[i].hp + lista_inimigos[i].atk;
        if (nivel_ameaca >= 200.0) {
            printf("%s - Nivel de Ameaca: %.1f\n", lista_inimigos[i].nome, nivel_ameaca);
        }
    }
    return 0;
