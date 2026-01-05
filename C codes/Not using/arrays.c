#include <stdio.h>

int main(void){
    int array_2[2]={0,1};
    int array_10[10]={0,1,2,3,4,5,6,7,8,9};

    int array_double[2][3]={ {0,1,2}, {3,4,5}};
    int array_zero[2][2]={{1}};
    
    
    printf("the first array is\n %d %d\n", array_2[0], array_2[1]);
    printf("the second array is\n");
    for(int i=0;i<10;++i)
        printf(" %d", array_10[i]);
    printf("\n");

    printf("the third array is\n");
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j)
            printf(" %d", array_double[i][j]);
        printf("\n");
    }
    
}