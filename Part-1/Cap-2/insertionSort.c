#include <stdio.h>
#include <stdlib.h>

int main() {

  int i, j = 0;

  int vet[9] = {3, 45, 2, 8, 12, 2, 2, 4, 10};
  int tam = 9, chave;

  printf("Lista: ");

  for (i = 0; i < tam; i++) {

    printf("%d ", vet[i]);
  }

  for (i = 1; i < tam; i++) {
    chave = vet[i];

    j = i - 1;
    while (j >= 0 && vet[j] > chave) {
      vet[j + 1] = vet[j];
      j--;
    }
    vet[j + 1] = chave;
  }
  
  printf("InsertSort: ");

  for (i = 0; i < tam; i++) {

    printf("%d ", vet[i]);
  }
  return 0;
}
