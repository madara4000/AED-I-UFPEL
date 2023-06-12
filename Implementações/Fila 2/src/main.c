#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[10];
    int idade;
    int altura;
} Data;

typedef struct Node {
    Data info;
    struct Node *next;
} Node;

typedef struct Fila {
    Node *pfront;
    Node *prear;
} Fila;

void Push(Fila *fila, Node *pnodo) {
    if (fila == NULL || pnodo == NULL)
        return;

    pnodo->next = NULL;

    if (fila->prear == NULL) {
        fila->pfront = pnodo;
        fila->prear = pnodo;
    } else {
        fila->prear->next = pnodo;
        fila->prear = pnodo;
    }
}

Node *Pop(Fila *fila) {
    if (fila == NULL || fila->pfront == NULL)
        return NULL;

    Node *poppedNode = fila->pfront;
    fila->pfront = fila->pfront->next;
    if (fila->pfront == NULL)
        fila->prear = NULL;

    poppedNode->next = NULL;
    return poppedNode;
}

void Clear(Fila *fila) {
    if (fila == NULL)
        return;

    Node *current = fila->pfront;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    fila->pfront = NULL;
    fila->prear = NULL;
}

void Reset(Fila *fila) {
    Clear(fila);
}

int main() {
    Fila fila;
    fila.pfront = NULL;
    fila.prear = NULL;

    // Create nodes and data
    Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));

    Data data1, data2, data3;
    strcpy(data1.nome, "John");
    data1.idade = 25;
    data1.altura = 180;

    strcpy(data2.nome, "Alice");
    data2.idade = 30;
    data2.altura = 165;

    strcpy(data3.nome, "Bob");
    data3.idade = 28;
    data3.altura = 175;

    // Push nodes to the queue
    node1->info = data1;
    node1->next = NULL;
    Push(&fila, node1);

    node2->info = data2;
    node2->next = NULL;
    Push(&fila, node2);

    node3->info = data3;
    node3->next = NULL;
    Push(&fila, node3);

    // Pop nodes from the queue
    Node *poppedNode;
    poppedNode = Pop(&fila);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    poppedNode = Pop(&fila);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    poppedNode = Pop(&fila);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    // Clear the queue
    Clear(&fila);

    return 0;
}
