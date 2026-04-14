#include <stdio.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    int moedas_coletadas[] = {10, 50, 20, 5, 100};
    int pontuacao_total = 0;
    int *ponteiro_moeda;
    ponteiro_moeda = moedas_coletadas;
    for (int i = 0; i < 5; i++) {
        pontuacao_total = pontuacao_total + *ponteiro_moeda;
        ponteiro_moeda++;
    }
    printf("Pontuação total do nivel: %d\n", pontuacao_total);
    return 0;
}
