#ifndef _INPUT_H
#define _INPUT_H

#include <stdio.h>

int readMatrix(int size, int line_size, FILE *fd, float ***matrix);

int writeMatrix(int size, int line_size, FILE *fd, float **matrix);

#endif // _INPUT_H