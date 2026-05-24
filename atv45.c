#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int nivel;
    float vida;
    float mana;
} Personagem;
int main() {
    int opcao;
    Personagem novo_char;
    printf("Sistema de Save Game do RPG\n");
    while (1) {
        printf("\nMenu Principal:\n");
        printf("1 - Criar Novo Personagem\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite o nome do personagem: ");
            scanf("%s", novo_char.nome);
            printf("Digite o nivel: ");
            scanf("%d", &novo_char.nivel);
            printf("Digite a vida (HP): ");
            scanf("%f", &novo_char.vida);
            printf("Digite a mana (MP): ");
            scanf("%f", &novo_char.mana);
            FILE *arquivo = fopen("savegame.sav", "wb");
            if (arquivo == NULL) {
                printf("Erro ao criar o arquivo de save!\n");
                return 1;
            }
            fwrite(&novo_char, sizeof(Personagem), 1, arquivo);
            fclose(arquivo);
            printf("\n>> Sucesso! O personagem %s foi salvo no arquivo savegame.sav!\n", novo_char.nome);
        } 
        else if (opcao == 2) {
            printf("Encerrando o sistema. Ate mais!\n");
            break; 
        } 
        else {
            printf("Opcao invalida. Tente de novo.\n");
        }
    }
    return 0;
}
