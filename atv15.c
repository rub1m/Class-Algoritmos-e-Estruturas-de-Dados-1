#include <stdio.h>
#include <string.h> 
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    char nome_jogador[100];
    char titulo_conquistado[50];
    printf("Digite o nome do heroi: ");
    scanf("%s", nome_jogador);
    printf("Digite o titulo conquistado: ");
    scanf("%s", titulo_conquistado);

    strcat(nome_jogador, " ");
    strcat(nome_jogador, titulo_conquistado);
    printf("O heroi agora eh conhecido como: %s\n", nome_jogador);
    return 0;
}
