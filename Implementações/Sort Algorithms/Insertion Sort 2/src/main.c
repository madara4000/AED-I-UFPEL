#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int* vector, int size) {
    for (int i = 1; i < size; i++) {
        int chave = vector[i];
        int j = i - 1;
        while (j >= 0 && vector[j] < chave) { 
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = chave;
    }
}

int main() {  
    int size, v = 0, n = 0;
    int* vector = NULL;

    do {    
        printf("\t MENU\n");
        printf("\t\t 1: adicionar numero\n");
        printf("\t\t 2: imprimir vetor\n");
        printf("\t\t 3: sair\n");
        printf("digite a opcao: ");
        scanf("%d", &v);

        switch (v) {
        case 1:
            n++;
            vector = realloc(vector, n * sizeof(int));
            printf("entre com o numero: ");
            scanf("%d", &vector[n-1]); // store new number in the last element of the array
            break;

        case 2:
            size = n; // the size of the array is equal to the number of elements
            InsertionSort(vector, size);
            for (int i = 0; i < size; i++) {
                printf("%d\n", vector[i]);
            }
            break;
        
        case 3:
            printf("saindo...\n");
            break;

        default:
            printf("opcao invalida\n");
            break;
        }
    } while (v != 3);

    free(vector);

    return 0;
}
























/*#include <stdio.h>
#include<stdlib.h>
void InsertionSort(int* vector,int size){
    for(int i=0;i<size;i++){
   int chave=vector[i];
   int j=i-1;
    while ((j>0) || (vector[j]<chave)){ 
        vector[j+1]=vector[j];
        j--;
         
    }
vector[j+1]=chave;
    }
}
int main()
{  
   int size, v=0, n=0;
   int *vector=NULL;
    do
    {    
        printf("\t MENU\n");
        printf("\t\t 1:adicionar numero:\n");
        printf("\t\t 2:imprimir vetor:\n");
        printf("\t\t 3:Sair:\n");
        printf("digite a opcao:");
        scanf("%d",v);
        switch (v)
        {
        case 1:
        
           printf("entre com o numero:");
           scanf("%d",vector[n]);
           n+=1;
           vector=realloc(vector,n*sizeof(int));
            break;

           case 2:
           size=sizeof(vector)/sizeof(vector[0]);
           InsertionSort(vector,size);
           for ( int i = 0; i < size-1; i++)
           {  printf("%d\n",vector[i]);
            
           }
           
            break;
            case 3:  
            free(vector);
            return 0;
        
        default:
        printf("opcao invalida\n");
        return 0;
            break;
        }
    } while (v != 3);
    
    

    return 0;
}
*/