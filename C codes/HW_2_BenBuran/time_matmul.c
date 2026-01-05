#include "MyMatrix.h"
#include <stdlib.h> // memory management related functions
#include <stdio.h> // print statements
#include <time.h> // timing tools

int main(void){

    int n_min = 10; // minimum dimension of matrices A,B,C in experiment, inclusive
    int n_max = 128; // maximum dimension of matrices A,B,C in experiment, inclusive
    int num_n = n_max - n_min+1;
    int num_samples = 25;

    struct MyMatrix times_arr; // array that will store the runtimes for each dimension for each sample. Each row consists of times for multiplication of two nxn matrices for n=10,11,...,128. We will average over columns of this matrix afterwards to get average times for each n.
    times_arr.m = num_samples; // each row is a sample
    times_arr.n = num_n;
    MyMatrix_zeroes(&times_arr); // we will fill out the result of the experiment with for loops below
    double **times_arr_data = times_arr.data;

    struct MyMatrix averages_vec;
    averages_vec.m = 1;
    averages_vec.n = num_n;
    MyMatrix_zeroes(&averages_vec); // we will compute the averages in the experiment's outer for loop

    struct MyMatrix A; // matrix to be multiplied
    A.data = NULL;
    struct MyMatrix B; // matrix to be multiplied
    B.data = NULL;
    struct MyMatrix C; // product of A and B
    C.data = NULL;

    // conduct the experiment num_samples many times.
    for(int i=0; i<num_samples; ++i){
        // for each sample, we time matrix mult over each value of n
        for(int n=n_min; n<=n_max; ++n){

            int col = n-n_min;

            // free A,B,C if they are not currently free
            if(A.data != NULL){
                free_MyMatrix(&A);
            }
            if(B.data != NULL){
                free_MyMatrix(&B);
            }
            if(C.data != NULL){
                free_MyMatrix(&C);
            }

            // re-initialize A and B to have dimension n and zeroes (using MyMatrix_zeroes for the latter)
            A.m = n;
            A.n = n;
            B.m = n;
            B.n = n;
            C.m = n;
            C.n = n;
            MyMatrix_zeroes(&A);
            MyMatrix_zeroes(&B);
            construct_MyMatrix(&C);

            // start clock
            clock_t start = clock();
            // Perform matrix mult
            int status = matmul(&C, &A, &B);
            if(status==1){
                printf("There was an error in the matrix multiplication.\n");
                return 1;
            }
            // end clock
            clock_t end = clock();

            // Store time elapsed in times_arr
            times_arr_data[i][col] = ((double) (end - start)) / CLOCKS_PER_SEC;
            // printf("%.9f ", times_arr_data[i][col]); // debug print: 
        }
    }

    for(int col=0; col<num_n; ++col){
        double sum;
        int col_sum_status = sum_column(&times_arr, col, &sum);
        if(col_sum_status==1){
            printf("There was an error in the column summation.\n");
            return 1;
        }
        averages_vec.data[0][col] = sum/num_samples;
        printf("%.9f ", averages_vec.data[0][col]);
    }

    // struct MyMatrix dim_vec;
    // dim_vec.m = 119;
    // dim_vec.n = 1;
    // construct_MyMatrix(&dim_vec);
    // double **dim_vec_data = dim_vec.data;
    // int count = 0;
    // for(int i=0; i<dim_vec.m; ++i){
    //     dim_vec_data[i][1] = count + 10;
    //     printf("%d\n", count);
    //     count +=1;
    // }

    return 0;
}
