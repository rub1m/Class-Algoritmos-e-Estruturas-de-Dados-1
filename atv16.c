#include <stdio.h>
#include <string.h> 
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    char inventario[5][20];
    char item_necessario[20];
    int encontrou = 0; 
    printf("Digite os 5 itens que estão no seu inventário:\n");
    for (int i = 0; i < 5; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s", inventario[i]); 
    }
    printf("\nQual item é necessario para abrir a porta? ");
    scanf("%s", item_necessario);
    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], item_necessario) == 0) {
            encontrou = 1; 
            break; 
        }
    }
    if (encontrou == 1) {
        printf("\nPorta aberta!\n");
    } else {
        printf("\nVocê não tem o item necessário.\n");
    }
    return 0;
}
