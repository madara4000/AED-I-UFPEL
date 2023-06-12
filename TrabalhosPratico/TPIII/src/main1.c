//Nome:Yago Martins Pintos M2
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
        getLeaf(root->right,treeleafstemp, nleafs);
    }
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    int numberleafs1=0,numberleafs2=0,nelements=200;
    
 int *leafs=(int*)malloc( nelements * sizeof(int)) ;  
int *leafs1=(int*)malloc( nelements * sizeof(int)) ;  
  
   
    
    getLeaf(root1, leafs, &numberleafs1);
    getLeaf(root2, leafs1, &numberleafs2);
    
    if(memcmp(leafs,leafs1,numberleafs1*sizeof(int)) == 0) {
        return true;}else{ return false;}
}


typedef struct TreeNode* Treebin ;
Treebin* create_TreeBin()
{
    Treebin *Root = (Treebin *)malloc(sizeof(struct TreeNode*));
    if (Root != NULL)
        *Root = NULL;
    return Root;
}
void free_Node(struct TreeNode *Node)
{
    if (Node == NULL)
        return;
    free_Node(Node->left);
    free_Node(Node->right);
    free(Node);
    Node = NULL;
}
void Free_TreeBin(Treebin *Root)
{
    if (Root == NULL)
        return;
    free_Node(*Root); 
    free(*Root);       
}
int totalNode_Treebin(Treebin *Root)
{
    if (Root == NULL)
        return 0;
    if (*Root == NULL)
        return 0;
    int alt_left = totalNode_Treebin(&((*Root)->left));
    int alt_right = totalNode_Treebin(&((*Root)->right));
    return (alt_left + alt_right + 1);
}
int itsfree_Treebin(Treebin *Root)
{
    if (Root == NULL)
        return 1;
    if (*Root == NULL)
        return 1;
    return 0;
}

int POP(Treebin *Root, int value)
{
    if (Root == NULL)
        return 0;
    struct TreeNode *new;
    new = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (new == NULL)
        return 0;
    new->val = value;
    new->right = NULL;
    new->left = NULL;

    if (*Root == NULL)
        *Root = new;
    else
    {
        struct TreeNode *current = *Root;
        struct TreeNode *previous = NULL;
        while (current != NULL)
        {
            previous = current;
            if (value == current->val)
            {
                free(new);
                return 0; 
            }

            if (value > current->val)
                current = current->right;
            else
                current = current->left;
        }
        if (value > previous->val)
            previous->right = new;
        else
            previous->left = new;
    }
    return 1;
}
int altura_Treebin(Treebin *Root){
    if (Root == NULL)
        return 0;
    if (*Root == NULL)
        return 0;
    int alt_left = altura_Treebin(&((*Root)->left));
    int alt_right = altura_Treebin(&((*Root)->right));
    if (alt_left > alt_right)
        return (alt_left + 1);
    else
        return(alt_right + 1);
}

int main()
{ bool value;
    int N = 9, Date1[9] = {3, 5, 1, 6, 2, 9, 8, 7, 4};
    int M = 3, Date2[9] = {3, 5, 1, 6, 7, 4, 2, 9, 8};

    Treebin *Root = create_TreeBin();
    Treebin *Root1 = create_TreeBin();
    int i;
    for (i = 0; i < N; i++)
    {
        POP(Root, Date1[i]);

        
    }

    for (i = 0; i < N; i++)
    {
        POP(Root1, Date2[i]);

      
    }
    leafSimilar((struct TreeNode*)Root, (struct TreeNode*)Root1);
    int Date3[3] = {1, 2, 3}, Date4[3] = {1, 3, 2};
Treebin *Root2 = create_TreeBin();
    Treebin *Root3 = create_TreeBin();
     for (i = 0; i < M; i++)
    {
        POP(Root2, Date3[i]);

        
    }

    for (i = 0; i < M; i++)
    {
        POP(Root3, Date4[i]);

        
    }
    leafSimilar((struct TreeNode*)Root2,(struct TreeNode*) Root3);
   value= leafSimilar((struct TreeNode*)Root2, (struct TreeNode*)Root3);
    if(value==true){printf("true");}
    else {printf("false");}
    Free_TreeBin(Root); 
    Free_TreeBin(Root1); 
    Free_TreeBin(Root2);
    Free_TreeBin(Root3);
    return 0;
}
