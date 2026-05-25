#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;
int main() {
    Campeao esquadrao[3];
    FILE *arquivo;
    arquivo = fopen("squad.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo squad.dat!\n");
        printf("Voce precisa criar o arquivo primeiro.\n");
        return 1; 
    }
    fread(esquadrao, sizeof(Campeao), 3, arquivo);
    fclose(arquivo);
    int maiorVida = esquadrao[0].vida; 
    int indiceTanque = 0;   
    for (int i = 1; i < 3; i++) {
        if (esquadrao[i].vida > maiorVida) {
            maiorVida = esquadrao[i].vida;
            indiceTanque = i;
        }
    }
    printf("%s: Tanque do esquadrão.\n", esquadrao[indiceTanque].nome);
    return 0;
}
