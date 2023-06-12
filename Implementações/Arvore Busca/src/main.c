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
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    printf("Nome: %s, Idade: %d, Altura: %d\n", root->info.nome, root->info.idade, root->info.altura);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("Nome: %s, Idade: %d, Altura: %d\n", root->info.nome, root->info.idade, root->info.altura);
}

void inOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("Nome: %s, Idade: %d, Altura: %d\n", root->info.nome, root->info.idade, root->info.altura);
    inOrderTraversal(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create nodes and data
    Data data1, data2, data3, data4, data5;
    strcpy(data1.nome, "John");
    data1.idade = 25;
    data1.altura = 180;

    strcpy(data2.nome, "Alice");
    data2.idade = 30;
    data2.altura = 165;

    strcpy(data3.nome, "Bob");
    data3.idade = 28;
    data3.altura = 175;

    strcpy(data4.nome, "Mary");
    data4.idade = 35;
    data4.altura = 160;

    strcpy(data5.nome, "David");
    data5.idade = 22;
    data5.altura = 190;

    // Create the tree
    Node *root = createNode(data1);
    root->left = createNode(data2);
    root->right = createNode(data3);
    root->left->left = createNode(data4);
    root->left->right = createNode(data5);

    // Print the tree in pre-order
    printf("Pre-order traversal:\n");
    preOrderTraversal(root);
    printf("\n");

    // Print the tree in post-order
    printf("Post-order traversal:\n");
    postOrderTraversal(root);
    printf("\n");

    // Print the tree in in-order (central) traversal
    printf("In-order traversal:\n");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);

    return 0;
}
