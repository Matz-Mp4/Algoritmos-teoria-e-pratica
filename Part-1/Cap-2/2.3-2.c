/*Exercicio: Reescreva o procedimento Merge de modo que ele nao utilizae
 * sentinelas e, em vez disso, pare tão logo todos os elemtnos do arranjo L ou
 * do arranjo R tenham sido copiados de volta em A e entação copie o restante do
 * outro arranjo de volta     */

#include <math.h>
#include <stdio.h>

/* array [p ... r] => p <= q < r
 * Voce pode querer ordenar uma parte do vetor
 * ou array [... p .... r ...]
 * o procedimento que os sub arrays
 * L[p ... q] e R[q+1 ... r] estao ordenados
 */
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
    // Faca testes ajuda muito
    if ((i < n1 && L[i] < R[j]) || (j == n2)) {
      /* if(L[i] <= R[j]) -> incompleto */
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

int main() {

  int array[11] = {5, 2, 4, 7, 1, 3, 6, 8, -2, -10, 4};

  printf("\nLista: ");
  for (int i = 0; i < 11; i++) {
    printf("%d ", array[i]);
  }

  mergerSort(array, 0, 11);

  printf("\nLista com mergeSort: ");
  for (int i = 0; i < 11; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
