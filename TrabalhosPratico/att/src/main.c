#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArray(int *N, int numssize)
{
    for (int i = 0; i < numssize; i++)
    {
        printf("%d ", N[i]);
    }
    printf("\n");
}
void InsertionSort(int *N, int numssize)
{

    for (int i = 1; i < numssize; i++)
    {
        int key = N[i];
        int j = i - 1;
        while ((j >= 0) && (N[j] < key))
        {
            N[j + 1] = N[j];
            j--;
        }
        N[j + 1] = key;
    }
}

int *maxSubsequence(int *nums, int numsSize, int k, int *returnSize)
{
    int Noccurence = 0;
    int *vector = (int *)malloc(k * sizeof(int));
    int *sort = (int *)malloc(numsSize * sizeof(int));

    if (vector == NULL || sort == NULL)
    {
        printf("Nao tem memoria disponivel para alocar\n");
        free(vector);
        free(sort);
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        sort[i] = nums[i];
    }

    InsertionSort(sort, numsSize);
    int lastk = sort[k - 1];

    
    for (int i = k - 1; i >= 0; i--)//verefica as ocorrencias onde elementos são iguais
    {
        if (sort[i] == lastk)
            Noccurence++;
        else
            break;
    }

    for (int i = 0, j = 0; i < numsSize; i++)
    {
        if (nums[i] > lastk){
            vector[j] = nums[i];
            j++;}
        else if (nums[i] == lastk)
        {
            if (Noccurence > 0)
            {
                vector[j++] = nums[i];
                Noccurence--;
            }
        }
    }

    *returnSize = k;
    return vector;
}

int main()
{
    int nums1[] = {2, 1, 3, 3};
    int k2 = 3; // segundo teste
    int nums2[] = {-1, -2, 3, 4};
    int nums3[] = {3, 4, 3, 3};
    int nums4[] = {50, -75};
    // 1 teste e terceiro teste
    int numsSize = 4;
    int numsSize2 = 2;
    int k = 2;
    int returnSize = 0;

    int *vector = maxSubsequence(nums1, numsSize, k, &returnSize);
    int *vector2 = maxSubsequence(nums2, numsSize, k2, &returnSize);
    int *vector3 = maxSubsequence(nums3, numsSize, k, &returnSize);
    int *vector4 = maxSubsequence(nums4, numsSize2, k, &returnSize);
    printf("Subsequencia com maior soma:\n");
    printArray(vector, k);
    printf("Subsequencia com maior soma:\n");
    printArray(vector2, k2);
    printf("Subsequencia com maior soma:\n");
    printArray(vector3, k);
    printf("Subsequencia com maior soma:\n");
    printArray(vector4, k);

    free(vector);
    free(vector2);
    free(vector3);
    free(vector4);

    return 0;
}
