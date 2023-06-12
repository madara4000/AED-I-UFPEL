#include <stdio.h>
#include <stdlib.h>

int main() {
    void* buffer = NULL;
    int* tamanho_lista = NULL;
    int** primeiro = NULL;
    int** ultimo = NULL;
    int** atual = NULL;

    // aloca o buffer e inicializa as variáveis ponteiro
    buffer = malloc(sizeof(int) * 3);
    tamanho_lista = (int*)buffer;
    primeiro = (int**)(buffer + sizeof(int));
    ultimo = (int**)(buffer + sizeof(int) * 2);
    *primeiro = NULL;
    *ultimo = NULL;

    // operações com a lista
    int *opcao =(int*) malloc(sizeof(int));
   *opcao=0;
    while (*opcao != 4) {
        printf("\nMENU\n");
        printf("1. Adicionar elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", opcao);

        switch (*opcao) {
            case 1:
                // aloca memória para o novo elemento
                int *novo_elemento = (int*) malloc(sizeof(int));
                printf("Digite o valor: ");
                scanf("%d", novo_elemento);
                novo_elemento[1] = (int)NULL;

                if (*tamanho_lista == 0) {
                    // insere o primeiro elemento da lista
                    *primeiro = novo_elemento;
                    *ultimo = novo_elemento;
                } else {
                    // insere o novo elemento no final da lista
                    (*ultimo)[1] = (int)novo_elemento;
                    *ultimo = novo_elemento;
                }

                (*tamanho_lista)++;
                break;

            case 2:
                if (*tamanho_lista == 0) {
                    printf("Lista vazia\n");
                } else {
                    // remove o último elemento da lista
                    if (*primeiro == *ultimo) {
                        *primeiro = NULL;
                        *ultimo = NULL;
                    } else {
                        *atual = *primeiro;
                        while ((*atual)[1] != (int)*ultimo) {
                            *atual = (int*)(*atual)[1];
                        }
                        *ultimo = *atual;
                        (*atual)[1] = (int)NULL;
                    }
                    (*tamanho_lista)--;
                    printf("Elemento removido\n");
                }
                break;

            case 3:
                if (*tamanho_lista == 0) {
                    printf("Lista vazia\n");
                } else {
                    // imprime os elementos da lista
                    printf("Elementos da lista:\n");
                    *atual = *primeiro;
                    while (*atual != NULL) {
                        printf("%d ", **atual);
                        *atual = (int*)(*atual)[1];
                    }
                    printf("\n");
                }   
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }
    }

    // libera a memória alocada
    *atual = *primeiro;
    while (*atual != NULL) {
        int* proximo = (int*)(*atual)[1];
        free(*atual);
        *atual = proximo;
    }
    free(buffer);

    return 0;
}


case 2:
        {
            if (*num_nodos == 0)
            {
                printf("Lista vazia!\n");
                return 0;
            }
            
            char *nomeTemp = (char *)(pbuffer + QINT);
            printf("Entre com o nome a ser removido:\n");
            scanf("%s", nomeTemp);
            *n=-1;//equivalente a posição a remover
            for (*i = 0; *i < *num_nodos; (*i)++)
            {
                char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));
                int *idade = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
                int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);

                if (strcmp(nomeTemp, nome) == 0)
                {
                   *n=i;
                   break;
                }
            
            }
             if (*n != -1) {
        
        // deslocar todos os elementos subsequentes do array uma posição para trás
        for (int *i = (*n)+ 1; *i < *num_nodos; (*i)++) {
             char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));
                int *idade = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
                int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);
                char *nomeant = (char *)(pbuffer + QINT + NOME + INT + INT );
                int *idadeant = (int *)(pbuffer + QINT + NOME + INT + INT+ NOME);
                int *telefoneant = (int *)(pbuffer + QINT + NOME + INT + INT +  NOME + INT);
            *nomeant = *nome;
            *idadeant = *idade;
            *telefoneant = *telefone ;
        }
        num_nodos--;  // diminuir o tamanho do array em um
        pbuffer = realloc(pbuffer, QINT + NOME + INT + INT + (*num_nodos)  * (NOME + INT + INT));
    }

            break;
        }




           // char *nodoanteriornome=
    // char *nodoposteriornome=
    // int *nodoanterioridade=
    // int*nodoposterioridade=
    // int *nodoanteriortelefone=
    // int*nodoposteriortelefone=
}
// int *num_nodosprox=(int*) (pbuffer,(sizeof(int)*4) + (*num_nodos)+1*(sizeof(char)*10+sizeof(int)+sizeof(int))); //proxima pessoa na lista
/*for (*i = 0; *i < *num_nodos; (*i)++) {
for (*n = (*i)+1; *n < *num_nodos; (*n)++) {
   if (strcmp(nome + (*i) , nome + (*n) ) > 0) {
       // Troca os dados das pessoas
       strcpy(nomeTemp, nome + (*i) );
       strcpy(nome + (*i) , nome + (*n));
       strcpy(nome + (*n) , nomeTemp);

       *idadeTemp = *(idade+*i);

      *(idade+*i)  = *(idade+*n);
     *(idade+*n) = *idadeTemp;

       *telefoneTemp = *(telefone+*i);
       *(telefone+*i)= *(telefone+*n);
       *(telefone+*n) = *telefoneTemp;
   }
} //int *num_nodosprox=(int*) (pbuffer,(sizeof(int)*4) + (*num_nodos)+1*(sizeof(char)*10+sizeof(int)+sizeof(int))); //proxima pessoa na lista
/*for (*i = 0; *i < *num_nodos; (*i)++) {
for (*n = (*i)+1; *n < *num_nodos; (*n)++) {
   if (strcmp(nome + (*i) , nome + (*n) ) > 0) {
       // Troca os dados das pessoas
       strcpy(nomeTemp, nome + (*i) );
       strcpy(nome + (*i) , nome + (*n));
       strcpy(nome + (*n) , nomeTemp);

       *idadeTemp = *(idade+*i);

      *(idade+*i)  = *(idade+*n);
     *(idade+*n) = *idadeTemp;

       *telefoneTemp = *(telefone+*i);
       *(telefone+*i)= *(telefone+*n);
       *(telefone+*n) = *telefoneTemp;
   }
}
                                        }*/
/*void lista(void **pp,char *c,int *i ,int *t,int *num){
char *nodonomefirts;
int *nodoidadefirst;
int *nodotelefonefirst;
char *nodonomenext;
int *nodoidadenext;
int *nodotelefonenext;

// Verifica se o ponteiro pp é válido
if (pp == NULL) {
printf("Erro: ponteiro nulo\n");
return;
}

// Realoca o buffer de memória e verifica se foi bem-sucedido
void *p = realloc(*pp, (2*(sizeof(char)*10+sizeof(int)+sizeof(int))) +
                     (sizeof(int)*3) +
                     *num*(sizeof(char)*10+sizeof(int)+sizeof(int)));
if (p == NULL) {
printf("Erro: realocação de memória falhou\n");
return;
}

*pp = p;

// Se num for zero, adiciona o primeiro nó na lista
if (*num == 0) {
nodonomefirts = c;
nodoidadefirst = i;
nodotelefonefirst = t;
// ...
}
// Se num for diferente de zero, adiciona um nó na lista
else {
nodonomenext = c;
nodoidadenext = i;
nodotelefonenext = t;
// ...
}

(*num)++;
}
*/
  /*char *nomeTemp = (char *)(pbuffer + QINT);
            printf("Entre com o nome a ser removido:\n");
            scanf("%s", nomeTemp);
          *n=0;
            for (*i = 0; i < *num_nodos; i++)

            {   char *nomeini = (char *)(pbuffer + QINT + NOME + INT + INT );
                int *idadeini = (int *)(pbuffer + QINT + NOME + INT + INT+ NOME);
                int *telefoneini = (int *)(pbuffer + QINT + NOME + INT + INT +  NOME + INT);
                char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));
                int *idade = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
                int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);
                char *nomeprox = (char *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) + 1 * (NOME + INT + INT));
                int *idadeprox = (int *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) + 1 * (NOME + INT + INT) + NOME);
                int *telefoneprox = (int *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) + 1 * (NOME + INT + INT) + NOME + INT);
                if (strcmp(nomeTemp, nome) == 0)
                {

                }
                
            }*/