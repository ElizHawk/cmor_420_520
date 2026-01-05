#include <stdio.h>
#include <stdlib.h>

#include "HW_1.h"

double** construct_MyMatrix(int rows, int columns){
    double ** data = (double**) malloc(rows * sizeof(double*));
    data[0] = (double*) malloc(rows * columns * sizeof(double));
    for (int i = 1; i < rows; ++i) {
        data[i] = data[0] + columns * i;
    }
    return data;
}

void set_data(MyMatrix Mat){
    for (int i = 0; i < Mat.rows; ++i) {
        for (int j = 0; j < Mat.columns; j++) {
            Mat.data[i][j] = (double) (i * Mat.columns + j+1);
            printf("%.1f ",Mat.data[i][j]);
    }
    printf("\n");
    }
    printf("\n");
}

void free_MyMatrix(double** data){
    free(data[0]);
    free(data);
}

void matmul(MyMatrix* C, const MyMatrix A, const MyMatrix B){
    (*C).rows = A.rows;
    (*C).columns = B.columns;
    (*C).data=construct_MyMatrix((*C).rows, (*C).columns);

    for (int i = 0; i < (*C).rows; ++i) {
        for (int j = 0; j < (*C).columns; j++) {
            (*C).data[i][j]= (double) 0;
            printf("%.1f ",(*C).data[i][j]);
    }
    printf("\n");
    }
    printf("\n");

    for (int i = 0; i < (*C).rows; ++i) {
        for (int j = 0; j < (*C).columns; ++j) {
            for (int k=0; k < A.columns; ++k){
                (*C).data[i][j] += A.data[i][k]* B.data[k][j];
            }
    }
    }

    for (int i = 0; i < (*C).rows; ++i) {
        for (int j = 0; j < (*C).columns; j++) {
            printf("%.1f ",(*C).data[i][j]);
    }
    printf("\n");
    }
    printf("\n");
}

void reshape(int new_rows, int new_columns, MyMatrix* Mat){
    MyMatrix store = (*Mat);

    (*Mat).rows=new_rows;
    (*Mat).columns=new_columns;

    (*Mat).data = (double**) realloc((*Mat).data, new_rows * sizeof(double*));
    (*Mat).data[0] = (double*) realloc((*Mat).data[0],new_rows * new_columns * sizeof(double));
    for (int i = 1; i < new_rows; ++i) {
        (*Mat).data[i] = (*Mat).data[0] + new_columns * i;
    }

    for (int i = 0; i < (*Mat).rows; ++i) {
        for (int j = 0; j < (*Mat).columns; j++) {
            printf("%.1f ",(*Mat).data[i][j]);
    }
    printf("\n");
    }
    printf("\n");
}

int main(void){
    MyMatrix A;
    A.rows = 3;
    A.columns = 4;
    A.data=construct_MyMatrix(A.rows, A.columns);
    set_data(A);

    MyMatrix B;
    B.rows = 4;
    B.columns = 3;
    B.data=construct_MyMatrix(B.rows, B.columns);
    set_data(B);

    MyMatrix C;
    matmul(&C, A, B);

    reshape(3,4,&B);
    
    free_MyMatrix(A.data);
    free_MyMatrix(B.data);
    free_MyMatrix(C.data);
}