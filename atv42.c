#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int resolucao_x;
    int resolucao_y;
    float volume_som;
} Configuracao;

int main() {
    Configuracao config_atual;
    FILE *arquivo = fopen("config.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo config.txt nao encontrado!\n");
        return 1; 
    }
    fscanf(arquivo, "%d %d %f", &config_atual.resolucao_x, &config_atual.resolucao_y, &config_atual.volume_som);
    printf("Configuracoes carregadas:\n");
    printf("Resolucao: %dx%d\n", config_atual.resolucao_x, config_atual.resolucao_y);
    printf("Volume: %.1f\n", config_atual.volume_som);
    fclose(arquivo);
    return 0; 
}
