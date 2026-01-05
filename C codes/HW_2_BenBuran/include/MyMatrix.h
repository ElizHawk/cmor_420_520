#ifndef MYMATRIX_H
#define MYMATRIX_H

struct MyMatrix {
    int m;
    int n;
    double **data;
};

// Declare functions implemented in MyMatrix.c
void construct_MyMatrix(struct MyMatrix *A);
void free_MyMatrix(struct MyMatrix *A);
void MyMatrix_zeroes(struct MyMatrix *input_ptr);
int matmul(struct MyMatrix *C, const struct MyMatrix *A, const struct MyMatrix *B);
int sum_column(const struct MyMatrix *C, const int k, double *result);
int reshape(int new_m, int new_n, struct MyMatrix *A);
#endif