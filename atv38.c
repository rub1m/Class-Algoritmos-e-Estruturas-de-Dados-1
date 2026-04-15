#include <stdio.h>
#include <locale.h>
enum EstadoPersonagem {
    PARADO,
    CORRENDO,
    PULANDO
};
int main() {
  setlocale(LC_ALL,"Portuguese");
    enum EstadoPersonagem estado_atual;
    int opcao;
    printf("Defina o estado do personagem (0 para PARADO, 1 para CORRENDO, 2 para PULANDO): ");
    scanf("%d", &opcao);
    estado_atual = (enum EstadoPersonagem) opcao;
    if (estado_atual == PARADO) {
        printf("O personagem está parado.\n");
    } 
    else if (estado_atual == CORRENDO) {
        printf("O personagem está correndo!\n");
    } 
    else if (estado_atual == PULANDO) {
        printf("O personagem está pulando no ar!\n");
    } 
    else {
        printf("Estado inválido!\n");
    }
    return 0;
}
