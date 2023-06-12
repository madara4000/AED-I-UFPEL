#include<stdio.h>
#include<stdlib.h>
void ordenar_por_aparecimento(int* vetor1, int k, int* vetor2, int n) {
    int* temp = (int *) malloc(k * sizeof(int)); // aloca vetor temporário
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

int main(){
int vetor1[] = {3, 4};
int vetor2[] = {4, 3};
int k = 2;
int n = 2;
int nums1[] = {2,1,3,3};
    int k2 = 3;// segundo teste
    int nums2[] = {-1,-2,3,4};
    int nums3[] = {3,4,3,3};
     int out2[]={4,3};
    int nums4[] ={50,-75};
    int out[]={-75,50};
    //1 teste e terceiro teste
    int numsSize = 4;
    int numsSize2= 2;

ordenar_por_aparecimento(vetor1, k, vetor2, n);
ordenar_por_aparecimento(out2, k, nums3, n);
ordenar_por_aparecimento(out, k, nums4, n);
// imprime o vetor1 depois de ordenado
for (int i = 0; i < k; i++) {
    printf("%d ", vetor1[i]);
}
// saída: 4 3
printf("\n");
for (int i = 0; i < k; i++) {
    printf("%d ", out[i]);
}
printf("\n");
for (int i = 0; i < k; i++) {
    printf("%d ", out2[i]);
}

}




/*void ordenar_por_aparecimento(int *vetor1, int k, int *vetor2, int n) {
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
}*/