#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *resultbin;
    int n;

    // Abrir result.bin para lectura
    resultbin = fopen("result.bin", "rb");
    if (!resultbin) {
        printf("Error abriendo result.bin\n");
        return 1;
    }

    // Leer la dimensión de la matriz resultante
    fread(&n, sizeof(int), 1, resultbin);

    // Leer los elementos de la matriz resultante
    int total_elements = n * n * n;
    int *result_matrix = (int*)malloc(total_elements * sizeof(int));
    fread(result_matrix, sizeof(int), total_elements, resultbin);

    fclose(resultbin);

    // Imprimir los resultados
    printf("Result matrix dimension: %d\n", n);
    for (int i = 0; i < total_elements; i++) {
        printf("Element %d is %d\n", i, result_matrix[i]);
    }

    // Liberar memoria
    free(result_matrix);

    return 0;
}

