#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    int *vida_inimigo;
    vida_inimigo = malloc(sizeof(int));
    if (vida_inimigo == NULL) {
        printf("Erro: Faltou memória no sistema!\n");
        return 1; // Sai do programa avisando que deu erro
    }
    *vida_inimigo = 80;
    printf("Um novo inimigo apareceu com %d de vida!\n", *vida_inimigo);
    *vida_inimigo = *vida_inimigo - 35;
    printf("O jogador atacou! Vida restante do inimigo: %d\n", *vida_inimigo);
   
  free(vida_inimigo);
    return 0;
}
