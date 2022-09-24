#include "input.h"
#include <stdlib.h>

float genFloat()
{
    return (float)rand() / (float)RAND_MAX;
}

float genCoord()
{
    return (float)rand();
}


int main(int argc, char **argv)
{
    int N = atoi(argv[1]); // размерность пространства
    int size = atoi(argv[2]); // размер в мегабайтах матрицы
    int real_size = size * 1024 * 1024 / sizeof(float); 
    int vector_count = real_size / N; // количество вектор-столбцов для задания точек
    int matrix_count = N * N; // размерность матрицы поворота
    
    FILE *matrix_file = fopen("matrix.txt", "wb");
    FILE *vector_file = fopen("vector.txt", "wb");

    float **vectors = (float **)malloc(sizeof(float *) * vector_count);
    for (int i = 0; i < vector_count; i++) {
        vectors[i] = (float *)malloc(sizeof(float) * N);
        float *line = vectors[i];
        for (int k = 0; k < N; k++) {
            line[k] = genCoord();
        }
    }

    if (writeMatrix(real_size, N, vector_file, vectors)) {
        perror("Failed to write result vectors");
    }
    fclose(vector_file);

    float **matrix = (float **)malloc(sizeof(float *) * matrix_count);
    for (int i = 0; i < matrix_count; i++) {
        matrix[i] = (float *)malloc(sizeof(float) * N);
        float *line = matrix[i];
        for (int k = 0; k < N; k++) {
            line[k] = genFloat();
        }
    }

    if (writeMatrix(N * N * sizeof(float), N, matrix_file, matrix)) {
        perror("Failed to write result matrix");
    }
    fclose(matrix_file);

    for (int i = 0; i < vector_count; i++) {
        free(vectors[i]);
    }
    free(vectors);

    for (int i = 0; i < matrix_count; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}