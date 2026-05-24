#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;
int main() {
    FILE *arquivo = fopen("profiles.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro: Arquivo profiles.dat nao encontrado!\n");
        printf("Dica: Rode o programa auxiliar primeiro para criar o arquivo.\n");
        return 1;
    }
    PlayerProfile perfil_atual;
    printf("--- Carregando Save Games ---\n");
    while (fread(&perfil_atual, sizeof(PlayerProfile), 1, arquivo) == 1) {
        printf("Jogador: %s | Rank: ", perfil_atual.nome);
        if (perfil_atual.highScore > 10000) {
            printf("Mestre do Jogo\n");
        } 
        else if (perfil_atual.highScore > 5000) {
            printf("Veterano\n");
        } 
        else {
            printf("Aspirante\n");
        }
    }
    fclose(arquivo);
    printf("--- Leitura Concluida ---\n");
    return 0;
}

/* PROG (profiles.dat)
#include <stdio.h>
typedef struct {
    char nome[50];
    int nivel;
    int highScore;
} PlayerProfile;
int main() {
    FILE *f = fopen("profiles.dat", "wb");
    if (f == NULL) return 1;
    PlayerProfile p1 = {"Mestre", 99, 15000}; 
    PlayerProfile p2 = {"Veterano", 45, 7500};      
    PlayerProfile p3 = {" Aspirante", 5, 2000};       
    fwrite(&p1, sizeof(PlayerProfile), 1, f);
    fwrite(&p2, sizeof(PlayerProfile), 1, f);
    fwrite(&p3, sizeof(PlayerProfile), 1, f);
    fclose(f);
    printf("Arquivo de teste 'profiles.dat' gerado com sucesso!\n");
    return 0;
}
*/
