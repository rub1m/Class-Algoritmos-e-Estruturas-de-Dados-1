#include <stdio.h>
#include <locale.h>
struct ItemColetavel {
    char nome[50];
    int valor_pontos;
};
int main() {
  setlocale(LC_ALL,"Portuguese");
    struct ItemColetavel inventario[3];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Digite o nome do item %d: ", i + 1);
        scanf("%s", inventario[i].nome);
        printf("Digite o valor de pontos do item %d: ", i + 1);
        scanf("%d", &inventario[i].valor_pontos);
        printf("\n");
    }
    struct ItemColetavel maisValioso = inventario[0];
    for(i = 1; i < 3; i++) {
        if(inventario[i].valor_pontos > maisValioso.valor_pontos) {
            maisValioso = inventario[i];
        }
    }
    printf("O item mais valioso coletado foi: [%s]\n", maisValioso.nome);
    return 0;
}
