#include <stdio.h>
void particao(int n, int v[]) {
    int pivo = v[n - 1]; 
    int i = 0;       
    for (int j = 0; j < n - 1; j++) {
        if (v[j] < pivo) {
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
            i++; 
        }
    }
    int temp = v[i];
    v[i] = v[n - 1];
    v[n - 1] = temp;
}
int main() {
    int n;
    scanf("%d", &n);  
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    particao(n, v);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");  
    return 0;
}
