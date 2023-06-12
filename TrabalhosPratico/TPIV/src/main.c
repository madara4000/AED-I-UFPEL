/*Yago Martins Pintos Turma:M2
 Você recebe um vetor de inteiro nums e um inteiro k. Você deseja encontrar uma subsequência em
nums de comprimento k que tenha a maior soma.
Retorne a subsequência como uma matriz de inteiros com comprimento k.
Uma subsequência é uma matriz que pode ser extraída de outra matriz excluindo alguns ou nenhum
elemento sem alterar a ordem dos elementos restantes.*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void ordenar_por_aparecimento(int *vetor1, int k, int *vetor2, int n,int *temp)
{
    
    if (k <= n)
    { 
        int index = 0; // índice do vetor temporário
        // percorre o vetor2 e adiciona os elementos correspondentes do vetor1 no vetor temporário
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (vetor2[i] == vetor1[j])
                {
                    temp[index] = vetor1[j];
                    index++;
                }
            }
        }
        // copia o vetor temporário de volta para o vetor1
        for (int i = 0; i < k; i++)
        {
            vetor1[i] = temp[i];
        }
    }
    else
    {
        printf("k maior que o vetor de origem\n");
        return;
    }
  
}
void InsertionSort(int *N,int numssize){

    for (int i= 1; i < numssize; i++)
    {  int key =N[i];
            int j=i-1;
        while ((j>=0) && (N[j]>key) )
        {   N[j+1]=N[j];
         j--;

        }
        N[j+1]=key;
        
    }
    }

   
void printArray(int *N, int numssize) {
  for (int i = 0; i < numssize; i++) {
    printf("%d ", N[i]);
  }
  printf("\n");
} 
int* maxSubsequence(int *nums, int numsSize, int k,int* returnSize )//
{ 
  int *temp=(int*)malloc(k*sizeof(int));
int *num1=(int*)malloc(numsSize*sizeof(int));
 int *vector = NULL;
 vector = (int *)malloc(k * sizeof(int));
  if (vector == NULL||num1  == NULL)
    {

        printf("Nao tem memoria disponivel para alocar\n");
        return NULL;
    }
for (int i = 0; i < k; i++)
{
  num1[i]=nums[i];
}

 InsertionSort(nums,numsSize);
 
 int newsize;
 newsize = numsSize-1-k;
 int s = 0;
for ( numsSize-1; numsSize-1 >newsize; numsSize--)
{  vector[s]=nums[numsSize-1] ;

    s++;
}
ordenar_por_aparecimento(vector,k,num1,numsSize,temp);
free(temp);
free(num1);
*returnSize=k;
return vector;
 free(vector);
 
}

int main()

{   int nums1[] = {2,1,3,3};
    int k2 = 3;// segundo teste
    int nums2[] = {-1,-2,3,4};
    int nums3[] = {3,4,3,3};
    int k = 2;//1 teste e terceiro teste
    int returnSize;
    int size = sizeof(nums1)/sizeof(nums1[0]);
    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    int size3 = sizeof(nums3)/sizeof(nums3[0]);
    maxSubsequence(nums1,size,k,returnSize);
    maxSubsequence(nums2,size2,k2,returnSize);
    maxSubsequence(nums3,size3,k,returnSize);
    //InsertionSort(nums,size);
    //printArray(nums,size);
    //printArray(nums2,size2);
    //printArray(nums3,size3);
   
   
    return 0;
}
