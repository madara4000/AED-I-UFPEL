// Nome:Yago Martins Pintos M2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void getLeaf(struct TreeNode *root, int *treeleafstemp, int *nleafs)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        treeleafstemp[(*nleafs)++] = root->val;
    else
    {
        getLeaf(root->left, treeleafstemp, nleafs);
        getLeaf(root->right, treeleafstemp, nleafs);
    }
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int numberleafs1 = 0, numberleafs2 = 0, nelements = 200;

    int *leafs = (int *)malloc(nelements * sizeof(int));
    int *leafs1 = (int *)malloc(nelements * sizeof(int));

    getLeaf(root1, leafs, &numberleafs1);
    getLeaf(root2, leafs1, &numberleafs2);

    if (memcmp(leafs, leafs1, numberleafs1 * sizeof(int)) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct TreeNode *newNode(int val)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

struct TreeNode *createTree(int *values, int size)
{
    struct TreeNode *root = NULL;
    for (int i = 0; i < size; i++)
    {
        if (values[i] != NULL)
        {
            root = insert(root, values[i]);
        }
    }
    return root;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main()
{
    bool tru1, tru2;
    int values[] = {3, 5, 1, 6, 2, 9, 8, 7, 4};
    int size = sizeof(values) / sizeof(values[0]);
    struct TreeNode *root = createTree(values, size);
    /*printf("Árvore em ordem: ");
    inorderTraversal(root);*/
    int values1[] = {3, 5, 1, 6, 7, 4, 2, 9, 8};
    int size1 = sizeof(values1) / sizeof(values1[0]);
    struct TreeNode *root1 = createTree(values1, size1);
    /*printf("Árvore 1 em ordem: ");
    inorderTraversal(root1);*/

    int values2[] = {1, 2, 3};
    int size2 = sizeof(values2) / sizeof(values2[0]);
    struct TreeNode *root2 = createTree(values2, size2);
    /*printf("\nÁrvore 2 em ordem: ");
    inorderTraversal(root2);*/

    int values3[] = {1, 3, 2};
    int size3 = sizeof(values3) / sizeof(values3[0]);
    struct TreeNode *root3 = createTree(values3, size3);
    /*printf("\nÁrvore 3 em ordem: ");
    inorderTraversal(root3);*/

    tru1 = leafSimilar(root, root1);
    tru2 = leafSimilar(root2, root3);
    if (tru1 == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    if (tru2 == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}