

/*int main() {
    void *pbuffer = NULL;
    int *contador = NULL;
    char *nome = NULL;
    int *idade = NULL;
    char *telefone = NULL;
    char *resposta = NULL;
    // Aloca espaço para o contador
    contador = (int*) malloc(sizeof(int));
    *contador = 0;

    while (1) {
        // Aloca espaço para armazenar os dados da pessoa
        pbuffer = realloc(pbuffer, (*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2));

        // Aponta os ponteiros para as posições corretas no pbuffer
        nome = (char*) (pbuffer + (*contador) * (sizeof(char) * 10 + sizeof(int) * 2));
        idade = (int*) (nome + sizeof(char) * 10);
        telefone = (char*) (idade + sizeof(int));

        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
        scanf("%s", nome);
        printf("Digite a idade da pessoa: ");
        scanf("%d", idade);
        printf("Digite o telefone da pessoa: ");
        scanf("%s", telefone);

        // Incrementa o contador
        (*contador)++;

        // Pergunta se o usuário quer continuar
    
//resposta = (char*) (pbuffer + *contador * (sizeof(char) * 10 + sizeof(int) * 2) + sizeof(int));
resposta = (char*) (pbuffer + (*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2));
printf("Deseja adicionar outra pessoa? (S/N): ");
scanf(" %c", resposta);
if (*resposta == 'N' || *resposta == 'n') {
    break;
}
    }

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for (int i = 0; i < *contador; i++) {
        // Aponta os ponteiros para as posições corretas no pbuffer
        nome = (char*) (pbuffer + i * (sizeof(char) * 10 + sizeof(int) * 2));
        idade = (int*) (nome + sizeof(char) * 10);
        telefone = (char*) (idade + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %s\n", nome, *idade, telefone);
    }

    // Libera a memória alocada
    free(contador);
    free(pbuffer);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

int main() {

    void *pbuffer = NULL;
    int *contador = NULL;
    char *nome = NULL;
    int *idade = NULL;
     long int *telefone = NULL;
    char *resposta = NULL;
    int *opcao=NULL;
    //Aloca memoria pra escolha da opção
    opcao = (int*) malloc (sizeof(int));
    // Aloca espaço para o contador
    contador = (int*) malloc(sizeof(int));
    *contador = 0;

    while (1) {
        // Aloca espaço para armazenar os dados da pessoa
       // pbuffer = realloc(pbuffer, (*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2));
     pbuffer = realloc(pbuffer, (*opcao+1)*(*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2 + sizeof(char) * 12));
        // Aponta os ponteiros para as posições corretas no pbuffer
        nome = (char*) (pbuffer +  (*contador) * (sizeof(char) * 10 + sizeof(int) * 2));
        idade = (int*) (nome + sizeof(char) * 10);
        //telefone = (char*) (idade + sizeof(int));
        //telefone = (char*) (idade + sizeof(int));
   telefone = (long int*) (idade + sizeof(int));
        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
       scanf("%10s", nome);
       // printf("Digite a idade da pessoa: ");
        printf("Digite a idade da pessoa: ");
scanf("%d", idade);
getchar(); // Consumir o '\n' deixado pelo scanf anterior
printf("Digite o telefone da pessoa: ");
scanf(" %ld",telefone);
        //scanf("%d", idade);
        //printf("Digite o telefone da pessoa: ");
       // scanf("%s", telefone);
        //getchar(); // Consumir o '\n' deixado pelo scanf anterior
        //fgets(telefone, 11, stdin);
        // Adiciona o caractere '\0' no final da string de telefone
       // sprintf(telefone + strlen(telefone), "%c", '\0');
        // Incrementa o contador
        (*contador)++;

        // Pergunta se o usuário quer continuar
        resposta = (char*) (pbuffer + (*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2));
        printf("Deseja adicionar outra pessoa? (S/N): ");
        scanf(" %c", resposta);
        if (*resposta == 'N' || *resposta == 'n') {
            break;
        }
    }

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for (int i = 0; i < *contador; i++) {
        // Aponta os ponteiros para as posições corretas no pbuffer
        nome = (char*) (pbuffer + i * (sizeof(char) * 10 + sizeof(int) * 2));
        idade = (int*) (nome + sizeof(char) * 10);
        telefone = ( long int*) (idade + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(contador);
    free(pbuffer);
}
/* switch(*opcao) {
            case 1: {
                Pessoa* nova_pessoa = (Pessoa*)(pBuffer + sizeof(Pessoa) * (*qtd_pessoas));
                incluir(nova_pessoa);
                break;
            }
            case 2: {
                char nome[10];
                printf("Digite o nome da pessoa que deseja apagar: ");
                fgets(nome, 10, stdin);
                apagar(nome);
                break;
            }
            case 3: {
                char nome[10];
                printf("Digite o nome da pessoa que deseja buscar: ");
                fgets(nome, 10, stdin);
                buscar(nome);
                break;
            }
            case 4:
                listar();
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

        exibir_menu();
    } while (opcao != 5);*/
