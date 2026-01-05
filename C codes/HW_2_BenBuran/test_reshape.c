#include "MyMatrix.h"
#include <stdlib.h> // memory management related functions
#include <stdio.h> // print statements

int main(void){

    int old_m = 3;
    int old_n = 4;

    struct MyMatrix A, C; // C will be an identical copy of A used to compare the results of the re-shaping
    A.m = old_m;
    A.n = old_n;
    construct_MyMatrix(&A);
    C.m = old_m;
    C.n = old_n;
    construct_MyMatrix(&C);
    double **A_data = A.data;
    double **C_data = C.data;
    int count = 1;
    for(int i=0;i<A.m;++i){
        for(int j=0; j<A.n; ++j){
            A_data[i][j] = count;
            C_data[i][j] = count;
            // printf("%d\n", count); // debug print
            count +=1;
        }
    }

    // debug code block
    printf("The matrix before reshaping is:\n");
    for(int i=0; i<old_m; ++i){
        for(int j=0; j<old_n; ++j){
            printf("%8.3f ", C.data[i][j]);
        }
        printf("\n");
    }

    int new_m = old_n;
    int new_n = old_m;
    reshape(new_m, new_n, &A);

    printf("The matrix after reshaping is:\n");
    for(int i=0; i<new_m; ++i){
        for(int j=0; j<new_n; ++j){
            printf("%8.3f ", A.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}