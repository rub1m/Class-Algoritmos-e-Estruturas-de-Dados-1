#include <stdio.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};
    int *inventario[3];
    inventario[0] = balas;
    inventario[1] = granadas;
    inventario[2] = foguetes;
    
    printf("Inventário Inicial:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n\n", *inventario[2]);
    for (int i = 0; i < 3; i++) {
        *inventario[i] = *inventario[i] - 1;
    }
    printf("Inventário Após o Uso:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);
    return 0;
}
