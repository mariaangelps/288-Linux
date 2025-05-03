#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

//Maria Angel Palacios Sarmiento
#define LIMIT 1000  // max value we expect in the data

int main(int arg_count, char *arg_list[]) {
    int my_rank, total_procs;
    int full_size, chunk_size;
    unsigned int *full_array = NULL, *my_chunk = NULL;
    int *my_histogram = NULL, *final_histogram = NULL;
    unsigned long long my_total = 0, overall_total = 0;
    char file_path[256];

    // Check args: need length, process count, and file
    if (arg_count != 4) {
        fprintf(stderr, "Usage: %s <array_len> <proc_count> <file_name>\n", arg_list[0]);
        return EXIT_FAILURE;
    }

    int array_len = strtol(arg_list[1], NULL, 10);
    int expected_procs = strtol(arg_list[2], NULL, 10);
    snprintf(file_path, sizeof(file_path), "%s", arg_list[3]);

    // Start MPI party
    MPI_Init(&arg_count, &arg_list);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &total_procs);

    // Make sure we have the number of procs we were told to use
    if (total_procs != expected_procs) {
        if (my_rank == 0) {
            fprintf(stderr, "Mismatch: running with %d processes but expected %d\n", total_procs, expected_procs);
        }
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Only rank 0 handles file input
    if (my_rank == 0) {
        FILE *input = fopen(file_path, "rb");
        if (!input) {
            perror("Couldn't open input file");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        full_array = malloc(array_len * sizeof(unsigned int));
        if (!full_array) {
            perror("Memory allocation failed for full_array");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        fread(full_array, sizeof(unsigned int), array_len, input);
        fclose(input);

        full_size = array_len;
    }

    // Share the array length with everyone
    MPI_Bcast(&full_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Slice the data
    chunk_size = full_size / total_procs;
    my_chunk = malloc(chunk_size * sizeof(unsigned int));
    if (!my_chunk) {
        perror("Couldn't allocate memory for my_chunk");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Send chunks out to each process
    MPI_Scatter(full_array, chunk_size, MPI_UNSIGNED, my_chunk, chunk_size, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

    // Allocate space to count values locally
    my_histogram = calloc(LIMIT, sizeof(int));
    if (!my_histogram) {
        perror("Failed to allocate my_histogram");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Count and sum the data I got
    for (int i = 0; i < chunk_size; i++) {
        my_histogram[my_chunk[i]]++;
        my_total += my_chunk[i];
    }

    if (my_rank == 0) {
        final_histogram = calloc(LIMIT, sizeof(int));
        if (!final_histogram) {
            perror("Memory allocation failed for final_histogram");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    MPI_Reduce(my_histogram, final_histogram, LIMIT, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&my_total, &overall_total, 1, MPI_UNSIGNED_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        printf("Overall sum of array values: %llu\n", overall_total);

        // Rebuild sorted array
        int pos = 0;
        for (int val = 0; val < LIMIT; val++) {
            for (int count = 0; count < final_histogram[val]; count++) {
                full_array[pos++] = val;
            }
        }

        // Save sorted data to the file
        FILE *output = fopen(file_path, "wb");
        if (!output) {
            perror("Couldn't open file for writing");
        } else {
            fwrite(full_array, sizeof(unsigned int), full_size, output);
            fclose(output);
        }

        free(final_histogram);
        free(full_array);
    }

    free(my_chunk);
    free(my_histogram);

    MPI_Finalize();
    return 0;
}