#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_matrix(int n, FILE *file) {
    // Guardar el tamaño de la matriz
    fwrite(&n, sizeof(int), 1, file);

    // Generar valores aleatorios para llenar la matriz
    int total_elements = n * n * n;
    int *matrix = (int *)malloc(total_elements * sizeof(int));

    for (int i = 0; i < total_elements; i++) {
        matrix[i] = rand() % 100;  // Valores aleatorios entre 0 y 99
    }

    // Escribir la matriz al archivo binario
    fwrite(matrix, sizeof(int), total_elements, file);

    free(matrix);
}

void generate_identity_matrix(int n, FILE *file) {
    // Guardar el tamaño de la matriz
    fwrite(&n, sizeof(int), 1, file);

    // Generar una matriz identidad 3D
    int total_elements = n * n * n;
    int *matrix = (int *)malloc(total_elements * sizeof(int));

    // Inicializar la matriz con ceros
    for (int i = 0; i < total_elements; i++) {
        matrix[i] = 0;
    }

    // Poner 1 en la diagonal principal
    for (int i = 0; i < n; i++) {
        matrix[i * n * n + i * n + i] = 1;
    }

    // Escribir la matriz al archivo binario
    fwrite(matrix, sizeof(int), total_elements, file);

    free(matrix);
}

int main() {
    srand(time(NULL));  // Inicializar la semilla para números aleatorios

    // Crear y abrir los archivos para las matrices
    FILE *file1 = fopen("matrix1.bin", "wb");
    if (file1 == NULL) {
        printf("Error opening file for matrix1\n");
        return 1;
    }

    FILE *file2 = fopen("matrix2.bin", "wb");
    if (file2 == NULL) {
        printf("Error opening file for matrix2\n");
        fclose(file1);
        return 1;
    }

    // Definir el tamaño de la matriz (puedes cambiar el tamaño para probar otros casos)
    int n = 5;  // Cambiar a 101 para probar el tamaño mayor que 100

    // Generar una matriz aleatoria y escribirla en matrix1.bin
    generate_random_matrix(n, file1);

    // Generar una matriz identidad y escribirla en matrix2.bin
    generate_identity_matrix(n, file2);

    // Cerrar los archivos
    fclose(file1);
    fclose(file2);

    printf("Matrices generadas y guardadas en matrix1.bin y matrix2.bin\n");
    return 0;
}

