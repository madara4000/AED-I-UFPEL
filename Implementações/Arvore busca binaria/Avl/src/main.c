
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int maxi(int a, int b) {
    return a > b ? a : b;
}
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Função para criar um novo nó
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Função para calcular a altura de um nó
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Função para calcular o fator de balanceamento de um nó
int balanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Função para realizar uma rotação simples à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas dos nós afetados
    y->height = 1 + maxi(height(y->left), height(y->right));
    x->height = 1 + maxi(height(x->left), height(x->right));

    // Retorna o novo nó raiz
    return x;
}

// Função para realizar uma rotação simples à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas dos nós afetados
    x->height = 1 + maxi(height(x->left), height(x->right));
    y->height = 1 + maxi(height(y->left), height(y->right));

    // Retorna o novo nó raiz
    return y;
}

// Função para inserir um nó com um valor especificado na árvore AVL
Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // O valor já existe na árvore,
        return node;
}


// Atualiza a altura do nó atual
node->height = 1 + maxi(height(node->left), height(node->right));

// Calcula o fator de balanceamento do nó atual
int balance = balanceFactor(node);

// Verifica se o nó atual ficou desbalanceado e, se sim, realiza as rotações necessárias
if (balance > 1 && data < node->left->data) {
    return rotateRight(node);
}
if (balance < -1 && data > node->right->data) {
    return rotateLeft(node);
}
if (balance > 1 && data > node->left->data) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}
if (balance < -1 && data < node->right->data) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// Retorna o nó atual
return node;
}

// Função para realizar uma travessia em ordem na árvore AVL
void inorder(Node* root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}

// Função principal
int main() {
Node* root = NULL;



// Insere alguns nós na árvore AVL
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

// Realiza a travessia em ordem para exibir os elementos ordenados
inorder(root);

return 0;
}