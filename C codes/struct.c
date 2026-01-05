#include <stdio.h>

// create struct
struct my_struct{
    int n;
    char* name;
};

// create struct and typedef
typedef struct{
    int n;
    char* name;
} your_struct; // the renamed_struct

int main(void){
    // initialize instance
    struct my_struct instance_1;
    instance_1.n=28;
    instance_1.name="Brenden";
    printf("age=%d, name=%s\n", instance_1.n,instance_1.name);

    // initialize instance (version 2)
    struct my_struct instance_2={4, "Ozzy"};
    printf("age=%d, name=%s\n", instance_2.n,instance_2.name);

    // typedef allows you to initialize without specifying as a 'struct'
    typedef struct my_struct renamed_struct;
    // initialize instance
    renamed_struct instance_3={.name="Sue", .n=83};
    printf("age=%d, name=%s\n", instance_3.n,instance_3.name);

    your_struct instance_4={28, "Me"};
    printf("age=%d, name=%s\n", instance_4.n,instance_4.name);
}