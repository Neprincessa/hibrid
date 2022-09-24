#include "input.h"
#include <string.h>
#include <stdlib.h>

int readMatrix(int size, int line_size, FILE *fd, float ***matrix)
{
    int count = size / line_size;
    float **res_matrix = (float **)malloc(sizeof(float *) * count);
    for (int i = 0; i < count; i++) {
        float *line = (float *)calloc(line_size, sizeof(float));
        size_t read_size = fread(line, sizeof(float), line_size, fd);
        if (read_size != line_size) {
            free(line);
            free(res_matrix);
            return 1;
        }
        res_matrix[i] = (float *)malloc(sizeof(float) * line_size);
        if (!memcpy(res_matrix[i], line, line_size)) {
            free(line);
            free(res_matrix);
            return 1;
        }
        free(line);
    }
    *matrix = res_matrix;
    return 0;
}

int writeMatrix(int size, int line_size, FILE *fd, float **matrix)
{
    int count = size / line_size;
    for (int i = 0; i < count; i++) {
        size_t write_size = fwrite(matrix[i], sizeof(float), line_size, fd);
        if (write_size != line_size) {
            return 1;
        }
    }
    return 0;
}