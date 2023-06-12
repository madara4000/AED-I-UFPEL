#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*void lista(*void pessoas){
  int *node=(int*) malloc(sizeof(int)*2);
  int *node=pessoas;
}*/
//void ordena_pessoas(){}
int main() {

  void *pbuffer=NULL;
  pbuffer = (void*) malloc((sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3));
  char *resposta=(char*)(pbuffer);
  char *nomeTemp = (char*)(pbuffer+(sizeof(char)));
    int *idadeTemp = (int*)(pbuffer+(sizeof(char))+(sizeof(char)*10)) ;
    long int *telefoneTemp = (long int*)(pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))) ; 
          int *i= (int*)(pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int)));
   int *n = (int*)(pbuffer+(sizeof(char))+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)));
    int *num_pessoas =(int*)(pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*2)) ;
    *num_pessoas=0;
   
    while (1) {
        // Adiciona espaço para a próxima pessoa
        pbuffer = realloc(pbuffer,(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+(*num_pessoas + 1) * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));//(*nomeTemp)+(*idadeTemp)+(*telefoneTemp)+(*n)+(*j)+
 
 
    
        // Aponta para a região de memória correspondente à próxima pessoa
        char *nome = (char*) (pbuffer +(sizeof(char))+ (sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+*num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer +(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+ *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer +(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+ *num_pessoas * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));
    
   
        // Lê os dados da pessoa
        printf("Digite o nome da pessoa (max 10 caracteres): ");
        scanf("%10s", nome);

        printf("Digite a idade da pessoa: ");
        scanf("%d", idade);

        printf("Digite o telefone da pessoa: ");
        scanf("%ld", telefone);
       
     for (*n = 0; *n < *num_pessoas; (*n)++) {
        
            if (strcmp(nome + (*n) * 10 , nome + (*n+1) * 10 ) > 0) {
                // Troca os dados das pessoas
                strcpy(nomeTemp, nome + (*n+1) * 10 );
                strcpy(nome + (*n)* 10  , nome + (*n+1) * 10  );
                strcpy(nome + (*n+1) * 10  , nomeTemp);

                *idadeTemp = *(idade+*n);
               *(idade+*n)  = *(idade+*n+1);
              *(idade+*n+1) = *idadeTemp;

                *telefoneTemp = *(telefone+*n);
                *(telefone+*n)= *(telefone+*n+1);
                *(telefone+*n+1) = *telefoneTemp;
            }
        }
      
        (*num_pessoas)++;
    
    

        // Pergunta se o usuário quer continuar
  
        printf("Deseja adicionar outra pessoa? (S/N): ");
        scanf(" %c", resposta);
        if (*resposta == 'N' || *resposta == 'n') {
            break;
        }
    } 

    // Imprime os dados de todas as pessoas
    printf("Dados das pessoas:\n");
    for ( *i = 0; *i < *num_pessoas; (*i)++) {
        // Aponta para a região de memória correspondente à i-ésima pessoa
        char *nome = (char*) (pbuffer+(sizeof(char))+ (sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+*i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)));
        int *idade = (int*) (pbuffer+(sizeof(char)) +(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+ *i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10);
        long int *telefone = (long int*) (pbuffer+(sizeof(char))+(sizeof(char)*10)+(sizeof(int))+(sizeof(long int))+(sizeof(int)*3)+*i * (sizeof(char) * 10 + sizeof(int) + sizeof(long int)) + sizeof(char) * 10 + sizeof(int));

        // Imprime os dados da pessoa
        printf("Nome: %s, Idade: %d, Telefone: %ld\n", nome, *idade, *telefone);
    }

    // Libera a memória alocada
    free(pbuffer);

    return 0;
}