/* Escreva o algoritmo, recursivamente e iterativamente, para busca binaria */

#include <stdbool.h>
#include <stdio.h>
void merge(int array[], int p, int q, int r) {

  // Se lembre que o array comeca no 0
  int n1 = q - p + 1;
  int n2 = r - q;
  int pos, i, j;

  int L[n1];
  int R[n2];

  for (i = 0; i < n1; i++) {
    pos = p + i;
    L[i] = array[pos];
  }

  for (j = 0; j < n2; j++) {
    pos = q + 1 + j;
    R[j] = array[pos];
  }
  i = 0;
  j = 0;
  int k;
  for (k = p; k <= r; k++) {

    // Copia o ultimo elemento que sobrou
    if ((i < n1 && L[i] < R[j]) || (j == n2)) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
  }
}

void mergerSort(int array[], int p, int r) {
  int q;
  if (p < r) {
    q = (r + p) / 2;
    mergerSort(array, p, q);
    mergerSort(array, q + 1, r);
    merge(array, p, q, r);
  }
}

int buscarIterativo(int array[], int item, int tam) {

  int inicio = 0, meio, fim = tam - 1, pos = -1;
  bool achou = false;
  do {
    meio = (inicio + fim) / 2;

    if (array[meio] == item) {
      achou = true;
      pos = meio;
    } else if (array[meio] > item) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }

  } while (achou == false && inicio <= fim);

  return pos;
}
int buscarRecursivo(int array[], int item, int inicio, int fim) {

  int pos;
  if (inicio <= fim) {
    int meio = (fim + inicio) / 2;

    if (array[meio] == item) {
      pos = meio;
    } else if (array[meio] > item) {
      pos = buscarRecursivo(array, item, inicio, meio - 1);
    } else if (array[meio] < item) {
      pos = buscarRecursivo(array, item, meio + 1, fim);
    }
  } else {
    pos = -1;
  }

  return pos;
}

int main() {
  int array[10] = {20, 3, 5, 1, 4, 10, 39, 3, 10, 3};
  int pos;

  mergerSort(array, 0, 9);

  printf("\nLista: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  /* pos = buscarRecursivo(array, 5, 0, 9); */
  pos = buscarIterativo(array, 5, 10);
  printf("\n Posicao no array do elemnto 5: %d", pos);
  return 0;
}
