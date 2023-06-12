
   
    /*

    for (*n = 0; *n < *um_pessoas; (*n)++) {
        for (*j = *n + 1; *j < *num_pessoas; (*j)++) {
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
}*/
 
#include <stdio.h>
#include <stdlib.h>
 
int main() {

  void *pbuffer=NULL;
  pbuffer = realloc(pbuffer,(sizeof(char*))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4));
  char *resposta=(char*)(pbuffer);
  char *nomeTemp = (char*)(pbuffer+(sizeof(char)));
    int *idadeTemp = (int*)(pbuffer+(sizeof(char))+sizeof(char)*10) ;
    long int *telefoneTemp = (long int*)(pbuffer+(sizeof(char))+sizeof(char)*10+sizeof(int)) ; 
          int *i= (int*)(pbuffer+(sizeof(char))+sizeof(char)*10)+(sizeof(int))+(sizeof(long int));
   int *n = (int*)(pbuffer+(sizeof(char))+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)));
    int *j = (int*)(pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*2));
    int *num_pessoas =(int*)(pbuffer+(sizeof(char))+sizeof(char)*10)+(sizeof(int))+(sizeof(long int)+(sizeof(int)*3)) ;
    *num_pessoas=0;
    while (1) {
        // Adiciona espaço para a próxima pessoa
        pbuffer = realloc(pbuffer,(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+(*num_pessoas + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));//(*nomeTemp)+(*idadeTemp)+(*telefoneTemp)+(*n)+(*j)+
 
 
    
        // Aponta para a região de memória correspondente à próxima pessoa
        char *nome = (char*) (pbuffer +(sizeof(char))+ (sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+*num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer +(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+ *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer +(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+ *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));
    
   
        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
        scanf(" %10s", nome);

        printf("Digite a idade da pessoa: ");
        scanf("%d", idade);

        printf("Digite o telefone da pessoa: ");
        scanf(" %ld", telefone);
       // getchar(); // Limpa o buffer de entrada para o próximo scanf()
       
        // Incrementa o contador de pessoas  
        for (*n = 0; *n < *num_pessoas; (*n)++) {
        for (*j = *n + 1; *j < *num_pessoas; (*j)++) {
            if (strcmp(nome + (*n) , nome + (*j) ) > 0) {
                // Troca os dados das pessoas
                strcpy(nomeTemp, nome + (*n) );
                strcpy(nome + (*n) , nome + (*j));
                strcpy(nome + (*j) , nomeTemp);

                *idadeTemp = *(idade+*n);
               *(idade+*n)  = *(idade+*j);
              *(idade+*j) = *idadeTemp;

                *telefoneTemp = *(telefone+*n);
                *(telefone+*n)= *(telefone+*j);
                *(telefone+*j) = *telefoneTemp;
            }
        }
    }
        (*num_pessoas)++;
      

    

        // Pergunta se o usuário quer continuar
  
        printf("Deseja adicionar outra pessoa? (S/N): ");
        scanf(" %c", resposta);
        if (*resposta == 'N' || *resposta == 'n') {
            break;
        }
    }  /* fgets(resposta, 3, stdin);
        //scanf(" %c", resposta);
        if (strcmp (resposta == 'N') ||strcmp( resposta == 'n')) {
            break;
        }
    }*/

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for ( *i = 0; *i < *num_pessoas; (*i)++) {
        // Aponta para a região de memória correspondente à i-ésima pessoa
        char *nome = (char*) (pbuffer+(sizeof(char))+ (sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+*i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer+(sizeof(char)) +(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+ *i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*4)+*i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(pbuffer);

    return 0;
}