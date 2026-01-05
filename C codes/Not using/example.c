#include<stdio.h>

int main(void){
    char a = '5';
    char b = '4';

    int x = a-b;
    printf("%d\n",x);

    float y = 10.9;
    int z = y;
    int z_2 = (int) y;
    printf("z=%d, z_2=%d\n",z, z_2);
}