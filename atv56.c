#include <stdio.h>
int calcularDanoCascata(int nivel) {
    if (nivel == 1) {
        return 1; 
    }
    return nivel + calcularDanoCascata(nivel - 1);
}
int main() {
    int nivel_mago;
    scanf("%d", &nivel_mago);
    int dano_total = calcularDanoCascata(nivel_mago);
    printf("%d\n", dano_total);
    return 0;
}
