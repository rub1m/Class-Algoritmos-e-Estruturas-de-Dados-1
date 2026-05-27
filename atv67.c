#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int pontuacoes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pontuacoes[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;       
        for (int j = 0; j < n - i - 1; j++) {        
            if (pontuacoes[j] < pontuacoes[j + 1]) {               
                int temp = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = temp;                
                trocou = 1; 
            }
        }
        if (trocou == 0) {
            break; 
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");    
    return 0;
}
