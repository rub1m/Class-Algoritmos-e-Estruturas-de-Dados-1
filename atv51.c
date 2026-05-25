#include <stdio.h>
typedef struct {
    char tipo[50]; 
    int hp;       
} Inimigo;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Inimigo unidadeAtual; 
        scanf("%s %d", unidadeAtual.tipo, &unidadeAtual.hp);
        printf("Inimigo: %s, HP: %d\n", unidadeAtual.tipo, unidadeAtual.hp);
    }
    return 0;
}
