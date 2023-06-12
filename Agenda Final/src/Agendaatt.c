#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define QINT sizeof(int) * 6
#define INT sizeof(int)
#define TINT sizeof(int) * 3
#define NOME sizeof(char) * 10
#define DINT sizeof(int) * 2
#define QUINT sizeof(int) * 4
void remover_elemento(char *pbuffer, int *num_nodos) {
    if (*num_nodos == 0) {
        printf("Lista vazia\n");
        return ;
    } 
  
  int *i=(int*) (pbuffer + QUINT) ;
    int *indice=(int*) (pbuffer + QUINT+INT);
    
    char *nomeTemp = (char *)(pbuffer + QINT);
    printf("Entre com o nome a ser removido:\n");
    scanf("%s", nomeTemp);

    
    *indice = -1; // inicializar o índice do elemento a ser removido com -1
    for ( *i = 0; *i < *num_nodos; (*i)++) {
        char *nomep = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));

        if (strcmp(nomeTemp, nomep) == 0) {
            *indice = *i; // atualizar o índice do elemento a ser removido
            break;
        }
    }

    if (*indice != -1) {
        // deslocar todos os elementos subsequentes do array uma posição para trás
        for ( *i = *indice + 1; *i < *num_nodos; (*i)++) {
            char *nomeant = (char *)(pbuffer + QINT + NOME + INT + INT + (*i)-1 * (NOME + INT + INT));
            char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));
            int *idadeant = (int *)(pbuffer + QINT + NOME + INT + INT + (*i)-1 * (NOME + INT + INT) + NOME);
            int *idade= (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
            int *telefoneant = (int *)(pbuffer + QINT + NOME + INT + INT + (*i)-1 * (NOME + INT + INT) + NOME + INT);
            int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);
            memcpy(nomeant, nome, NOME);
            *idadeant = *idade;
            *telefoneant = *telefone;
        }
        (*num_nodos)--;  // diminuir o número de elementos em um
        pbuffer = realloc(pbuffer, QINT + NOME + INT + INT + (*num_nodos) * (NOME + INT + INT));
    } else {
        printf("Elemento não encontrado\n");
    }
}



int main()
{
    void *pbuffer = NULL;                                        // inicia pbuffer
    pbuffer = (void *)malloc(QINT + NOME + INT + INT); // malloc do tamanho ja adicionando os contadores que serão utilizados no programa
    if (pbuffer == NULL)
    {

        printf("Nao tem memoria disponivel para alocar\n");
        return 1;
    }
    int *opcaomenu = (int *)(pbuffer);
    int *i = (int *)(pbuffer + INT);
    int *n = (int *)(pbuffer + INT + INT);
    int *num_nodos = (int *)(pbuffer + TINT);
   
    *num_nodos = 0;

    do
    {
        printf("\n\tMENU\n");
        printf("\n1.Incluir Pessoas:\n ");
        printf("\n2.Buscar Pessoas:\n ");
        printf("\n3.Remover Pessoas:\n");
        printf("\n4.Listar Pessoas:\n ");
        printf("\n5.Sair:\n");
        printf("Escolha a Opcao: ");
        scanf("%d", opcaomenu);
        switch (*opcaomenu)
        {
        case 1:
        {

            pbuffer = realloc(pbuffer, QINT  + NOME + INT + INT + (*num_nodos) + 1 * (NOME + INT + INT));
            if (pbuffer == NULL)
            {
                printf("Nao tem memoria disponivel para alocar!\n");
                return 1;
            }
            char *nomeTemp = (char *)(pbuffer + QINT );
            int *idadeTemp = (int *)(pbuffer + QINT   + NOME);
            int *telefoneTemp = (int *)(pbuffer + QINT + NOME + INT);

            char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) * (NOME + INT + INT)); // percorre o nome de pessoa
            int *idade = (int *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) * (NOME + INT + INT) + NOME);
            int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + (*num_nodos) * (NOME + INT + INT) + NOME + INT);

            printf("Entre com o nome:\n");
            scanf("%s", nome);
            printf("Entre com a idade:\n");
            scanf("%d", idade);
            printf("Entre com o telefone:\n");
            scanf("%d", telefone);
            (*num_nodos)++;
            if (*num_nodos != 0)
            {

             
                for (*i = 0; *i < *num_nodos; (*i)++)
                {
                    for (*n = (*i) + 1; *n < *num_nodos; (*n)++)
                    {

                        // Troca os dados das pessoas
                        char *nome = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT)); // percorre o nome de pessoa
                        int *idade = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
                        int *telefone = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);
                        char *nomeprox = (char *)(pbuffer + QINT + NOME + INT + INT + (*n) * (NOME + INT + INT));
                        int *idadeprox = (int *)(pbuffer + QINT + NOME + INT + INT + (*n) * (NOME + INT + INT) + NOME);
                        int *telefoneprox = (int *)(pbuffer + QINT + NOME + INT + INT + (*n) * (NOME + INT + INT) + NOME + INT);

                        if (strcmp(nome, nomeprox) > 0)
                        {
                            strcpy(nomeTemp, nome);
                            strcpy(nome, nomeprox);
                            strcpy(nomeprox, nomeTemp);

                            *idadeTemp = *idade;

                            *idade = *idadeprox;
                            *idadeprox = *idadeTemp;

                            *telefoneTemp = *telefone;
                            *telefone = *telefoneprox;
                            *telefoneprox = *telefoneTemp;
                        }
                    }
                }
            }
            break;
        }

        case 2:
        {
            if (*num_nodos == 0)
            {
                printf("Lista vazia!\n");
                return 0;
            }

            char *nomeTemp = (char *)(pbuffer + QINT);
            printf("Entre com o nome a ser encontrado:\n");
            scanf("%s", nomeTemp);
            for (*i = 1; *i < *num_nodos; (i)++)
            {
                char *nomeb = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT));

                if (strcmp(nomeb, nomeTemp) == 0)
                {
                    printf("Nome: %s, Idade: %d, Telefone: %d\n", nomeb, *(int *)(nomeb + NOME), *(int *)(nomeb + NOME + INT));
                    break;
                }
            }

            break;
        }
        case 3:
        {
            remover_elemento((char *) pbuffer,num_nodos);

            break;
        }
        case 4:
        {
            printf("Dados das pessoas:\n");
            for (*i = 0; *i < *num_nodos; (*i)++)
            {
                // Aponta para a região de memória correspondente à i-ésima pessoa
                char *nomel = (char *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT)); // percorre o nome de pessoa
                int *idadel = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME);
                int *telefonel = (int *)(pbuffer + QINT + NOME + INT + INT + *i * (NOME + INT + INT) + NOME + INT);

                // Imprime os dados da pessoa
                printf("Nome: %s, Idade: %d, Telefone: %d\n", nomel, *idadel, *telefonel);
            }

            break;
        }
        case 5:

            return 0;
            free(pbuffer);
            break;

        default:
            printf("Opcao invalida!\n");
            return 1;
            break;
        }
    } while (*opcaomenu != 5);
}