void ordenarPessoas(int *num_pessoas, char *nomes, int *idades, long int *telefones) {
    int *n = malloc(sizeof(int));
    int *j = malloc(sizeof(int));
    char *nomeTemp = malloc(sizeof(char) * 10);
    int *idadeTemp = malloc(sizeof(int));
    long int *telefoneTemp = malloc(sizeof(long int));

    for (*n = 0; *n < num_pessoas; (*n)++) {
        for (*j = *n + 1; *j < num_pessoas; (*j)++) {
            if (strcmp(nomes + (*n) * 10, nomes + (*j) * 10) > 0) {
                // Troca os dados das pessoas
                strcpy(nomeTemp, nomes + (*n) * 10);
                strcpy(nomes + (*n) * 10, nomes + (*j) * 10);
                strcpy(nomes + (*j) * 10, nomeTemp);

                *idadeTemp = *(idades+*n);
               *(idades+*n)  = *(idades+*j);
              *(idades+*j) = *idadeTemp;

                *telefoneTemp = *(telefones+*n);
                *(telefones+*n)= *(telefones+*j);
                *(telefones+*j) = *telefoneTemp;
            }
        }
    }

    free(n);
    free(j);
    free(nomeTemp);
    free(idadeTemp);
    free(telefoneTemp);
}
 
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
        pbuffer = realloc(pbuffer, (*i)+(*num_pessoas + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));//(*n)+(*j)+

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
         ordenarPessoas(*num_pessoas, (char*)pbuffer, (int*)(pbuffer + sizeof(int)), (long int*)(pbuffer + sizeof(int) + sizeof(char) * 10));
        // Pergunta se o usuário quer continuar
        char resposta; //transformar em ponteiro
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