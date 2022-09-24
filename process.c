#include "process.h"

void process(int N, int M, float **vector_mn, float **matrix_nn, float **result_vectors)
{

    int k = 0;
    for ( k=0; k < M; k++) {
        float *vector = vector_mn[k];
        float *res_vector = result_vectors[k];
        for (int p = 0; p < N; p++) {
            float *matrix_line = matrix_nn[p];
            float res = 0;
            for (int b = 0; b < N; b++) {
                res += matrix_line[b] * vector[b];
            }
            res_vector[p] = res;
        }
    }
}