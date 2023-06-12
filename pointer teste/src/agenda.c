#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *pBuffer; //ponteiro void que armazena os dados da agenda
int *qtd;//ponteiro para a quantidade de pessoas na agenda
int *opcao; //ponteiro para a opção do menu
char *nomes; //ponteiro para a string de nomes
int *idades; //ponteiro para o array de idades
int *telefones; //ponteiro para o array de telefones
#define TAM_NOME 10 //tamanho máximo do nome


/*void adicionar(); //função que adiciona uma pessoa na agenda
void remover(); //função que remove uma pessoa da agenda
void buscar(); //função que busca uma pessoa na agenda pelo nome
void listar(); //função que lista todas as pessoas da agenda
*/
int main()
{

    pBuffer = malloc(sizeof(int) * 3); //aloca espaço inicial para três inteiros: qtd, opcao e tamanho máximo da string de nomes
    if (pBuffer == NULL) //se não conseguiu alocar memória
    {
        printf("Erro de alocação.\n");
        exit(1);
    }
    qtd = pBuffer; //qtd aponta para o primeiro inteiro do pBuffer
    opcao = pBuffer + sizeof(int); //opcao aponta para o segundo inteiro do pBuffer
    nomes = pBuffer + 2 * sizeof(int); //nomes aponta para a string de nomes
    *qtd = 0; //inicializa a quantidade de pessoas com zero
    *opcao = 0; //inicializa a opção com zero
    memset(nomes, 0, TAM_NOME * sizeof(char)); //inicializa a string de nomes com '\0'

    pBuffer = realloc(pBuffer, sizeof(int) * 3 + TAM_NOME * sizeof(char) + sizeof(int) * 2); //realoca o espaço do pBuffer para caber os arrays de idades e telefones
    if (pBuffer == NULL) //se não conseguiu realocar memória
    {
        printf("Erro de alocação.\n");
        exit(1);
    }
    qtd = pBuffer; //qtd aponta para o primeiro inteiro do pBuffer
    opcao = pBuffer + sizeof(int); //opcao aponta para o segundo inteiro do pBuffer
    nomes = pBuffer + 2 * sizeof(int); //nomes aponta para a string de nomes
    idades = pBuffer + 2 * sizeof(int) + TAM_NOME * sizeof(char); //idades aponta para o array de idades
    telefones = pBuffer + 2 * sizeof(int) + TAM_NOME * sizeof(char) + sizeof(int) * (*qtd); //telefones aponta para o array de telefones

    do {
        printf("Menu:\n");
        printf("1) Adicionar\n");
        printf("2) Remover\n");
        printf("3) Buscar\n");
        printf("4) Listar\n");
        printf("5) Sair\n");
        printf("Selecione uma opcao acima:\n");
        scanf("%d", opcao);

       /* switch(*opcao)
        {
            case 1:
                //adicionar();
                break;
            case 2:
               // remover();
                break;
            case 3: 
               // buscar();
                break;  
            case 4:
               // listar();
                break;
            case 5:
                break;
            default:
                //printf("Opção inválida.\n");

        }*/

    } while (*opcao != 5);

    free(pBuffer); //libera a memória alocada pelo pBuffer

    return 0;
}
