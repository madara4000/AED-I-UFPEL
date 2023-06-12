#include <stdio.h>
void selectSort(int *N, int size) {
    int min, tmp, i, j, min_id;
    for (i = 0; i < size - 1; i++) {
        min = N[i];
        for (j = i + 1; j < size; j++) {
            if (N[j] < min) {
                min = N[j];
                min_id = j;
            }
        }
        tmp = N[i];
        N[i] = N[min_id];
        N[min_id] = tmp;
    }
}

void printArray(int *N, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", N[i]);
  }
  printf("\n");
} 
int main()
{ int N[] = {9, 5, 1, 4, 3};

  int size = sizeof(N) / sizeof(N[0]);
  selectSort(N, size);
 printArray(N, size);

    return 0;
}
