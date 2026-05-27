#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int portal_alfa[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &portal_alfa[i]);
    }  
    int m;    
    scanf("%d", &m);
    int portal_beta[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &portal_beta[i]);
    }
    int lista_final[n + m];
    int i = 0; 
    int j = 0; 
    int k = 0; 
    while (i < n && j < m) {
        if (portal_alfa[i] <= portal_beta[j]) {
            lista_final[k] = portal_alfa[i];
            i++; 
        } else {
            lista_final[k] = portal_beta[j];
            j++; 
        }
        k++; 
    }   
    while (i < n) {
        lista_final[k] = portal_alfa[i];
        i++;
        k++;
    }
    while (j < m) {
        lista_final[k] = portal_beta[j];
        j++;
        k++;
    }
    for (int x = 0; x < n + m; x++) {
        printf("%d ", lista_final[x]);
    }
    printf("\n");   
    return 0;
}
