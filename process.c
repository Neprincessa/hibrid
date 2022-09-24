#include "process.h"
#include <omp.h>

void process(int N, int M, float **vector_mn, float **matrix_nn, float **result_vectors)
{
    omp_set_dynamic(0);      // запретить библиотеке openmp менять число потоков во время исполнения
    omp_set_num_threads(3);
    
    int k = 0;
    #pragma omp parallel for shared(vector_mn, matrix_nn) private(k)
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