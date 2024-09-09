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
void remover_pessoa(char* nome)
{

}
void adicionar_pessoa( char* nome, int* idade, char* telefone)
{

}
void heap()
{

}
void listar(void *pbuffer)
{
    
}
void listar_nome(void *pbuffer, char *nome)
{
    
}
void lista_duplamente_ligada(void *pbuffer){

}
void pbuffer (void *pbuffer){

}
int main()
{  void *pbuffer=(void*) malloc(sizeof())
    
}