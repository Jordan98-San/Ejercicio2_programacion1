#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b);
int min(int a, int b);

int maxima_Nota(int a, int b, int c);
int minima_Nota(int a, int b, int c);

int main() {
  srand(time(NULL));
  // Variables
  int i, j;
  int maximaNota = 0;
  int minimaNota = 0;

  int matrizA[5][3] = {0};

  /* Entrada de datos */
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 3; j++) {
      matrizA[i][j] = rand() % 10 + 1;
      if (matrizA[i][j] < 0 || matrizA[i][j] > 10) {
        printf("[!] Valores dentro de la matriz superan el rango permitido "
               "(0-10)");

        matrizA[i][j] = rand() % 10 + 1;
      }
    }
  }

  for (i = 0; i < 5; i++) {
    printf("\n");
    for (j = 0; j < 3; j++) {
      printf("%d\t", matrizA[i][j]);
    }
  }

  for (i = 0; i < 5; i++) {
    printf("\n");
    int suma = 0;
    maximaNota = maxima_Nota(matrizA[i][0], matrizA[i][1], matrizA[i][2]);
    minimaNota = minima_Nota(matrizA[i][0], matrizA[i][1], matrizA[i][2]);

    for (j = 0; j < 3; j++) {
      suma += matrizA[i][j];
    }
    float Promedio = (float)suma / 3;
    printf("      ---------Estudiantes [%d]----------\n", i + 1);
    printf("      |Materia-1 | Materia-2 | Materia-3\n");
    printf("Notas |    %d    |    %d    |    %d\n", matrizA[i][0],
           matrizA[i][1], matrizA[i][2]);
    printf("\n[*] Promedio -> %.2f", (float)Promedio);
    printf("\n[+] Nota mas alta -> %d", maximaNota);
    printf("\n[-] Nota mas baja -> %d\n", minimaNota);
  }

  // Calculo de las Columna -> Materias
  float promedioAsignatura = 0;
  int nota;
  for (int j = 0; j < 3; j++) {
    int suma = 0;
    int maxNotaMateria = matrizA[0][j];
    int minNotaMateria = matrizA[0][j];
    int Conaprobados = 0;
    int Conreprobados = 0;

    for (int i = 0; i < 5; i++) {
      nota = matrizA[i][j];
      suma += matrizA[i][j];

      maxNotaMateria = max(maxNotaMateria, matrizA[i][j]);
      minNotaMateria = min(minNotaMateria, matrizA[i][j]);
      promedioAsignatura = (float)suma / 5;
      if (nota >= 6) {
        Conaprobados++;
      } else {
        Conreprobados++;
      }
    }
    printf("\n---------Asignatura [%d]---------\n", j + 1);
    printf("\n[*] Promedio -> %.2f\n", promedioAsignatura);
    printf("\n[+] Maxima nota -> %d", maxNotaMateria);
    printf("\n[-] Minima nota -> %d\n", minNotaMateria);
    printf("\n[+] Aprobados -> %d", Conaprobados);
    printf("\n[-] Reprobados -> %d", Conreprobados);
  }
}

int max(int a, int b) {
  int notaMaxima = a;
  if (b > notaMaxima) {
    return b;
  } else {
    return notaMaxima;
  }
}

int maxima_Nota(int a, int b, int c) { return max(max(a, b), c); }

int min(int a, int b) {
  int notaMinima = a;
  if (b < notaMinima) {
    return b;
  } else {
    return notaMinima;
  }
}

int minima_Nota(int a, int b, int c) { return min(min(a, b), c); }
