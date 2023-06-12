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
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int maxi(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(Node *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node *createNode(Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxi(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxi(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxi(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxi(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insertNode(Node *root, Data data) {
    if (root == NULL)
        return createNode(data);

    if (strcmp(data.nome, root->info.nome) < 0)
        root->left = insertNode(root->left, data);
    else if (strcmp(data.nome, root->info.nome) > 0)
        root->right = insertNode(root->right, data);
    else
        return root; // Elemento já existe na árvore

    root->height = maxi(getHeight(root->left), getHeight(root->right)) + 1;

    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) {
        if (strcmp(data.nome, root->left->info.nome) < 0)
            return rightRotate(root);
        else if (strcmp(data.nome, root->left->info.nome) > 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balanceFactor < -1) {
        if (strcmp(data.nome, root->right->info.nome) > 0)
            return leftRotate(root);
        else if (strcmp(data.nome, root->right->info.nome) < 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
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
    Node *root = NULL;

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

    strcpy(data4.nome, "Eva");
    data4.idade = 32;
    data4.altura = 160;

    strcpy(data5.nome, "Mike");
    data5.idade = 27;
    data5.altura = 175;

    root = insertNode(root, data1);
    root = insertNode(root, data2);
    root = insertNode(root, data3);
    root = insertNode(root, data4);
    root = insertNode(root, data5);

    printf("Imprimindo em ordem crescente:\n");
    inOrderTraversal(root);

    freeTree(root);

    return 0;
}
