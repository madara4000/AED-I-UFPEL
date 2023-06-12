#include <stdio.h>
#include <stdlib.h>

int main() {
    void *pbuffer = NULL;
    int *contador = NULL;
    char *nome = NULL;
    int *idade = NULL;
    long int *telefone = NULL;
    char *resposta = NULL;
    // Aloca espaço para o contador
    contador = (int*) malloc(sizeof(int));
    *contador = 0;

    while (1) {
        // Aloca espaço para armazenar os dados da pessoa
   
     pbuffer = realloc(pbuffer, (*contador + 1) * (sizeof(char) * 10 + sizeof(int) * 2 + sizeof(long int) *1));
        // Aponta os ponteiros para as posições corretas no pbuffer
        nome = (char*) (pbuffer + (*contador) * (sizeof(char) * 10 + sizeof(int) * 2));
        idade = (int*) (nome + sizeof(char) * 10);
        telefone =  (long int *) (nome + sizeof(char) * 10 + sizeof(int));
       // telefone =  (long int *) (nome + sizeof(char) * 10 + sizeof(int) + sizeof(long int));
        printf("Digite o nome da pessoa (max 10 caracteres): ");
       scanf("%10s", nome);
       // printf("Digite a idade da pessoa: ");
        printf("Digite a idade da pessoa: ");
scanf("%d", idade);
getchar(); // Consumir o '\n' deixado pelo scanf anterior
printf("Digite o telefone da pessoa: ");
scanf("%ld", telefone);
    
      
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
        telefone = (long int*) (idade + sizeof( int));
          //telefone = (long int*) (idade + sizeof( long int));
        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(contador);
    free(pbuffer);
}