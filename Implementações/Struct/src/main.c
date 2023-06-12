
/*Lista
#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

typedef struct No No;

No* criarNo(int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

void imprimirLista(No* inicio) {
    No* atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void inserirNoInicio(No** inicio, int valor) {
    No* novoNo = criarNo(valor);
    novoNo->prox = *inicio;
    *inicio = novoNo;
}

void inserirNoFim(No** inicio, int valor) {
    No* novoNo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novoNo;
    } else {
        No* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoNo;
    }
}

void removerNo(No** inicio, int valor) {
    No* anterior = NULL;
    No* atual = *inicio;
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista\n", valor);
    } else if (anterior == NULL) {
        *inicio = atual->prox;
        free(atual);
    } else {
        anterior->prox = atual->prox;
        free(atual);
    }
}

int main() {
    No* lista = NULL;

    inserirNoInicio(&lista, 10);
    inserirNoInicio(&lista, 20);
    inserirNoFim(&lista, 30);
    imprimirLista(lista);

    removerNo(&lista, 20);
    imprimirLista(lista);

    removerNo(&lista, 40);

    return 0;
}*/
/*Pilha
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100 // tamanho máximo da pilha

typedef struct {
    int topo; // índice do topo da pilha
    int elementos[TAM_MAX]; // array para armazenar os elementos da pilha
} Pilha;

// Função para inicializar uma pilha vazia
void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaEstaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int pilhaEstaCheia(Pilha* pilha) {
    return (pilha->topo == TAM_MAX - 1);
}

// Função para adicionar um elemento no topo da pilha
void empilhar(Pilha* pilha, int elemento) {
    if (pilhaEstaCheia(pilha)) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = elemento;
}

// Função para remover um elemento do topo da pilha
int desempilhar(Pilha* pilha) {
    int elemento;
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    }
    elemento = pilha->elementos[pilha->topo];
    pilha->topo--;
    return elemento;
}

// Função para imprimir os elementos da pilha
void imprimirPilha(Pilha* pilha) {
    int i;
    printf("Pilha: ");
    for (i = pilha->topo; i >= 0; i--) {
        printf("%d ", pilha->elementos[i]);
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);
   pilhaEstaVazia(&minhaPilha);
    empilhar(&minhaPilha, 10);
    empilhar(&minhaPilha, 20);
    empilhar(&minhaPilha, 30);
 
    imprimirPilha(&minhaPilha);

    printf("Elemento removido: %d\n", desempilhar(&minhaPilha));
    printf("Elemento removido: %d\n", desempilhar(&minhaPilha));

    imprimirPilha(&minhaPilha);

    return 0;
}*/
/*

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100 // tamanho máximo da pilha
typedef struct{
    char nome[100];
    int idade;
    int telefone;
} Pessoa;
typedef struct {
    int topo; // índice do topo da pilha
    Pessoa Pessoas[TAM_MAX]; // array para armazenar os elementos da pilha
} Pilha;

// Função para inicializar uma pilha vazia
void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaEstaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int pilhaEstaCheia(Pilha* pilha) {
    return (pilha->topo == TAM_MAX - 1);
}

// Função para adicionar um elemento no topo da pilha
void empilhar(Pilha* pilha, Pessoa Pessoas) {
    if (pilhaEstaCheia(pilha)) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    pilha->topo++;
    pilha->Pessoas[pilha->topo] = Pessoas;
}

// Função para remover um elemento do topo da pilha
int desempilhar(Pilha* pilha) {
    int elemento;
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        return -1;
    }
    elemento = pilha->Pessoas[pilha->topo];
    pilha->topo--;
    return elemento;
}

// Função para imprimir os elementos da pilha
void imprimirPilha(Pilha* pilha) {
    int i;
    printf("Pilha: ");
    for (i = pilha->topo; i >= 0; i--) {
        printf("%d ", pilha->Pessoas[i]);
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
 Pessoa p;
 p.idade=40;
 p.nome="toto";
 p.telefone=55555555;
 Pessoa d;
 d.idade=41;
 d.nome="tote";
 d.telefone=55555556;
    inicializarPilha(&minhaPilha);
   pilhaEstaVazia(&minhaPilha);
    empilhar(&minhaPilha, Pessoa.p);
    empilhar(&minhaPilha, Pessoa.d);
    
 
    imprimirPilha(&minhaPilha);

    printf("Elemento removido: %d\n", desempilhar(&minhaPilha));
    printf("Elemento removido: %d\n", desempilhar(&minhaPilha));

    imprimirPilha(&minhaPilha);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100 // tamanho máximo da pilha

typedef struct {
    char nome[100];
    int idade;
    int telefone;
} Pessoa;

typedef struct {
    int topo; // índice do topo da pilha
    Pessoa Pessoas[TAM_MAX]; // array para armazenar os elementos da pilha
} Pilha;

// Função para inicializar uma pilha vazia
void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaEstaVazia(Pilha* pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int pilhaEstaCheia(Pilha* pilha) {
    return (pilha->topo == TAM_MAX - 1);
}

// Função para adicionar um elemento no topo da pilha
void empilhar(Pilha* pilha, Pessoa pessoa) {
    if (pilhaEstaCheia(pilha)) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    pilha->topo++;
    pilha->Pessoas[pilha->topo] = pessoa;
}

// Função para remover um elemento do topo da pilha
Pessoa desempilhar(Pilha* pilha) {
    Pessoa pessoa;
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: pilha vazia.\n");
        pessoa.idade = -1;
        return pessoa;
    }
    pessoa = pilha->Pessoas[pilha->topo];
    pilha->topo--;
    return pessoa;
}

// Função para imprimir os elementos da pilha
void imprimirPilha(Pilha* pilha) {
    int i;
    printf("Pilha: ");
    for (i = pilha->topo; i >= 0; i--) {
        printf("(%s, %d, %d) ", pilha->Pessoas[i].nome, pilha->Pessoas[i].idade, pilha->Pessoas[i].telefone);
    }
    printf("\n");
}

int main() {
    Pilha minhaPilha;
    Pessoa p1, p2,p3;
    strcpy(p1.nome, "Toto");
    p1.idade = 40;
    p1.telefone = 55555555;
    strcpy(p2.nome, "Tote");
    p2.idade = 41;
    p2.telefone = 55555556;
    strcpy(p3.nome,"Yago");
    p3.idade= 22;
    p3.telefone = 984685152;
    inicializarPilha(&minhaPilha);
    empilhar(&minhaPilha, p1);
    empilhar(&minhaPilha, p2);
    imprimirPilha(&minhaPilha);
    Pessoa pessoa1 = desempilhar(&minhaPilha);
Pessoa pessoa2 = desempilhar(&minhaPilha);
printf("Elemento removido: (%s, %d, %d)\n", pessoa1.nome, pessoa1.idade, pessoa1.telefone);
printf("Elemento removido: (%s, %d, %d)\n", pessoa2.nome, pessoa2.idade, pessoa2.telefone);
empilhar(&minhaPilha,p3);
   imprimirPilha(&minhaPilha);
    return 0;
}