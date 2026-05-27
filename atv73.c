#include <stdio.h>
void particao(int n, int v[]) {
    int pivo = v[n - 1]; 
    int s[n];             
    int inicio = 0;     
    int fim = n - 1;    
    for (int i = 0; i < n; i++) {
        if (v[i] <= pivo) {
            s[inicio] = v[i];
            inicio++;        
        } else {
            s[fim] = v[i];  
            fim--;           
        }
    }
    for (int i = 0; i < n; i++) {
        v[i] = s[i];
    }
}
int main() {
    int N;
    scanf("%d", &N);
    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    particao(N, v);
        printf("%d ", v[i]);
    }
    printf("\n");  
    return 0;
}
