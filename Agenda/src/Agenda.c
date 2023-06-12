#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAX_PESSOAS 10

// Definição da estrutura de uma pessoa
typedef struct {
    char nome[10];
    int idade;
    char telefone[10];
} Pessoa;

// Definição da estrutura de um nodo da lista duplamente ligada
typedef struct Nodo {
    Pessoa* pessoa;
    struct Nodo* prox;
    struct Nodo* ant;
} Nodo;

// Variável global para armazenar as pessoas
Pessoa pessoas[MAX_PESSOAS];

// Protótipos das funções
void incluir(Pessoa* nova_pessoa);
void apagar(char* nome);
void buscar(char* nome);
void listar();
void limpar_buffer();
void exibir_menu();

// Variáveis globais para armazenar a lista duplamente ligada
Nodo* primeiro = NULL;
Nodo* ultimo = NULL;

int main() {
    void* pBuffer = malloc(sizeof(int*) * 3 + sizeof(Nodo*) * 2); // Aloca o buffer principal
    int* qtd_pessoas = (int*)pBuffer; // Ponteiro para a quantidade de pessoas
    int* tamanho_heap = (int*)(pBuffer + sizeof(int*)); // Ponteiro para o tamanho da heap
    int* heap_atual = (int*)(pBuffer + sizeof(int*) * 2); // Ponteiro para o índice atual da heap
    Nodo** lista_dupla = (Nodo**)(pBuffer + sizeof(int*) * 3); // Ponteiro para a lista duplamente ligada

    *qtd_pessoas = 0; // Inicializa a quantidade de pessoas
    *tamanho_heap = 0; // Inicializa o tamanho da heap
    *heap_atual = 0; // Inicializa o índice atual da heap
    *lista_dupla = NULL; // Inicializa a lista duplamente ligada

    

    int *opcao;
    opcao=(int*) malloc(sizeof(int));
    do {

        printf("Opcao: ");
        scanf("%d", opcao);
        limpar_buffer();

        switch(*opcao) {
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

       
    } while (*opcao != 5);

    // Libera a memória alocada para a lista duplamente ligada
    Nodo* nodo_atual = *lista_dupla;
    while (nodo_atual != NULL) {
        Nodo* nodo_anterior = nodo_atual->ant;
        free(nodo_atual->pessoa);
        free(nodo_atual);
        nodo_atual = nodo_anterior;
    }

    free(pBuffer); // Libera a memória alocada para o buffer principal

    return 0;
}






