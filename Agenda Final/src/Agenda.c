/* implementar um programa em C para gerenciar uma agenda que inclui funcionalidades de adicionar, remover, buscar e listar pessoas. O programa deve seguir certas restrições:

Resumo das Restrições:
Uso Exclusivo de Ponteiros:

Nenhuma variável (exceto o pBuffer global) pode ser declarada no programa.
Todos os dados devem ser manipulados usando apenas ponteiros, inclusive contadores de loops e variáveis temporárias.
Uso de pBuffer:

Todas as informações (nome, idade, telefone, contadores, etc.) devem ser armazenadas dentro de um único buffer chamado pBuffer.
Deve-se usar um ponteiro para navegar e manipular os dados dentro desse buffer.
Proibição de struct Dentro de pBuffer:

Não é permitido usar struct diretamente no pBuffer.
Fila Ordenada (Heap):

Deve-se usar uma fila ordenada (heap) para manter as pessoas ordenadas alfabeticamente por nome ao inserir novas entradas.
Lista Duplamente Ligada:

A base de dados da agenda deve ser implementada como uma lista duplamente ligada.
Cada nó pode ser alocado separadamente usando malloc.
Limite Máximo de Pessoas:

A agenda deve armazenar no máximo 10 pessoas.
Dr. Memory e Vídeo:

O código deve ser testado com o Dr. Memory, uma ferramenta de análise de memória.
Um vídeo explicando o código e mostrando casos de teste é necessário.
Estrutura do Programa
Vou te mostrar uma estrutura básica do programa em C que segue as restrições mencionadas:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define QINT sizeof(int) * 4
#define INT sizeof(int)
#define TINT sizeof(int) * 3
#define NOME sizeof(char) * 10
#define TELEFONE sizeof(char) * 15
#define PESSOA sizeof(NOME+INT+TELEFONE)
void menu (void *pbuffer)
{  pbuffer = realloc(pbuffer, 4*INT);
    do
    {
        int *opcaomenu= (int *) (pbuffer);
        int *contpessoas=(int*)(pbuffer+TINT);
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
             { pessoatemp=()

                break;
             }
             case 2:
             {
               break;
               }
                 case 3:
             {
                pbuffer = realloc(pbuffer,QINT+NOME+*i*PESSOA);
                char *nomeTemp = (char *)(pbuffer + 2*INT);
                  printf("Entre com o nome a ser encontrado:\n");
            scanf("%s", nomeTemp);
                remover_pessoa(nomeTemp,pbuffer);
               break;
               }
                 case 4:
             {
               break;
               }
                 case 5:
             {
                return 0;
                free(pbuffer);
                break;
              
               }
                  default:
            printf("Opcao invalida!\n");
            return 1;
            break;
        }

         } while (*opcaomenu != 5);

}
void remover_pessoa(char* nome, void *pbuffer)
{

}
void adicionar_pessoa( char* nome, int* idade, char* telefone, void *pbuffer)
{ int *qtd_pessoas = (int *)(*pbuffer);
    if (qtd_pessoas>=10){
        printf("agenda lotada\n");
        return

    }


}
void heap(void *pbuffer)
{

}
void listar(void *pbuffer)
{int *i = (int* )((pbuffer+INT));
    
}
void listar_nome(void *pbuffer, char *nome)
{ 
    int *i = (int* )((pbuffer+INT));

    
}
void lista_duplamente_ligada(void *pbuffer){

}
void pbuffer (void *pbuffer){

}
int main()
{  void *pbuffer=(void*) malloc(sizeof(INT));
  menu(pbuffer);

  
    
}