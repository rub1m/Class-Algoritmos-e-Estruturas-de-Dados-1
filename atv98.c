#include <stdio.h>
#include <stdlib.h>

typedef struct Membro {
    int id;
    char nome[100];
    int nivel;
} Membro;
typedef struct No {
    Membro dados;
    struct No *prox;
} No;
typedef struct {
    No *inicio;
} Lista;
Lista carregar_guilda() {
    Lista lista;
    lista.inicio = NULL;
    FILE *arquivo = fopen("guild_roster.b", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura!\n");
        return lista;
    }
    Membro temp;
    while (fread(&temp, sizeof(Membro), 1, arquivo) == 1) {
        No *novo = (No*)malloc(sizeof(No));
        novo->dados = temp;
        novo->prox = NULL;
        if (lista.inicio == NULL) {
            lista.inicio = novo;
        } else {
            No *aux = lista.inicio;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    fclose(arquivo);
    return lista;
}
void mostrar_guilda(Lista lista) {
    No *aux = lista.inicio;
    printf("\n--- Membros da Guilda ---\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s | Nivel: %d\n", aux->dados.id, aux->dados.nome, aux->dados.nivel);
        aux = aux->prox;
    }
}
