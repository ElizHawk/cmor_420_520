#include "MyMatrix.h"
#include <stdlib.h> // memory management related functions
#include <stdio.h> // print statements
#include <stdbool.h> // bools
#include <math.h> // NAN for error returns

// The MyMatrix struct declaration is already included in MyMatrix.h, but here is the format:
// struct MyMatrix {
//     int m;
//     int n;
//     double ** data;
// };

void construct_MyMatrix(struct MyMatrix *input_ptr){

    // NOTE: Structure of function should expect that m and n are already initialized within MyMatrix
    if(input_ptr == NULL){
        printf("Error: construct_MyMatrix was fed a NULL pointer.\n");
        return;
    }
    int m = input_ptr->m;
    int n = input_ptr->n;
    if(m<= 0 || n<=0){
        printf("Error: MyMatrix passed into construct_MyMatrix has non-positive dimensions.\n");
    }
    input_ptr->data = malloc(sizeof(double*) * m); //C implicitly casts void* to relevant data type (double*)
    input_ptr->data[0] = malloc(sizeof(double) * m * n);  //C implicitly casts void* to relevant data type (double*)
    for (int i = 1; i<m; ++i){
        input_ptr->data[i] = input_ptr->data[0] + i * n;
    }
}

void MyMatrix_zeroes(struct MyMatrix *input_ptr){

    // NOTE: Structure of function should expect that m and n are already initialized within MyMatrix
    if(input_ptr == NULL){
        printf("Error: construct_MyMatrix was fed a NULL pointer.\n");
        return;
    }
    int m = input_ptr->m;
    int n = input_ptr->n;
    if(m<= 0 || n<=0){
        printf("Error: MyMatrix passed into construct_MyMatrix has non-positive dimensions.\n");
    }
    input_ptr->data = malloc(sizeof(double*) * m); // C implicitly casts void* to relevant data type (double*)
    input_ptr->data[0] = calloc(m * n, sizeof(double));  // now initializes all entries to zeroes.
    for (int i = 1; i<m; ++i){
        input_ptr->data[i] = input_ptr->data[0] + i * n;
    }
}

void free_MyMatrix(struct MyMatrix *A) {
    if(A == NULL){
        printf("Warning: free_MyMatrix was fed a NULL pointer.\n");
        return;
    }
    if (A->data == NULL) {
        printf("Warning: free_MyMatrix was called on a matrix with NULL data (likely already freed).\n");
        return;
    }

    // Note: at this point, A->data != NULL
    if(A->data[0] != NULL){
        free(A->data[0]);
    }
    free(A->data);
    A->data = NULL; // prevents dangling pointer
}

int matmul(struct MyMatrix *C, const struct MyMatrix *A, const struct MyMatrix *B) {

    /*
    The matrix C will have its values filled in to be the values obtained by performing the matrix multiplication C = AB. Note that C does not need to already have values, but does need to be initilaized with a block of contiguous memory that C.data already points to.
    */

    if(C == NULL || A == NULL || B == NULL) {
        printf("Error: matmul received NULL matrix pointer.\n");
        return 1;
    }   
    if(C->data == NULL || A->data == NULL || B->data == NULL){
        printf("Error: matmul was given a matrix with NULL data.");
        return 1;
    }


    // suppose C = m x n. Then need A = m x k and B = k x n
    // Store relevant dimension values for checking
    int C_m = C->m;
    int C_n = C->n;
    int A_m = A->m;
    int A_n = A->n;
    int B_m = B->m;
    int B_n = B->n;

    bool error = (C_m != A_m) || (C_n != B_n) || (A_n != B_m);
    if(error){
        printf("Error: inputted matrix sizes did not align\n");
        return 1;
    }

    double **A_data = A->data;
    double **B_data = B->data;
    double **C_data = C->data;

    for(int i = 0; i<C_m; ++i){
        for(int j = 0; j<C_n; ++j){
            double temp_sum = 0.0;
            for(int k=0; k<A_n; ++k){
                temp_sum += A_data[i][k] * B_data[k][j];
            }
            C_data[i][j] = temp_sum;
        }
    }

    return 0; 

}

int sum_column(const struct MyMatrix *C, const int k, double *result){

    if(C == NULL) {
        printf("Error: sum_column received NULL matrix pointer.\n");
        *result = NAN;
        return 1;
    }   
    if(C->data == NULL){
        printf("Error: matrix inputted into sum_column was pointed to NULL data.");
        *result = NAN;
        return 1;
    }

    if(k < 0 || k >= C->n){
        printf("Error: column index %d is out of bounds (n = %d)\n", k, C->n);
        return 0.0;
    }
    double **C_data = C->data;
    double sum = 0;
    for(int i=0; i<C->m; ++i){
        sum += C_data[i][k];
    }
    *result = sum;
    return 0;
}

int reshape(int new_m, int new_n, struct MyMatrix *A){

    int old_m = A->m;
    int old_n = A->n;
    if(new_m * new_n != old_m * old_n){
        printf("The inputted reshape dimensions are incompatible with the inputted matrix.");
        return 1;
    }

    double* mem_start_ptr = A->data[0]; // keep pointer to beginning of data
    A->data = malloc(sizeof(double*) * new_m); // re-shape the array of pointers to the new dimension
    for(int i=0; i<new_m; ++i){
        A->data[i] = mem_start_ptr + i*new_n;
    }

    A->m = new_m;
    A->n = new_n;

    return 0;
}

// OLD Main function for debugging; requires compilation without any other files except MyMatrix.h
// int main(){

//     struct MyMatrix A;
//     A.m = 2;
//     A.n = 3;
//     construct_MyMatrix(&A);
//     for(int i = 0; i < A.m; i++){
//         if(A.data[i] == NULL){
//             printf("Error: row %d was not initialized properly.\n", i);
//         }
//     }
//     free_MyMatrix(&A);

//     return 0;

// }