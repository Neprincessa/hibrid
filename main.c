#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "process.h"

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    int size = atoi(argv[2]);
    int real_size = size * 1024 * 1024 / sizeof(float);
    int M = real_size / N;
    const char *vector_name = argv[3];
    const char *matrix_name = argv[4];

    FILE *vector_file = fopen(vector_name, "rb");
    FILE *matrix_file = fopen(matrix_name, "rb");

    float **vector_mn = NULL;
    int vector_size = M * N;
    float **matrix_nn = NULL;
    int matrix_size = N * N;

    if (readMatrix(vector_size, N, vector_file, &vector_mn)) {
        perror("Failed to read vectors");
    }
    fclose(vector_file);

    if (readMatrix(matrix_size, N, matrix_file, &matrix_nn)) {
        perror("Failed to read matrix");
    }
    fclose(matrix_file);

    float **result_vectors = (float **)malloc(sizeof(float *) * M);
    for (int k = 0; k < M; k++) {
        result_vectors[k] = (float *)malloc(sizeof(float) * N);
    }

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    process(N, M, vector_mn, matrix_nn, result_vectors);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f sec elapsed\n", cpu_time_used);

    FILE *out_file = fopen("result.txt", "wb");
    if (writeMatrix(vector_size, N, out_file, result_vectors)) {
        perror("Failed to write result vectors");
    }
    fclose(out_file);
    return 0;
}