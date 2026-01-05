#include <stdio.h>

// argc : c language variable for 'argument count'
// argv : c language variable for 'argument vector'
int main(int argc, char** argv){
    printf("You have %d values available.\n", argc);
    printf("The first is: %s\n", *argv); //default *argv acesses *argv[0]
    printf("The second is: %s\n", *(argv+1));// acesses *argv[1]
}