#include <stdio.h>
#include <locale.h>
void ler_cenario(int n, int *cenario) {
    printf("Digite a configuracao do cenario (0 para vazio, 1 para plataforma):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", (cenario + i));
    }
}
int main() {
   setlocale(LC_ALL,"Portuguese");
   int n;
    printf("Quantos blocos tem o cenario? ");
    scanf("%d", &n);
    int cenario[n];
    ler_cenario(n, cenario);
    for (int i = 0; i < n; i++) {
        if (*(cenario + i) == 1) {
            *(cenario + i) = 2; 
            break; 
        }
    }
    printf("\nCenario com Power-up posicionado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(cenario + i));
    }
    printf("\n");
    return 0;
}
