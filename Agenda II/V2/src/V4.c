/*#include <stdio.h>
#include <stdlib.h>
 void filaordenation(int *num_pessoas,char *nome,int *idade,long int *telefone){}
int main() {
    void *pbuffer = NULL;
    int *num_pessoas;
    num_pessoas= (int*) malloc (sizeof(int));
    *num_pessoas= 0;
    while (1) {
        // Adiciona espaço para a próxima pessoa
        pbuffer = realloc(pbuffer, (*num_pessoas + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));

        // Aponta para a região de memória correspondente à próxima pessoa
        char *nome = (char*) (pbuffer + (*num_pessoas) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer + (*num_pessoas) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer + (*num_pessoas) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
        scanf("%10s", nome);

        printf("Digite a idade da pessoa: ");
        scanf("%d", idade);

        printf("Digite o telefone da pessoa: ");
        scanf("%ld", telefone);

        // Incrementa o contador de pessoas
        *num_pessoas++;

        // Pergunta se o usuário quer continuar
        char resposta;
        printf("Deseja adicionar outra pessoa? (S/N): ");
        scanf(" %c", &resposta);
        if (resposta == 'N' || resposta == 'n') {
            break;
        }
    }

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for (int i = 0; i < num_pessoas; i++) {
        // Aponta para a região de memória correspondente à i-ésima pessoa
        char *nome = (char*) (pbuffer + i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer + i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer + i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(pbuffer);
    return 0;
}*/  
#include <stdio.h>
#include <stdlib.h>
 //void filaordenation(int *num_pessoas,char *nome,int *idade,long int *telefone){}
int main() {
    void *pbuffer = NULL;
    int *num_pessoas = malloc(sizeof (int));
    *num_pessoas=0;
    int *i=malloc(sizeof(int));
  
    while (1) {
        // Adiciona espaço para a próxima pessoa
        pbuffer = realloc(pbuffer,  (*num_pessoas + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));

        // Aponta para a região de memória correspondente à próxima pessoa
        char *nome = (char*) (pbuffer + *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer + *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer + *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
        scanf("%10s", nome);

        printf("Digite a idade da pessoa: ");
        scanf("%d", idade);

        printf("Digite o telefone da pessoa: ");
        scanf("%ld", telefone);
        getchar(); // Limpa o buffer de entrada para o próximo scanf()
        //filaordenation(int *num_pessoas,char *nome,int *idade,long int *telefone)
        // Incrementa o contador de pessoas
        (*num_pessoas)++;

        // Pergunta se o usuário quer continuar
        char resposta;
        printf("Deseja adicionar outra pessoa? (S/N): ");
        scanf(" %c", &resposta);
        if (resposta == 'N' || resposta == 'n') {
            break;
        }
    }

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for ( *i = 0; *i < *num_pessoas; (*i)++) {
        // Aponta para a região de memória correspondente à i-ésima pessoa
        char *nome = (char*) (pbuffer + *i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer + *i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer + *i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(pbuffer);
    free(num_pessoas);
    return 0;
}
/*int pessoa_a_remover;
printf("Digite o índice da pessoa a remover: ");
scanf("%d", &pessoa_a_remover);

if (pessoa_a_remover < 0 || pessoa_a_remover >= *num_pessoas) {
    printf("Índice inválido!\n");
} else {
    // Desloca todos os dados das pessoas à direita da pessoa a ser removida uma posição para a esquerda
    for (int j = pessoa_a_remover; j < *num_pessoas - 1; j++) {
        char *nome_atual = (char*) (pbuffer + j * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        char *nome_proximo = (char*) (pbuffer + (j + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        strcpy(nome_atual, nome_proximo);

        int *idade_atual = (int*) (pbuffer + j * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        int *idade_proximo = (int*) (pbuffer + (j + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        *idade_atual = *idade_proximo;

        long int *telefone_atual = (long int*) (pbuffer + j * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));
        long int *telefone_proximo = (long int*) (pbuffer + (j + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));
        *telefone_atual = *telefone_proximo;
    }

    // Reduz o número de pessoas na lista em 1
    (*num_pessoas)--;
}*/



