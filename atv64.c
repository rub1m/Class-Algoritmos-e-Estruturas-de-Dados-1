#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n;
    scanf("%d", &n);
    int *fragmentos = (int *)malloc(n * sizeof(int));
    if (fragmentos == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &fragmentos[i]);
    }
    for (int i = 1; i < n; i++) {
        int chave = fragmentos[i]; 
        int j = i - 1; 
        while (j >= 0 && fragmentos[j] > chave) {
            fragmentos[j + 1] = fragmentos[j]; 
            j = j - 1; 
        }
        fragmentos[j + 1] = chave;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", fragmentos[i]);
    }
    printf("\n");
    free(fragmentos);
    return 0;
}
