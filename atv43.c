#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Inimigo;
int main() {
    Inimigo atual;
    Inimigo mais_forte;
    mais_forte.ataque = -1; 
    FILE *arquivo = fopen("wave_data.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo wave_data.txt nao pode ser aberto ou encontrado!\n");
        return 1; 
    }
    while (fscanf(arquivo, "%s %d %d", atual.nome, &atual.vida, &atual.ataque) != EOF) {
        if (atual.ataque > mais_forte.ataque) {
            mais_forte = atual;
        }
    }
    fclose(arquivo);
    printf("Maior Ameaca: %s, Vida: %d, Ataque: %d\n", mais_forte.nome, mais_forte.vida, mais_forte.ataque);
    return 0;
}
