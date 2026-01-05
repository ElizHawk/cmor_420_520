#include <stdio.h>
#include "my_struct.h"
#include "unpack.h"

int main(void){
    my_struct instance={12};
    printf("n=%d\n", unpack(instance));
}