#include <stdio.h>

void QuickSort(int *N, int left, int right) {
    int i, j, mid, tmp;
    i = left;
    j = right;
    mid = N[(left + right) / 2];
    do {
        while (N[i] < mid) {
            i++;
        }
        while (mid < N[j]) {
            j--;
        }
        if (i <= j) {
            tmp = N[i];
            N[i] = N[j];
            N[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) {
        QuickSort(N, left, j);
    }
    if (i < right) {
        QuickSort(N, i, right);
    }
}



int main()
{ int data[] = {9, 5, 1, 4, 3};

  int size = sizeof(data) / sizeof(data[0]);
  
 printArray(data, size);

    return 0;
}
