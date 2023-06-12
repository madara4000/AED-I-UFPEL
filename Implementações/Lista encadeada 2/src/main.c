#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
/*typedef struct Pessoa
{
 char nome[10];
 int idade;
 int altura;

}Data;
 typedef struct Node{
    Data info;
    struct Node *next;
 }Node;
 typedef struct Lista{
  Node*pfirst;

 } Lista;
 int PUSH(Lista *plista,Node *pnodo, int nind){
   Node *patual,*panterior;
   int Npos;
   if(plista->pfirst == NULL && nind!=0)
   return 0;
    else if (plista->pfirst == NULL && nind ==0){
      plista->pfirst = pnodo;
      plista->pfirst->next= NULL;
      return 1;
      
      }
      else if(nind== 0){
     pnodo->next=plista->pfirst;
     plista->pfirst=pnodo;
     return 1 ;

      }
    patual = plista->pfirst;
    for ( Npos = 0; Npos <= nind
          && patual  != NULL; Npos++)  {
       panterior = patual;
       patual = patual->next;               
      }
 
    if(!patual) return 0; // erro nIndex nÃ£o existe
 
   pnodo->next = patual;
   panterior->next = pnodo;
  
    return 1;
 }





  int POP(Lista *plista, Node *pnodo, int nind) {
   Node*pAnterior, *pAtual;
 int nPos;

if (plista->pfirst== NULL) return 0; 

if (nind== 0) {
pnodo= plista->pfirst;
 plista->pfirst= plista->pfirst->next;
return 1;
}

 pAtual= plista->pfirst;
 for (nPos= 0; nPos< nind && pAtual!= NULL; nPos++) {
 pAnterior= pAtual;
 pAtual= pAtual->next;
 }

 if(!pAtual) return 0; // erronIndexinvalido

 pAnterior->next= pAtual->next;
 pnodo= pAtual;

return 1;

 
}
void Clear(Lista *plista) {
    if (plista == NULL)
        return;

    Node *current = plista->pfirst;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    plista->pfirst = NULL;
  
}
 
 void RESET(Lista *plista){
    Clear(plista);
    plista=(Lista*) malloc(sizeof(Lista));
    plista->pfirst = NULL;
 }
 
*/




typedef struct Pessoa {
    char nome[10];
    int idade;
    int altura;
} Data;

typedef struct Node {
    Data info;
    struct Node *next;
} Node;

typedef struct Lista {
    Node *pfirst;
} Lista;

int PUSH(Lista *plista, Node *pnodo, int nind) {
    if (plista == NULL || pnodo == NULL || nind < 0)
        return 0;

    if (plista->pfirst == NULL && nind != 0)
        return 0;
    else if (plista->pfirst == NULL && nind == 0) {
        plista->pfirst = pnodo;
        plista->pfirst->next = NULL;
        return 1;
    } else if (nind == 0) {
        pnodo->next = plista->pfirst;
        plista->pfirst = pnodo;
        return 1;
    }

    Node *panterior = plista->pfirst;
    int Npos = 0;
    while (Npos < nind - 1 && panterior->next != NULL) {
        panterior = panterior->next;
        Npos++;
    }

    pnodo->next = panterior->next;
    panterior->next = pnodo;
    return 1;
}

int POP(Lista *plista, Node **ppnodo, int nind) {
    if (plista == NULL || plista->pfirst == NULL || nind < 0)
        return 0;

    if (nind == 0) {
        *ppnodo = plista->pfirst;
        plista->pfirst = plista->pfirst->next;
        (*ppnodo)->next = NULL;
        return 1;
    }

    Node *panterior = plista->pfirst;
    int Npos = 0;
    while (Npos < nind - 1 && panterior->next != NULL) {
        panterior = panterior->next;
        Npos++;
    }

    if (panterior->next == NULL)
        return 0;  // Index out of range

    *ppnodo = panterior->next;
    panterior->next = (*ppnodo)->next;
    (*ppnodo)->next = NULL;
    return 1;
}

void Clear(Lista *plista) {
    if (plista == NULL)
        return;

    Node *current = plista->pfirst;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    plista->pfirst = NULL;
}

void RESET(Lista *plista) {
    Clear(plista);
    plista->pfirst = NULL;
}

int main() {
    Lista lista;
    lista.pfirst = NULL;

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

    // Push nodes to the list
    node1->info = data1;
    node1->next = NULL;
    PUSH(&lista, node1, 0);

    node2->info = data2;
    node2->next = NULL;
    PUSH(&lista, node2, 1);

    node3->info = data3;
    node3->next = NULL;
    PUSH(&lista, node3, 1);

    // Pop node at index 1
    Node *poppedNode;
    if (POP(&lista, &poppedNode, 1)) {
        printf("Popped Node: Nome: %s, Idade: %d, Altura: %d\n",
               poppedNode->info.nome, poppedNode->info.idade, poppedNode->info.altura);
        free(poppedNode);
    }

    // Clear the list
    RESET(&lista);

    return 0;
}

 

