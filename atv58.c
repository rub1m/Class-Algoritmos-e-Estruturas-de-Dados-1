#include <stdio.h>
int calcularDanoEco(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return calcularDanoEco(n - 1) + calcularDanoEco(n - 2); 
}
int main() {
    int N;
    printf("Digite o numero do golpe: ");
    scanf("%d", &N);
    int resultado_dano = calcularDanoEco(N);
    printf("Dano bonus do golpe %d: %d\n", N, resultado_dano); 
    return 0;
}
