#include <stdio.h>
typedef struct {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
} Personagem;
int main() {
    int n;
    printf("Digite o numero de personagens: ");
    scanf("%d", &n);
    Personagem personagens[n];
    for (int i = 0; i < n; i++) {
        printf("Digite ID, Nome, Forca, Agilidade e Inteligencia do personagem %d:\n", i + 1);
        scanf("%d %s %d %d %d", &personagens[i].id, personagens[i].nome, &personagens[i].forca, &personagens[i].agilidade, &personagens[i].inteligencia);
    }
    int opcao = 0;
    while (opcao != 2) {
        printf("\n--- MENU DO MESTRE DE JOGO ---\n");
        printf("1 - Consultar Personagem\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            int id_busca;
            printf("Digite a ID do personagem que deseja buscar: ");
            scanf("%d", &id_busca);
            int encontrado = 0; 
            for (int i = 0; i < n; i++) {
                if (personagens[i].id == id_busca) {
                    float media = (personagens[i].forca + personagens[i].agilidade + personagens[i].inteligencia) / 3.0;
                    printf("Personagem Encontrado! Nome: %s, Media de Atributos: %.2f\n", personagens[i].nome, media);
                    encontrado = 1;
                    break; 
                }
            }
            if (encontrado == 0) {
                printf("Personagem não existe.\n");
            }
        } else if (opcao != 2) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    printf("Encerrando o sistema. Boa sessao, Mestre!\n");
    return 0;
}
