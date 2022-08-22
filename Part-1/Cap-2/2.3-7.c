/* Enunciado: Crie um algoritmo de tempo O(n * lg(n)) que, dado, um conjunto S
 * de n inteiros e um outro inteiro x, determine se existem ou não dois
 * elementos em S cuja soma seja extamente x  */

#include <stdbool.h>
#include <stdio.h>
void merge(int array[], int inicio, int q, int fim) {
  // Se lembre que o array comeca no 0
  int n1 = q - inicio + 1;
  int n2 = fim - q;
  int pos, i, j;

  int L[n1];
  int R[n2];

  for (i = 0; i < n1; i++) {
    pos = inicio + i;
    L[i] = array[pos];
  }

  for (j = 0; j < n2; j++) {
    pos = q + 1 + j;
    R[j] = array[pos];
  }
  i = 0;
  j = 0;
  int k;
  for (k = inicio; k <= fim; k++) {

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

void mergerSort(int array[], int inicio, int fim) {
  int q;
  if (inicio < fim) {
    q = (fim + inicio) / 2;
    mergerSort(array, inicio, q);
    mergerSort(array, q + 1, fim);
    merge(array, inicio, q, fim);
  }
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

bool buscarSoma(int n, int array[], int tam) {
  bool achou = false;
  int i = 0, j;
  mergerSort(array, 0, tam - 1);


  while (achou == false && i < tam) {
    j = buscarRecursivo(array, n - array[i], 0, tam - 1);
    if (j != -1 && (array[j] != array[i])) {
      achou = true;
    }
    i++;
  }
  return achou;
}
int main() {

  int array[10] = {20, 102, 5, 1, 4, 10, 39, 3, 17, 9};
  int numero;

  printf("\nLista: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  numero = 21;

  if (buscarSoma(numero, array, 10) == true) {
    printf("\nExiste dois numeros que somados é igual a %d", numero);
  } else {
    printf("\nNao Existe dois numeros que somados é igual a %d", numero);
  }
  return 0;
}
