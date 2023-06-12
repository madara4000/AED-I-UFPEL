#include <stdio.h>
#include <stdlib.h>
void InsertionSort(int *N,int size){

    for (int i= 1; i < size; i++)
    {  int key =N[i];
            int j=i-1;
        while ((j>=0) && (N[j]>key) )
        {   N[j+1]=N[j];
         j--;

        }
        N[j+1]=key;
        
    }
    }

   // Function to print an array
void printArray(int *N, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", N[i]);
  }
  printf("\n");
} 


int main()
{ int data[] = {9, 5, 1, 4, 3};

  int size = sizeof(data) / sizeof(data[0]);
  InsertionSort(data, size);
 printArray(data, size);

    return 0;
}
