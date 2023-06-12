#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 //tamanho máximo da string

int main()
{
    char nomes[MAX]; //string que armazena os nomes
    int opcao; //opção do menu
    char nome[20]; //nome a ser adicionado ou removido
    char *p; //ponteiro auxiliar

    nomes[0] = '\0'; //inicializa a string vazia

    do {
        printf("Menu:\n");
        printf("1) Adicionar nome\n");
        printf("2) Remover nome\n");
        printf("3) Listar\n");
        printf("4) Sair\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: //adicionar nome
                printf("Digite o nome a ser adicionado: ");
                scanf("%s", nome);
                strcat(nomes, nome); //concatena o nome na string
                strcat(nomes, ","); //concatena uma vírgula para separar os nomes
                break;
            case 2: //remover nome
                printf("Digite o nome a ser removido: ");
                scanf("%s", nome);
                p = strstr(nomes, nome); //procura o nome na string
                if (p != NULL) //se encontrou o nome
                {
                    strcpy(p, p + strlen(nome) + 1); //copia o resto da string após o nome e a vírgula para o lugar do nome
                    printf("Nome removido com sucesso.\n");
                }
                else //se não encontrou o nome
                {
                    printf("Nome não encontrado.\n");
                }
                break;
            case 3: //listar nomes
                printf("Nomes armazenados:\n");
                p = strtok(nomes, ","); //separa a primeira palavra antes da vírgula
                while (p != NULL) //enquanto houver palavras na string
                {
                    printf("%s\n", p); //imprime a palavra
                    p = strtok(NULL, ","); //separa a próxima palavra antes da vírgula
                }
                
            case 4: 
               break;
            default:
               printf("Opção inválida.\n");

        }

    } while (opcao != 4);

    return 0;
}