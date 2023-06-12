#include <stdio.h>
typedef struct 
{
   int cod;
   char nome[40];
   int idade;}
Sdado;
typedef struct{
    Sdado info;
    struct SNodo *pNext;
} SNodo;
typedef struct
{ struct SNodo *pfirst;

}
SLista;
void POP(SLista *plista,SNodo *pNodo, unsigned int nindex) {
 SNodo *pAnterior, *pAtual;

int nPos;
if (plista->pfirst== NULL) return 0;
if (nindex== 0) {
    pNodo = plista->pfirst;
    plista->pfirst = plista->pfirst->pNext;
    return 1 ;
}

pAtual = plista->pfirst;
for (int nPos = 0; nPos < nindex && pAtual != NULL; nPos++) { pAnterior = pAtual;
pAtual= pAtual->pNext;}
 if (!pAtual) return 0;
 pAnterior->pNext=pAtual->pNext;
 pNodo=pAtual;
 return 1;
}
void Reset (SLista *plista){

    Clear(plista);
    plista= (SLista *)malloc(sizeof(SLista));
    if
(plista->pfirst==NULL)
return 0;
}

int Push(SLista *plista,SNodo * pNodo, unsigned int nindex) { SNodo *panterior;
 SNodo *patual;
 int npos;
 if
(plista->pfirst == NULL && nindex != 0) return 0 ;
else if (plista->pfirst == NULL && nindex == 0 ) {
     plista->pfirst=pNodo;
     plista->pfirst->pNext=NULL;

 return 1 ;

}
else if (nindex == 0)
{ pNodo->pNext=plista->pfirst;
  plista->pfirst=pNodo;
 return 1;
}
patual = plista->pfirst;
for (int npos = 0;npos <= nindex && patual != NULL;npos++)
{
   pNodo->pNext=patual;
   panterior->pNext=pNodo;   
   return 1;
}

}
int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}
