#include <stdio.h>

void soma1(int *ponteiro);
void imprimeVetor(int *vetor, int tamanho);

int main() {
    int a = 10;
    int *ponteiro = &a;
    int vetor[5] = {1, 2, 3, 4, 5};
    int *ponteiroVetor = vetor;

    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", &a);
    printf("Valor do ponteiro: %p\n", ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);
    printf("\n");

    soma1(ponteiro);

    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", &a);
    printf("Valor do ponteiro: %p\n", ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);
    printf("\n");

    printf("Valores do vetor: ");
    imprimeVetor(ponteiroVetor, 5);
    printf("\n");

    ponteiroVetor++;

    printf("Valores do vetor: ");
    imprimeVetor(ponteiroVetor, 4);
    printf("\n");

    return 0;
}

void soma1(int *ponteiro) {
    (*ponteiro)++;
}

void imprimeVetor(int *vetor, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }
}