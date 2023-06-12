#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val){
    if (root == NULL){
        return newNode(val);
    }
    if (val < root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

struct TreeNode* createTree(int* values, int size){
    struct TreeNode* root = NULL;
    for (int i = 0; i < size; i++){
        if (values[i] != NULL){
            root = insert(root, values[i]);
        }
    }
    return root;
}

void inorderTraversal(struct TreeNode* root){
    if (root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main(){
    bool tru1,tru2;
    
    int values[] = {3, 5, 1, 6, 2, 9, 8, NULL, NULL, 7, 4};
    int size = sizeof(values) / sizeof(values[0]);
    struct TreeNode* root = createTree(values, size);
    printf("Árvore em ordem: ");
    inorderTraversal(root);
    return 0;
}