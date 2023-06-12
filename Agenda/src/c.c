#include <stdio.h>
#include <stdlib.h>

int main() {
    void *pbuffer = malloc(sizeof(char) * 50 + sizeof(int) + sizeof(char) * 20 + sizeof(void*) * 2);
    // Armazena os dados da primeira pessoa
    char *nome = (char*) pbuffer;
    int *idade = (int*) (pbuffer + sizeof(char) * 50);
    char *telefone = (char*) (pbuffer + sizeof(char) * 50 + sizeof(int));
    void **pessoas = (void**) (pbuffer + sizeof(char) * 50 + sizeof(int) + sizeof(char) * 20);

    pessoas[0] = NULL; // O endereço da pessoa anterior é NULL para a primeira pessoa
    pessoas[1] = NULL; // O endereço da pessoa seguinte também é NULL para a primeira pessoa

    printf("Informe o nome da primeira pessoa: ");
    scanf("%s", nome);
    printf("Informe a idade da primeira pessoa: ");
    scanf("%d", idade);
    printf("Informe o telefone da primeira pessoa: ");
    scanf("%s", telefone);

    // Cria uma nova pessoa e a insere no final da lista
    void *nova_pessoa = malloc(sizeof(char) * 50 + sizeof(int) + sizeof(char) * 20 + sizeof(void*) * 2);
    char *nome_nova_pessoa = (char*) nova_pessoa;
    int *idade_nova_pessoa = (int*) (nova_pessoa + sizeof(char) * 50);
    char *telefone_nova_pessoa = (char*) (nova_pessoa + sizeof(char) * 50 + sizeof(int));
    void **pessoas_nova_pessoa = (void**) (nova_pessoa + sizeof(char) * 50 + sizeof(int) + sizeof(char) * 20);

    pessoas_nova_pessoa[0] = pbuffer; // A nova pessoa aponta para a pessoa anterior
    pessoas_nova_pessoa[1] = NULL; // A nova pessoa não tem ninguém seguinte

    printf("\nInforme o nome da nova pessoa: ");
    scanf("%s", nome_nova_pessoa);
    printf("Informe a idade da nova pessoa: ");
    scanf("%d", idade_nova_pessoa);
    printf("Informe o telefone da nova pessoa: ");
    scanf("%s", telefone_nova_pessoa);

    // Atualiza o endereço da próxima pessoa da primeira pessoa
    pessoas[1] = nova_pessoa;

    // Percorre a lista e imprime as informações de cada pessoa
    void *pessoa_atual = pbuffer;
    while (pessoa_atual != NULL) {
        char *nome_pessoa_atual = (char*) pessoa_atual;
        int *idade_pessoa_atual = (int*) (pessoa_atual + sizeof(char) * 50);
        char *telefone_pessoa_atual = (char*) (pessoa_atual + sizeof(char) * 50 + sizeof(int));
        void **pessoas_pessoa_atual = (void**) (pessoa_atual + sizeof(char) * 50 + sizeof(int) + sizeof(char) * 20);

        printf("\nNome: %s\n", nome_pessoa_atual);
        printf("\nidade: %d \n", idade_pessoa_atual);
        printf("\ntelefone: %s \n",telefone_pessoa_atual);
                                 }
    free(pbuffer);
    free(nova_pessoa);
     return 0;}