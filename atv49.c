#include <stdio.h>
#include <stdlib.h> 
int main() {
    FILE *arquivo;
    arquivo = fopen("level_1_map.dat", "r");
    if (arquivo == NULL) {
        printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
        perror("Detalhes do erro");
        exit(1); 
    }
    printf("Arquivo aberto com sucesso!\n");
    fclose(arquivo);
    return 0;
}
