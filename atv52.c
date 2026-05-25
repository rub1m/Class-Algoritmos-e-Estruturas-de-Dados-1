#include <stdio.h>
#include <stdlib.h> 
#include <math.h>  
typedef struct {
    int x;
    int y;
} Unidade;
int main() {
    int n;
    scanf("%d", &n);
    Unidade *esquadrao = (Unidade *)malloc(n * sizeof(Unidade));
    if (esquadrao == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &esquadrao[i].x, &esquadrao[i].y);
    }
    float raio;
    scanf("%f", &raio);
    int duplasProximas = 0; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distancia = sqrt(pow(esquadrao[j].x - esquadrao[i].x, 2) + pow(esquadrao[j].y - esquadrao[i].y, 2));
            if (distancia <= raio) {
                duplasProximas++;
            }
        }
    }
    printf("Duplas na area de explosao: %d\n", duplasProximas);
    free(esquadrao);
    return 0;
}
