#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_LEN 50

int main() {
    char** nomes = NULL;
    int n_nomes = 0;
    int capacidade = 0;
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1) Adicionar nome\n");
        printf("2) Remover nome\n");
        printf("3) Listar\n");
        printf("4) Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char nome[MAX_NOME_LEN];
                printf("Digite um nome: ");
                scanf("%s", nome);

                if (n_nomes == capacidade) {
                    // precisa alocar mais memória
                    capacidade = (capacidade == 0 ? 1 : capacidade * 2);
                    nomes = realloc(nomes, capacidade * sizeof(char*));
                }

                nomes[n_nomes] = malloc((strlen(nome) + 1) * sizeof(char));
                strcpy(nomes[n_nomes], nome);
                n_nomes++;

                printf("Nome adicionado com sucesso!\n");
                break;
            }
            case 2: {
                if (n_nomes == 0) {
                    printf("Nenhum nome para remover.\n");
                    break;
                }

                char nome[MAX_NOME_LEN];
                printf("Digite um nome a ser removido: ");
                scanf("%s", nome);

                int indice_nome = -1;

                for (int i = 0; i < n_nomes; i++) {
                    if (strcmp(nomes[i], nome) == 0) {
                        indice_nome = i;
                        break;
                    }
                }

                if (indice_nome != -1) {
                    free(nomes[indice_nome]);

                    // deslocar nomes à direita do nome removido
                    for (int i = indice_nome + 1; i < n_nomes; i++) {
                        nomes[i - 1] = nomes[i];
                    }

                    n_nomes--;
                    printf("Nome removido com sucesso!\n");
                } else {
                    printf("Nome nao encontrado.\n");
                }
                break;
            }
            case 3: {
                if (n_nomes == 0) {
                    printf("Nenhum nome para listar.\n");
                    break;
                }

                printf("Lista de nomes:\n");

                for (int i = 0; i < n_nomes; i++) {
                    printf("%s\n", nomes[i]);
                }
                break;
            }
            case 4: {
                // liberar memória antes de sair do programa
                for (int i = 0; i < n_nomes; i++) {
                    free(nomes[i]);
                }
                free(nomes);

                printf("Saindo do programa.\n");
                exit(0);
            }
            default: {
                printf("Opcao invalida.\n");
                break;
            }
        }

        printf("\n");
    }
}