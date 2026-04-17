#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
  int notaMaxima = a;
  if (b > notaMaxima) {
    return b;
  } else {
    return notaMaxima;
  }
}

int maximo_tres(int a, int b, int c) { return max(max(a, b), max(b, c)); }

int main() {
  srand(time(NULL));

  int i, j;
  int suma = 0;
  int maximaNota = 0;
  int min = 0;

  int matrizA[5][3] = {0};
  // int res[5][3] = {0};

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 3; j++) {
      matrizA[i][j] = rand() % 10 + 1;
    }
  }

  for (i = 0; i < 5; i++) {
    printf("Estudiante -> %d\t\n", i);
  }

  for (i = 0; i < 5; i++) {
    printf("\n");
    for (j = 0; j < 3; j++) {
      printf("%d\t", matrizA[i][j]);
    }
  }
  int res[5][3] = {0};

  for (i = 0; i < 1; i++) {
    printf("\n");
    for (j = 0; j < 3; j++) {
      // printf("Estudiante A  -> %d\t", matrizA[i][j]);
      res[i][j] = matrizA[i][j];
      suma += matrizA[i][j];

      maximaNota = maximo_tres(matrizA[0][0], matrizA[0][1], matrizA[0][2]);

      if (matrizA[0][0] < matrizA[0][1]) {
        min = matrizA[0][0];
      } else {
        min = matrizA[0][1];
      }

      if (matrizA[0][1] < matrizA[0][2]) {
        min = matrizA[0][1];
      } else {
        min = matrizA[0][2];
      }
    }
  }
  printf("---------Estudiantes----------\n");
  printf("\nEstudiante A  -> %d\t%d\t%d", res[0][0], res[0][1], res[0][2]);
  printf("\n Promedio -> %.2f", (float)suma / 3);
  printf("\nNota mas alta -> %d\n", maximaNota);
  printf("\nNota mas baja -> %d", min);

  printf("\n---------Materias---------\n");
}
