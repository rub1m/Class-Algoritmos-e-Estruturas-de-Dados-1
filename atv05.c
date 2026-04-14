#include <stdio.h>
#include <locale.h>
int main() {
 setlocale(LC_ALL,"Portuguese");
    int pontuacao = 0;
    int *ponteiro_pontuacao;
    ponteiro_pontuacao = &pontuacao;
    printf("Pontuação inicial: %d\n", pontuacao);
   
    *ponteiro_pontuacao = *ponteiro_pontuacao + 10;
    *ponteiro_pontuacao = *ponteiro_pontuacao + 10;
    *ponteiro_pontuacao = *ponteiro_pontuacao + 10;
    printf("Pontuação final após coletar 3 moedas: %d\n", pontuacao);
    return 0;
}
