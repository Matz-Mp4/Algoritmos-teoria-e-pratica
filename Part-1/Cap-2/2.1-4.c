// Enunciado: Considere o problema de somar dois inteiros binários de n bits,
//            armazenados em dois arranjos de n elemntos A e B. A soma dos dois
//            inteiros deve ser armaenada em forma binária  em uma arranjo de
//            (n+1) elementos C

#include <stdio.h>
#include <stdlib.h>

// De acordo com o enunciado eles tem o mesmo tamanho de bits
int *somarBits(int A[], int B[], int tam) {
  int tamC = tam + 1;
  int *C = malloc(sizeof(int) * tamC);
  int vaiUm = 0, soma, pos;
  

  for (int i = 0; i < tam; i++) {
    soma = A[i] + B[i] + vaiUm;
    pos = tamC - i - 1;
    switch (soma) {
    case 3:
      C[pos] = 1;
      vaiUm = 1;
      break;

    case 2:
      C[pos] = 0;
      vaiUm = 1;
      break;

    default:
      // Unica possibilidade para soma e 1 ou 0
      C[pos] = soma;
      vaiUm = 0;
      break;
    }
  }

  // Colocar o ultimo o bit
  C[0] = vaiUm;

  return C;
}

int main() {

  printf("\nBit A = 11011");
  printf("\nBit B = 01011");
  printf("$1");

  int A[] = {1, 1, 0, 1, 1};
  int B[] = {1, 1, 0, 1, 0};


  int *C = somarBits(A, B, 5);

  printf("\nA + B = ");

  for (int i = 0; i < 6; i++) {
    printf("%d", C[i]);
  }

  return 0;
}
