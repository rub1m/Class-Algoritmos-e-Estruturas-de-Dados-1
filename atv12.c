#include <stdio.h>
#include <string.h>
#include <locale.h>
int main() {
   setlocale(LC_ALL,"Portuguese");
    char nome_jogador[50];
    printf("Digite o nome do seu personagem: ");
    scanf(" %[^\n]", nome_jogador);
    int tamanho = strlen(nome_jogador);
    if (tamanho <= 15) {
        printf("Nome valido! Bem-vindo ao jogo, %s!\n", nome_jogador);
    } else {
        printf("Nome muito longo! Por favor, escolha um nome com até 15 caracteres.\n");
    }
    return 0;
}
