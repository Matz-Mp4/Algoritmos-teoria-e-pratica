// Enunciado: Reescreva o procedimento Insertion-Sort para ordenar em ordem
//            decrescente, em vez da ordem crescente

#include <stdio.h>

void insertionSort(int vet[], int tam) {
  int i, chave, j;

  for (i = 1; i < tam; i++) {
    chave = vet[i];

    j = i - 1;
    while (j >= 0 && vet[j] < chave) {
      vet[j + 1] = vet[j];
      j--;
    }
    vet[j + 1] = chave;
  }
}

int main() {

  int vet[9] = {3, 45, 2, 8, 12, 2, 2, 4, 10}, i;

  printf("Lista: ");

  for (i = 0; i < 9; i++) {
    printf("%d ", vet[i]);
  }
  insertionSort(vet, 9);
  printf("\nInsertion-Sort: ");

  for (i = 0; i < 9; i++) {
    printf("%d ", vet[i]);
  }
}
