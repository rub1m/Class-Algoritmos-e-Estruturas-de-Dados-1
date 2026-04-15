#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL,"Portuguese");
    int qtd_inimigos;
    int *status_inimigos;
    int i;
    printf("Bem-vindo a nova fase!\n");
    printf("Quantos inimigos esta fase terá? ");
    scanf("%d", &qtd_inimigos);
    status_inimigos = (int *)calloc(qtd_inimigos, sizeof(int));
    if (status_inimigos == NULL) {
        printf("Erro: Faltou memoria para carregar os inimigos!\n");
        return 1; 
    }
    printf("\n--- Status Inicial ---\n");
    for (i = 0; i < qtd_inimigos; i++) {
        printf("Inimigo %d: Inativo (%d)\n", i + 1, status_inimigos[i]);
    }
    for (i = 0; i < qtd_inimigos; i++) {
        status_inimigos[i] = 1; 
    }
    printf("\n--- Status Final---\n");
    for (i = 0; i < qtd_inimigos; i++) {
        printf("Inimigo %d: Ativo (%d)\n", i + 1, status_inimigos[i]);
    }
    free(status_inimigos);
    printf("\nMemoria liberada com sucesso. Bom jogo!\n");
    return 0;
}
