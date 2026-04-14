#include <stdio.h>
#include <locale.h>
int main() {
  setlocale(LC_ALL,"Portuguese"); 
  float coordenada_x;
    float *ponteiro_x;
    ponteiro_x = &coordenada_x;
    printf("Digite a coordenada X do portal: ");
    scanf("%f", &coordenada_x);
    printf("Posicao do portal no eixo X: %.2f\n", coordenada_x);
    printf("Endereco do portal para teletransporte: %p\n", ponteiro_x);
    return 0;
}
