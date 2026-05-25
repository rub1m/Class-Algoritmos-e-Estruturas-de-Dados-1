#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;
typedef struct {
    char tipo[50];
    int hp;
} Inimigo;
typedef struct {
    int x;
    int y;
} Unidade;
typedef struct {
    int id;
    char nome[50];
    int forca;
    int agilidade;
    int inteligencia;
} Personagem;
typedef struct {
    int id;
    char nickname[50];
    int reputacao;
} Jogador;
int buscaBinaria(int idBusca, Jogador vetor[], int tamanho) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio].id == idBusca) return meio;
        if (vetor[meio].id < idBusca) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}
int calcularDanoCascata(int nivel) {
    if (nivel == 1) return 1; 
    return nivel + calcularDanoCascata(nivel - 1);
}
int contarCristais(int vetor[], int tamanho, int indice) {
    if (indice == tamanho) return 0; 
    int carga = (vetor[indice] > 0) ? 1 : 0;
    return carga + contarCristais(vetor, tamanho, indice + 1);
}
int main() {
    int opcao = -1;
    while (opcao != 0) {
        printf("       LISTA DE ALGORITMOS        \n");
        printf("1. Carregar Esquadrao (fread)\n");
        printf("2. Carregamento Seguro (perror/exit)\n");
        printf("3. Calculo de Dano Final (O(1))\n");
        printf("4. Analise Inimigos (Loop linear)\n");
        printf("5. Proximidade Inimigos (Malloc/AoE)\n");
        printf("6. Ritual de Diminuicao (O(log n))\n");
        printf("7. Consulta Personagens (Busca Linear)\n");
        printf("8. Gerenciar Jogadores (Busca Binaria)\n");
        printf("9. Dano em Cascata (Recursao simples)\n");
        printf("10. Cristais de Mana (Recursao vetor)\n");
        printf("0. Sair\n");
        printf("Escolha qual questao rodar: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: {
                Campeao esquadrao[3];
                FILE *arquivo = fopen("squad.dat", "rb"); 
                if (arquivo != NULL) {
                    fread(esquadrao, sizeof(Campeao), 3, arquivo); 
                    fclose(arquivo);
                    int indiceTanque = 0;
                    for (int i = 1; i < 3; i++) {
                        if (esquadrao[i].vida > esquadrao[indiceTanque].vida) {
                            indiceTanque = i; 
                        }
                    }
                    printf("%s: Tanque do esquadrao.\n", esquadrao[indiceTanque].nome);
                } else {
                    printf("Ops, precisa criar o squad.dat primeiro!\n");
                }
                break;
            }
            case 2: {
                FILE *arquivo_mapa = fopen("level_1_map.dat", "r");
                if (arquivo_mapa == NULL) {
                    printf("ERRO CRITICO: Nao foi possivel carregar os dados do mapa.\n");
                    perror("Detalhes do erro");
                    exit(1); 
                }
                fclose(arquivo_mapa);
                break;
            }
            case 3: {
                float forca, arma, buff;
                printf("Digite forca base, bonus da arma e bonus do buff:\n");
                scanf("%f %f %f", &forca, &arma, &buff);
                printf("%.2f\n", forca + arma + buff);
                break;
            }
            case 4: {
                int n;
                printf("Quantidade de inimigos: ");
                scanf("%d", &n);       
                Inimigo atual;
                for (int i = 0; i < n; i++) {
                    scanf("%s %d", atual.tipo, &atual.hp);
                    printf("Inimigo: %s, HP: %d\n", atual.tipo, atual.hp);
                }
                break;
            }
            case 5: {
                int n;
                printf("Numero de inimigos no campo: ");
                scanf("%d", &n);
                Unidade *unidades = (Unidade *)malloc(n * sizeof(Unidade));
                for (int i = 0; i < n; i++) {
                    scanf("%d %d", &unidades[i].x, &unidades[i].y);
                }           
                float raio;
                printf("Raio de explosao: ");
                scanf("%f", &raio);                
                int pares_agrupados = 0;              
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        float dist = sqrt(pow(unidades[j].x - unidades[i].x, 2) + pow(unidades[j].y - unidades[i].y, 2));
                        if (dist <= raio) pares_agrupados++;
                    }
                }
                printf("Duplas na area de efeito: %d\n", pares_agrupados);
                free(unidades); 
                break;
            }
            case 6: {
                int energia;
                printf("Energia inicial do Golem: ");
                scanf("%d", &energia);             
                while (energia > 1) { 
                    printf("%d\n", energia);
                    energia = energia / 2; 
                }
                break;
            }
            case 7: {
                int n;
                printf("Total de personagens na campanha: ");
                scanf("%d", &n);
                Personagem p[n];               
                for(int i = 0; i < n; i++) {
                    scanf("%d %s %d %d %d", &p[i].id, p[i].nome, &p[i].forca, &p[i].agilidade, &p[i].inteligencia);
                }                
                int opc_menu2 = 0;
                while (opc_menu2 != 2) { 
                    printf("\n1 - Consultar Personagem\n2 - Sair\nEscolha: ");
                    scanf("%d", &opc_menu2);                  
                    if (opc_menu2 == 1) {
                        int id_busca, achou = 0;
                        scanf("%d", &id_busca);                      
                        for(int i = 0; i < n; i++) {
                            if (p[i].id == id_busca) {
                                float media = (p[i].forca + p[i].agilidade + p[i].inteligencia) / 3.0;
                                printf("Nome: %s, Media Atributos: %.2f\n", p[i].nome, media);
                                achou = 1;
                                break;
                            }
                        }
                        if (!achou) printf("Personagem nao existe.\n");
                    }
                }
                break;
            }
            case 8: {
                int n;
                printf("Numero de jogadores (IDs crescentes): ");
                scanf("%d", &n);
                Jogador j[n];              
                for (int i = 0; i < n; i++) {
                    scanf("%d %s %d", &j[i].id, j[i].nickname, &j[i].reputacao);
                }              
                int opc_menu3 = 0;
                while (opc_menu3 != 2) {
                    printf("\n1 - Adicionar Reputacao\n2 - Sair\nEscolha: ");
                    scanf("%d", &opc_menu3);               
                    if (opc_menu3 == 1) {
                        int id_busca;
                        scanf("%d", &id_busca);
                        int indice = buscaBinaria(id_busca, j, n);                      
                        if (indice != -1) {
                            j[indice].reputacao += 100; 
                            printf("Nickname: %s, Nova Reputacao: %d\n", j[indice].nickname, j[indice].reputacao);
                        } else {
                            printf("Jogador com ID %d nao encontrado.\n", id_busca);
                        }
                    }
                }
                break;
            }
            case 9: {
                int nivel;
                printf("Nivel do Mago: ");
                scanf("%d", &nivel);
                printf("Dano Total Cascata: %d\n", calcularDanoCascata(nivel));
                break;
            }
            case 10: {
                int n;
                printf("Quantidade de cristais no inventario: ");
                scanf("%d", &n);                
                int cristais[n];
                for (int i = 0; i < n; i++) {
                    scanf("%d", &cristais[i]);
                }                
                printf("Cristais carregados: %d\n", contarCristais(cristais, n, 0));
                break;
            }
            case 0:
                printf("Falou!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}
