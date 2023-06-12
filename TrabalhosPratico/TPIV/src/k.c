



/*Yago Martins Pintos Turma:M2
 Você recebe um vetor de inteiro nums e um inteiro k. Você deseja encontrar uma subsequência em
nums de comprimento k que tenha a maior soma.
Retorne a subsequência como uma matriz de inteiros com comprimento k.
Uma subsequência é uma matriz que pode ser extraída de outra matriz excluindo alguns ou nenhum
elemento sem alterar a ordem dos elementos restantes.*/

#include <stdio.h>
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
    
    
    void ordenar_por_aparecimento(int *vetor1, int k, int *vetor2, int n) {
    int *temp = (int *) malloc(k * sizeof(int)); // aloca vetor temporário
    int temp_idx = 0; // índice do vetor temporário
    // percorre o vetor2 e adiciona os elementos correspondentes do vetor1 no vetor temporário
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (vetor2[i] == vetor1[j]) {
                temp[temp_idx++] = vetor1[j];
            }
        }
    }
    // copia o vetor temporário de volta para o vetor1
    for (int i = 0; i < k; i++) {
        vetor1[i] = temp[i];
    }
    free(temp); // libera memória alocada para vetor temporário
}
    


    int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    int* vector = (int*)malloc(k * sizeof(int));
    if (vector == NULL) {
        printf("Nao tem memoria disponivel para alocar\n");
        return NULL;
    }
 
   
    InsertionSort(nums, numsSize);

    for (int i = numsSize - 1, j = 0; i >= numsSize - k; i--, j++) {
        vector[j] = nums[i];
    }

    *returnSize = k;
   ordenar_por_aparecimento(vector,k,nums,numsSize);
    return vector;
}


   
void printArray(int *N, int numssize) {
  for (int i = 0; i < numssize; i++) {
    printf("%d ", N[i]);
  }
  printf("\n");
} 




int main() {
   int nums1[] = {2,1,3,3};
    int k2 = 3;// segundo teste
    int nums2[] = {-1,-2,3,4};
    int nums3[] = {3,4,3,3};
    int nums4[] ={50,-75};
    //1 teste e terceiro teste
    int numsSize = 4;
    int numsSize2= 2;
    int k = 2;
    int returnSize;
    int* vector = maxSubsequence(nums1, numsSize, k, &returnSize);
    int* vector2 = maxSubsequence(nums2, numsSize, k2, &returnSize);
    int* vector3 = maxSubsequence(nums3, numsSize, k, &returnSize);
    int* vector4 = maxSubsequence(nums4, numsSize2, k, &returnSize);
    printf("Subsequencia com maior soma:\n");
   printArray(vector,k);
    printf("Subsequencia com maior soma:\n");
   printArray(vector2,k2);
   printf("Subsequencia com maior soma:\n");
   printArray(vector3,k);
    printf("Subsequencia com maior soma:\n");
   printArray(vector4,k);
    free(vector);
    free(vector2);
    free(vector3);
    return 0;
}
