#include <stdio.h>
#include <locale.h>
typedef struct {
    int pontos;
    float pos_x;
    float pos_y;
} Coletavel;
int main() {
  setlocale(LC_ALL,"Portuguese");
    Coletavel gema_rara;
    printf("Digite o valor em pontos da gema: ");
    scanf("%d", &gema_rara.pontos);
    printf("Digite a posição X: ");
    scanf("%f", &gema_rara.pos_x);
    printf("Digite a posição Y: ");
    scanf("%f", &gema_rara.pos_y);
    printf("\nColetavel criado! Valor: %d pontos. Posição: (X=%.1f, Y=%.1f)\n", 
            gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);
    return 0;
}
