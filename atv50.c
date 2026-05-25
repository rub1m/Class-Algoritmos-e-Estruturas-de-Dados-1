#include <stdio.h>
int main() {
    float forcaBase, bonusArma, bonusBuff;
    float danoTotal;
    printf("Digite a forca base do personagem: ");
    scanf("%f", &forcaBase);
    printf("Digite o bonus de dano da arma: ");
    scanf("%f", &bonusArma);
    printf("Digite o bonus do feitico de buff: ");
    scanf("%f", &bonusBuff);
    danoTotal = forcaBase + bonusArma + bonusBuff;
    printf("Dano total causado: %.2f\n", danoTotal);
    return 0;
}
