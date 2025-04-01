#include <stdio.h>

int main() {
    FILE *file = fopen("result.bin", "rb");  // Abrir el archivo binario en modo lectura
    if (file == NULL) {
        printf("Error opening result.bin\n");
        return 1;
    }

    int dim;
    long elem;

    // Leer la dimensión de la matriz
    fread(&dim, sizeof(int), 1, file);
    printf("Matrix dimension from result.bin: %d\n", dim);

    // Leer y mostrar cada elemento de la matriz resultante
    for (int i = 0; i < dim * dim * dim; i++) {
        fread(&elem, sizeof(long), 1, file);
        printf("Element %d: %ld\n", i, elem);
    }

    fclose(file);
    return 0;
}

