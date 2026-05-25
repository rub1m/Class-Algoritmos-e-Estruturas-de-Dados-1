#include <stdio.h>
int main() {  
    int n;
    scanf("%d", &n);
    while (n > 1) {
        printf("%d\n", n);
        n = n / 2; 
    }
    return 0;
}
