#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Membro {
    int id;
    char nome[50];
    struct Membro *prox;
} Membro;
void salvar_guild_arquivo(Membro *lista) {
    FILE *arquivo = fopen("guild_roster.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }
    Membro *atual = lista;
    while (atual != NULL) {
        fwrite(atual, sizeof(int) + sizeof(char[50]), 1, arquivo);
        atual = atual->prox;
    }
    fclose(arquivo);
    printf("Guilda salva com sucesso em guild_roster.bin!\n");
}
