#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    int n_inimigos;
    int *ponteiro_onda;
    printf("Quantos inimigos terá a onda atual? ");
    scanf("%d", &n_inimigos);
    ponteiro_onda = malloc(n_inimigos * sizeof(int));
    if (ponteiro_onda == NULL) {
        printf("Erro: Não foi possivel alocar memória para tantos inimigos!\n");
        return 1;
    }
    for (int i = 0; i < n_inimigos; i++) {
        printf("Digite o ID para o inimigo %d: ", i + 1);
        scanf("%d", &ponteiro_onda[i]); 
    }
    printf("\nOnda de inimigos criada com sucesso! IDs: ");
    for (int i = 0; i < n_inimigos; i++) {
        printf("%d ", ponteiro_onda[i]);
    }
    printf("\n");
    free(ponteiro_onda);
    ponteiro_onda = NULL;
    return 0;
}
