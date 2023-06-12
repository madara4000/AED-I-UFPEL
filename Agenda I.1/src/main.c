#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 10 //tamanho máximo do nome

typedef struct pessoa //struct que representa uma pessoa na agenda
{
    char nome[TAM_NOME]; //nome da pessoa
    int idade; //idade da pessoa
   int telefone; //telefone da pessoa
} Pessoa;

void *pBuffer; //ponteiro void que armazena os dados da agenda
int *qtd; //ponteiro para a quantidade de pessoas na agenda
int *opcao; //ponteiro para a opção do menu
Pessoa *p; //ponteiro auxiliar para manipular as pessoas

void adicionar(); //função que adiciona uma pessoa na agenda
void remover(); //função que remove uma pessoa da agenda
void buscar(); //função que busca uma pessoa na agenda pelo nome
void listar(); //função que lista todas as pessoas da agenda

int main()
{
    pBuffer = malloc(sizeof(int) + sizeof(int)); //aloca espaço inicial para dois inteiros: qtd e opcao
    if (pBuffer == NULL) //se não conseguiu alocar memória
    {
        printf("Erro de alocação.\n");
        exit(1);
    }
    qtd = pBuffer; //qtd aponta para o primeiro inteiro do pBuffer
    opcao = pBuffer + sizeof(int); //opcao aponta para o segundo inteiro do pBuffer

    *qtd = 0; //inicializa a quantidade de pessoas com zero

    do {
        printf("Menu:\n");
        printf("1) Adicionar\n");
        printf("2) Remover\n");
        printf("3) Buscar\n");
        printf("4) Listar\n");
        printf("5) Sair\n");
        printf("Selecione uma opcao acima:\n");
        scanf("%d", opcao);

        switch(*opcao)
        {
            case 1:
                adicionar();
                break;
            case 2:
                remover();
                break;
            case 3:
                buscar();
                break;
            case 4:
                listar();
                break;
            case 5:
                break;
            default:
                printf("Opção inválida.\n");

        }

    } while (*opcao != 5);

    free(pBuffer); //libera a memória alocada pelo pBuffer

    return 0;
}

void adicionar()
{
    Pessoa nova; //variável temporária para armazenar os dados da nova pessoa

    printf("Digite o nome: ");
    scanf("%s", nova.nome);
    
     if (strlen(nova.nome) > TAM_NOME - 1) { 
         printf ("Nome muito grande!\n"); 
         return ; 
     }

    printf("Digite a idade: ");
    scanf("%d", &nova.idade);

    printf("Digite o telefone: ");
    scanf("%d", &nova.telefone);

    pBuffer = realloc(pBuffer, sizeof(int) + sizeof(int) + (*qtd + 1) * sizeof(Pessoa)); //realoca o espaço do pBuffer para caber mais uma pessoa
    if (pBuffer == NULL) //se não conseguiu realocar memória
    {
        printf("Erro de alocação.\n");
        exit(1);
    }
    
    qtd = pBuffer; //qtd aponta para o primeiro inteiro do pBuffer
    opcao = pBuffer + sizeof(int); //opcao aponta para o segundo inteiro do pBuffer
    p = pBuffer + 2 * sizeof(int); //p aponta para a primeira pessoa do pBuffer

    p[*qtd] = nova; //copia os dados da variável nova para a última posição do pBuffer

    (*qtd)++; //incrementa a quantidade de pessoas
}
void remover()
{
    char nome[TAM_NOME]; //variável para armazenar o nome da pessoa a ser removida
    int i; //variável para controlar o laço
    int achou = 0; //variável para indicar se achou ou não a pessoa

    printf("Digite o nome da pessoa que deseja remover: ");
    scanf("%s", nome);

    for (i = 0; i < *qtd; i++) //percorre o pBuffer
    {
        if (strcmp(p[i].nome, nome) == 0) //se encontrou a pessoa com o nome digitado
        {
            p[i] = p[*qtd - 1]; //copia os dados da última pessoa para a posição da pessoa removida
            achou = 1; //marca que achou a pessoa
            break; //sai do laço
        }
    }

    if (achou) //se achou a pessoa
    {
        pBuffer = realloc(pBuffer, sizeof(int) + sizeof(int) + (*qtd - 1) * sizeof(Pessoa)); //realoca o espaço do pBuffer para uma pessoa a menos
        if (pBuffer == NULL && *qtd > 1) //se não conseguiu realocar memória e ainda tem pessoas na agenda
        {
            printf("Erro de alocação.\n");
            exit(1);
        }
        
        qtd = pBuffer; //qtd aponta para o primeiro inteiro do pBuffer
        opcao = pBuffer + sizeof(int); //opcao aponta para o segundo inteiro do pBuffer
        p = pBuffer + 2 * sizeof(int); //p aponta para a primeira pessoa do pBuffer

        (*qtd)--; //decrementa a quantidade de pessoas

        printf("Pessoa removida com sucesso.\n");
    }
    else //se não achou a pessoa
    {
        printf("Pessoa não encontrada.\n");
    }
}

void buscar()
{
    char nome[TAM_NOME]; //variável para armazenar o nome da pessoa a ser buscada
    int i; //variável para controlar o laço

    printf("Digite o nome da pessoa que deseja buscar: ");
    scanf("%s", nome);

    for (i = 0; i < *qtd; i++) //percorre o pBuffer
    {
        if (strcmp(p[i].nome, nome) == 0) //se encontrou a pessoa com o nome digitado
        {
            printf("Nome: %s\n", p[i].nome); //mostra os dados da pessoa encontrada
            printf("Idade: %d\n", p[i].idade);
            printf("Telefone: %d\n", p[i].telefone);
            return; //encerra a função 
        }
    }

    printf("Pessoa não encontrada.\n"); //mostra uma mensagem caso a pessoa não seja encontrada
}
       
       
       void listar()
{
    int i; //variável para controlar o laço

    if (*qtd == 0) //se não há pessoas na agenda
    {
        printf("Agenda vazia.\n");
        return; //encerra a função
    }

    for (i = 0; i < *qtd; i++) //percorre o pBuffer
    {
        printf("Nome: %s\n", p[i].nome); //mostra os dados de cada pessoa
        printf("Idade: %d\n", p[i].idade);
        printf("Telefone: %d\n", p[i].telefone);
        printf("\n");
    }
}
       
       
       
       
       
      
        
        

        

        

        

        

        
