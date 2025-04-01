#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *resultbin;
    int n1, n2;

    // open  matrix1
    file1 = fopen("matrix1.bin", "rb");
    if (file1 == NULL) {
        printf("Error opening matrix1.bin\n");
        return 1;
    }

    // open matrix2
    file2 = fopen("matrix2.bin", "rb");
    if (file2 == NULL) {
        printf("Error opening matrix2.bin\n");
        fclose(file1);
        return 1;
    }

    // read matrices dimensions
    if (fread(&n1, sizeof(int), 1, file1) != 1) {
        perror("Error reading matrix1 dimension");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    if (fread(&n2, sizeof(int), 1, file2) != 1) {
        perror("Error reading matrix2 dimension");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    //when matrix 1 and 2 are diff
    if (n1 != n2) {
        printf("The size of the matrices are different\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    //storage prob
    int total_elements = n1 * n1 * n1;
    int *matrix1 = (int *)malloc(total_elements * sizeof(int));
    int *matrix2 = (int *)malloc(total_elements * sizeof(int));
    long long *result_matrix = (long long *)malloc(total_elements * sizeof(long long));

    if (!matrix1 || !matrix2 || !result_matrix) {
        printf("Error allocating memory.\n");
        fclose(file1);
        fclose(file2);
        free(matrix1);
        free(matrix2);
        free(result_matrix);
        return 1;
    }

    if (fread(matrix1, sizeof(int), total_elements, file1) != total_elements) {
        printf("Error reading matrix1.bin\n");
        fclose(file1);
        fclose(file2);
        free(matrix1);
        free(matrix2);
        free(result_matrix);
        return 1;
    }

    if (fread(matrix2, sizeof(int), total_elements, file2) != total_elements) {
        printf("Error reading matrix2.bin\n");
        fclose(file1);
        fclose(file2);
        free(matrix1);
        free(matrix2);
        free(result_matrix);
        return 1;
    }

    fclose(file1);
    fclose(file2);

    for (int i = 0; i < total_elements; i++) {
        result_matrix[i] = (long long)matrix1[i] * matrix2[i];
    }

    resultbin = fopen("result.bin", "wb");
    if (!resultbin) {
        printf("Error opening result.bin\n");
        free(matrix1);
        free(matrix2);
        free(result_matrix);
        return 1;
    }

    fwrite(&n1, sizeof(int), 1, resultbin);
    fwrite(result_matrix, sizeof(long long), total_elements, resultbin);
    fclose(resultbin);

    free(matrix1);
    free(matrix2);
    free(result_matrix);

    printf("Multiplication result saved in result.bin\n");

    //reopen file to read and show 
    resultbin = fopen("result.bin", "rb");
    if (!resultbin) {
        printf("Error opening result.bin for reading\n");
        return 1;
    }

    // read and show dimension
    fread(&n1, sizeof(int), 1, resultbin);
    printf("Matrix dimension from result.bin: %d\n", n1);

    // read and show each element 
    long long elem;
    for (int i = 0; i < total_elements; i++) {
        fread(&elem, sizeof(long long), 1, resultbin);
        printf("Element %d: %lld\n", i, elem);
    }

    fclose(resultbin);

    return 0;
}

