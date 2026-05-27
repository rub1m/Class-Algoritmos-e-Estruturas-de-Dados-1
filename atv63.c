#include <stdio.h>
int main() {
    int placar[5] = {120, 125, 130, 142, 150};
    int novo_tempo;
    scanf("%d", &novo_tempo);
    if (novo_tempo < placar[4]) {       
        int i = 4; 
        while (i > 0 && placar[i - 1] > novo_tempo) {
            placar[i] = placar[i - 1]; 
            i--; 
        }
        placar[i] = novo_tempo;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", placar[i]);
    }
    printf("\n");
    return 0;
}
