/* Enunciado: Considere a ordenação de n numeros armzaenados no arranjo A,
              localizando o primeiro menor elemento de A e permutando esse
              elemento com o elemnto contido em A[1]. Em seguida, determine o
              segundo menor elemento de A e permutando-o com A[2]. Continue
              dessa maneira para os primeiros n - 1 elementos de A. Escreva
              esse algoritmo, conhecido comoSelection Sort.*/

#include <stdio.h>
void selectionSort(int vet[], int tam) {
  int menor, pos, troca;
  for (int i = 0; i < tam - 1; i++) {
    menor = vet[i];
    pos = -1;

    for (int j = i + 1; j < tam; j++) {
      if (menor > vet[j]) {
        menor = vet[j];
        pos = j;
      }
    }
    if (pos != -1) {
      troca = vet[i];
      vet[i] = menor;
      vet[pos] = troca;
    }
  }
}

int main() {
  int vet[12] = {4, 10, 3, 48, 90, 1, 38, 47, 100, 12, 0, 37};
  int tam = 12;
  printf("\nLista: ");

  for (int i = 0; i < tam; i++) {
    printf("%d ", vet[i]);
  }

  selectionSort(vet, tam);

  printf("\nLista com selectionSort: ");

  for (int i = 0; i < tam; i++) {
    printf("%d ", vet[i]);
  }

  return 0;
}
