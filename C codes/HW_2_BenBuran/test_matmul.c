#include "MyMatrix.h"
#include <stdlib.h> // memory management related functions
#include <stdio.h> // print statements
#include <math.h> // fabs function

int main(){
    struct MyMatrix A;
    A.m = 3;
    A.n = 4;
    construct_MyMatrix(&A);
    double **A_data = A.data;
    int count = 1;
    for(int i=0;i<A.m;++i){
        for(int j=0; j<A.n; ++j){
            A_data[i][j] = count;
            // printf("%d\n", count); // debug print statement
            count +=1;
        }
    }

    // Initialize matrix B, which will just be a vector for simplicity
    struct MyMatrix B;
    B.m = 4;
    B.n = 3;
    construct_MyMatrix(&B);
    double **B_data = B.data;
    count = 1;
    for(int i=0; i<B.m; ++i){
        for(int j=0;j<B.n;++j){
            B_data[i][j] = count;
            count += 1;
        }
    }

    // Initialize C = AB
    struct MyMatrix C;
    C.m = 3;
    C.n = 3;
    construct_MyMatrix(&C);
    double **C_data = C.data;
    int status = matmul(&C,&A,&B);
    if(status==1){
        printf("There was an error in the matrix multiplication\n");
    }
    // // Print result
    // printf("C = A * B =\n");
    // for (int i=0; i<C.m; ++i) {
    //     for (int j=0; j<C.n; ++j) {
    //         printf("%.9f ", C_data[i][j]);
    //     }
    //     printf("\n");
    // }

    //Explicitly defined the expected output matrix 
    struct MyMatrix D;
    D.m=3;
    D.n=3;
    construct_MyMatrix(&D);
    double **D_data = D.data;
    D_data[0][0] = 70;
    D_data[0][1] = 80;
    D_data[0][2] = 90;
    D_data[1][0] = 158;
    D_data[1][1] = 184;
    D_data[1][2] = 210;
    D_data[2][0] = 246;
    D_data[2][1] = 288;
    D_data[2][2] = 330;
    

    //compute maximum absolute difference between C and D
    double max_diff = 0.0;
    for (int i=0; i<D.m; ++i){
        for (int j=0; j<D.n; ++j) {

            if(fabs(D_data[i][j] - C_data[i][j]) > max_diff){
                max_diff = fabs(D_data[i][j] - C_data[i][j]) > max_diff;
            }
        }
    }
    printf("The maximum absolute difference between the true matrix product and the computed matrix product is %.9f ", max_diff);
}