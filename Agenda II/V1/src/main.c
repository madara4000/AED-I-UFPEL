#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 10

void adicionaPessoa(void *pBuffer, int *opcao) {
   // char (*pessoas)[MAX_NOME] = *(char (*)[MAX_NOME] **) (pBuffer + sizeof(int));
   char (*pessoas)[MAX_NOME] = (char (*)[MAX_NOME]) (pBuffer + sizeof(int));
    int *idades = (int *) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10);
    char **telefones = (char **) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10 + sizeof(int) * 10);
    int n = *(int *) pBuffer;
    printf("Digite o nome da pessoa: ");
    scanf("%s", pessoas[n]);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &idades[n]);
    printf("Digite o telefone da pessoa: ");
    scanf("%s", telefones[n]);
    *(int *) pBuffer = n + 1;
    *opcao = -1; // Reinicia a opção para obrigar a entrada de uma nova opção na função "main"
}

void listaPessoas(void *pBuffer, int *opcao) {
char (*pessoas)[MAX_NOME] = *((char (*)[MAX_NOME] *) (pBuffer + sizeof(int)));
    int *idades = (int *) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10);
    char (*telefones)[20] = *(char (*)[20] **) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10 + sizeof(int) * 10);
    int n = *(int *) pBuffer;
    if (n == 0) {
        printf("Nenhuma pessoa adicionada.\n");
    } else {
        printf("Pessoas adicionadas:\n");
        for (int i = 0; i < n; i++) {
            printf("%d: %s (%d anos), telefone: %s\n", i + 1, pessoas[i], idades[i], telefones[i]);
        }
    }
    *opcao = -1; // Reinicia a opção para obrigar a entrada de uma nova opção na função "main"
}

int main() {
    void *pBuffer = malloc(sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10 + sizeof(int) * 10 + sizeof(char (*)[20]) * 10);
    if (!pBuffer) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    *(int *) pBuffer = 0;
    *(char (*)[MAX_NOME] **) (pBuffer + sizeof(int)) = (char (*)[MAX_NOME] *) (pBuffer + sizeof(int) + sizeof(int) * 10);
    *(char (*)[20] **) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10 + sizeof(int) * 10) = (char (*)[20] *) (pBuffer + sizeof(int) + sizeof(char (*)[MAX_NOME]) * 10 + sizeof(int) * 10 +sizeof(char (*)[20]) * 10);
int *opcao = (int *) malloc(sizeof(int));
if (!opcao) {
printf("Erro ao alocar memória.\n");
free(pBuffer);
return 1;
}
*opcao = -1; // Inicializa a opção para obrigar a entrada de uma nova opção na primeira iteração do loop
while (*opcao != 0) {
printf("Selecione uma opcao:\n");
printf("1 - Adicionar pessoa\n");
printf("2 - Listar pessoas\n");
printf("0 - Sair\n");
scanf("%d", opcao);
switch (*opcao) {
case 1:
adicionaPessoa(pBuffer, opcao);
break;
case 2:
listaPessoas(pBuffer, opcao);
break;
case 0:
break;
default:
printf("Opcao invalida. Selecione outra opcao.\n");
break;
}
}
free(opcao);
free(pBuffer);
return 0;
} 