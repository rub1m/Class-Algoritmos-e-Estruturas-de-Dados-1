#include <stdio.h>
#include <stdlib.h>
int main() {
    int opcao;
    char evento[100]; 
    printf("Sistema de Log do Jogo Iniciado\n");
    while (1) {
        printf("\nMenu Principal:\n");
        printf("1 - Registrar novo evento\n");
        printf("2 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            printf("Digite o evento (Lembrete: digite_sem_espacos!): ");
            scanf("%s", evento);
            FILE *arquivo = fopen("game_log.txt", "a");
            if (arquivo == NULL) {
                printf("Putz, deu erro ao tentar abrir ou criar o arquivo de log.\n");
                return 1; 
            }
            fprintf(arquivo, "%s\n", evento);
            fclose(arquivo);
            printf("-> Evento registrado com sucesso no log!\n");
        } 
        else if (opcao == 2) {
            printf("Encerrando o sistema de log. Ate a proxima!\n");
            break; 
        } 
        else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0; 
}
