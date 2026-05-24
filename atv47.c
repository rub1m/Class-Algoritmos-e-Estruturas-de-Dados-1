#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Unidade;
int main() {
    int n;
    printf("--- Montagem do Esquadrao ---\n");
    printf("Quantas unidades tera o seu esquadrao? ");
    scanf("%d", &n);
    Unidade *esquadrao = (Unidade *) malloc(n * sizeof(Unidade));
    if (esquadrao == NULL) {
        printf("Ops! Faltou memoria no sistema.\n");
        return 1;
    }
    printf("\nDigite os dados de cada unidade (sem espacos no nome):\n");
    for (int i = 0; i < n; i++) {
        printf("\nUnidade %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", esquadrao[i].nome);
        printf("HP: ");
        scanf("%d", &esquadrao[i].vida);
        printf("ATK: ");
        scanf("%d", &esquadrao[i].ataque);
    }
    FILE *arquivo = fopen("squad.dat", "wb");
    if (arquivo == NULL) {
        printf("\nErro ao criar o arquivo squad.dat!\n");
        free(esquadrao); 
        return 1;
    }
    fwrite(esquadrao, sizeof(Unidade), n, arquivo);
    fclose(arquivo);
    printf("\n>> Esquadrao salvo com sucesso em 'squad.dat'!\n");
    int indice_mais_forte = 0; 
    for (int i = 1; i < n; i++) {
        if (esquadrao[i].ataque > esquadrao[indice_mais_forte].ataque) {
            indice_mais_forte = i;
        }
    }
    printf(">> Unidade mais forte do esquadrao: %s (ATK: %d)\n", 
           esquadrao[indice_mais_forte].nome, 
           esquadrao[indice_mais_forte].ataque);
    free(esquadrao);

    return 0; // Fim do programa!
}
