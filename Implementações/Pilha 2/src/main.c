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

typedef struct Pilha {
    Node *ptop;
} Pilha;

void Push(Pilha *pilha, Node *pnodo) {
    if (pilha == NULL || pnodo == NULL)
        return;

    pnodo->next = pilha->ptop;
    pilha->ptop = pnodo;
}

Node *Pop(Pilha *pilha) {
    if (pilha == NULL || pilha->ptop == NULL)
        return NULL;

    Node *poppedNode = pilha->ptop;
    pilha->ptop = pilha->ptop->next;
    poppedNode->next = NULL;
    return poppedNode;
}

void Clear(Pilha *pilha) {
    if (pilha == NULL)
        return;

    Node *current = pilha->ptop;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    pilha->ptop = NULL;
}

void Reset(Pilha *pilha) {
    Clear(pilha);
}

int main() {
    Pilha pilha;
    pilha.ptop = NULL;

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

    // Push nodes to the stack
    node1->info = data1;
    node1->next = NULL;
    Push(&pilha, node1);

    node2->info = data2;
    node2->next = NULL;
    Push(&pilha, node2);

    node3->info = data3;
    node3->next = NULL;
    Push(&pilha, node3);

    //Pilha
    Node *poppedNode;
    poppedNode = Pop(&pilha);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    poppedNode = Pop(&pilha);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    poppedNode = Pop(&pilha);
    if (poppedNode != NULL) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    // Clear the stack
    Reset(&pilha);


    return 0;
}
