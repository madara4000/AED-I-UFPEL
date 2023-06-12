#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { RED, BLACK } Color;

typedef struct Pessoa {
    char nome[10];
    int idade;
    int altura;
} Data;

typedef struct Node {
    Data info;
    Color color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node *createNode(Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->info = data;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node *grandparent(Node *node) {
    if ((node != NULL) && (node->parent != NULL))
        return node->parent->parent;
    else
        return NULL;
}

Node *uncle(Node *node) {
    Node *g = grandparent(node);
    if (g == NULL)
        return NULL;
    if (node->parent == g->left)
        return g->right;
    else
        return g->left;
}

void rotateLeft(Node **root, Node *node) {
    Node *pivot = node->right;
    node->right = pivot->left;
    if (pivot->left != NULL)
        pivot->left->parent = node;
    pivot->parent = node->parent;
    if (node->parent == NULL)
        *root = pivot;
    else if (node == node->parent->left)
        node->parent->left = pivot;
    else
        node->parent->right = pivot;
    pivot->left = node;
    node->parent = pivot;
}

void rotateRight(Node **root, Node *node) {
    Node *pivot = node->left;
    node->left = pivot->right;
    if (pivot->right != NULL)
        pivot->right->parent = node;
    pivot->parent = node->parent;
    if (node->parent == NULL)
        *root = pivot;
    else if (node == node->parent->right)
        node->parent->right = pivot;
    else
        node->parent->left = pivot;
    pivot->right = node;
    node->parent = pivot;
}

void insertFixup(Node **root, Node *node) {
    if (node->parent == NULL) {
        node->color = BLACK;
        return;
    }

    if (node->parent->color == BLACK)
        return;

    Node *unc = uncle(node);
    Node *gparent = grandparent(node);

    if (unc != NULL && unc->color == RED) {
        node->parent->color = BLACK;
        unc->color = BLACK;
        gparent->color = RED;
        insertFixup(root, gparent);
    } else {
        if (node == node->parent->right && node->parent == gparent->left) {
            rotateLeft(root, node->parent);
            node = node->left;
        } else if (node == node->parent->left && node->parent == gparent->right) {
            rotateRight(root, node->parent);
            node = node->right;
        }

        node->parent->color = BLACK;
        gparent->color = RED;
        if (node == node->parent->left && node->parent == gparent->left)
            rotateRight(root, gparent);
        else
            rotateLeft(root, gparent);
    }
}

Node *insertNode(Node *root, Data data) {
    Node *newNode = createNode(data);

    if (root == NULL) {
        newNode->color = BLACK;
        return newNode;
    }

    Node *current = root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (strcmp(newNode->info.nome, current->info.nome) < 0)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;
    if (strcmp(newNode->info.nome, parent->info.nome) < 0)
        parent->left = newNode;
    else
        parent->right = newNode;

    insertFixup(&root, newNode);
    return root;
}

void inOrderTraversal(Node *node) {
    if (node == NULL)
        return;

    inOrderTraversal(node->left);
    printf("Nome: %s, Idade: %d, Altura: %d\n", node->info.nome, node->info.idade, node->info.altura);
    inOrderTraversal(node->right);
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
