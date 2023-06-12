#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
 struct elemento {
    struct Pessoa dados;
    struct elemento prox;
 };
 typedef struct elemento Elem;
Lista* cria_lista(Lista*li){
   Lista*li=(Lista*) malloc(sizeof(Lista));
    if(li!=NULL) *li=NULL;
    return li;
}
Lista* libera_lista(Lista*li){
   if(li !=NULL)
   {Elem* no;
   while((*li) !=NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
   }
free (li);

}
}