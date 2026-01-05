#include <stdio.h>

int main(int argc, char** argv){
    if (argc==1){
        printf("no arguments\n");
    }
    else if (argc==2){
        printf("one argument\n");
    }
    else{
        printf("more than one argument\n");
    }
}