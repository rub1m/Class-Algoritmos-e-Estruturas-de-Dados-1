#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL,"Portuguese");
    int plataformas[] = {10, 20, 5, 15, 30};
    int *ponteiro_plataforma;
    int altura_total = 0;
    for (int i = 0; i < 5; i++) {
        altura_total = altura_total + *(plataformas + i);
    }
    printf("Altura total do salto: %d metros!\n", altura_total);
    return 0;
}
