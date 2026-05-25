#include <stdio.h>
typedef struct {
    char nome[50]; 
    int hp;       
} Monstro;
int main() {
    int n;
    scanf("%d", &n);
    Monstro horda[n]; 
    for (int i = 0; i < n; i++) {
        scanf("%s %d", horda[i].nome, &horda[i].hp); 
    }
    Monstro alvoMaisFraco = horda[0];
    for (int i = 1; i < n; i++) {
        if (horda[i].hp < alvoMaisFraco.hp) {
            alvoMaisFraco = horda[i];
        }
    }
    printf("Alvo prioritario: %s (%d HP)\n", alvoMaisFraco.nome, alvoMaisFraco.hp);
    return 0;
}
