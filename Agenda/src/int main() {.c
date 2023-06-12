#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_AGENDA 100

int main() {
    // Aloca um buffer dinâmico com espaço para armazenar informações de até 100 pessoas
    char *pbuffer = (char *)malloc(MAX_AGENDA * (MAX_NOME + sizeof(int) * 2));
    if (pbuffer == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    int num_pessoas = 0;

    // Insere algumas pessoas na agenda
    char nome[MAX_NOME];
    int idade, telefone;

    strcpy(nome, "João");
    idade = 30;
    telefone = 123456789;
    char *p = pbuffer;
    memcpy(p, nome, strlen(nome) + 1);
    p += MAX_NOME;
    memcpy(p, &idade, sizeof(int));
    p += sizeof(int);
    memcpy(p, &telefone, sizeof(int));
    p += sizeof(int);
    num_pessoas++;

    strcpy(nome, "Maria");
    idade = 25;
    telefone = 987654321;
    p = pbuffer + num_pessoas * (MAX_NOME + sizeof(int) * 2);
    memcpy(p, nome, strlen(nome) + 1);
    p += MAX_NOME;
    memcpy(p, &idade, sizeof(int));
    p += sizeof(int);
    memcpy(p, &telefone, sizeof(int));
    p += sizeof(int);
    num_pessoas++;

    // Procura uma pessoa pelo nome
    printf("Entre com o nome da pessoa a ser procurada:\n");
    scanf("%s", nome);

    for (int i = 0; i < num_pessoas; i++) {
        p = pbuffer + i * (MAX_NOME + sizeof(int) * 2);
        if (strcmp(p, nome) == 0) {
            printf("Nome: %s, Idade: %d, Telefone: %d\n", p, *(int *)(p + MAX_NOME), *(int *)(p + MAX_NOME + sizeof(int)));
            break;
        }
    }

    free(pbuffer);

    return 0;
}