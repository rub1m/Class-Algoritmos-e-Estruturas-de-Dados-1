#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    void *ponteiro_duracao;
    ponteiro_duracao = malloc(sizeof(int));
    if (ponteiro_duracao == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    *((int *)ponteiro_duracao) = 10;
    printf("Power-up 'Super Salto' ativado! Duração: %d segundos.\n", *((int *)ponteiro_duracao));
    *((int *)ponteiro_duracao) = *((int *)ponteiro_duracao) - 3;
    printf("3 segundos se passaram... Duração restante: %d segundos.\n", *((int *)ponteiro_duracao));

    free(ponteiro_duracao);
    return 0;
}
