
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *N, int begin, int end);

void Merge(int *N, int begin, int quite, int end);

void printArray(int *N, int size);

int main() {
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);
    MergeSort(data, 0, size - 1);
    printArray(data, size);
    return 0;
}

void MergeSort(int *N, int begin, int end) {
    if (begin < end) {
        int quite = (begin + end) / 2;
        MergeSort(N, begin, quite);
        MergeSort(N, quite + 1, end);
        Merge(N, begin, quite, end);
    }
}

void Merge(int *N, int begin, int quite, int end) {
    int n1 = quite - begin + 1;
    int n2 = end - quite;
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) {
        L[i] = N[begin + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = N[quite + 1 + j];
    }
    int i = 0, j = 0, k = begin;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            N[k] = L[i];
            i++;
        } else {
            N[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        N[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        N[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void printArray(int *N, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");
}

