#include <stdio.h>

// Defined and declared
float x;

// output int input void (none)
int main(void){
	// Defined, declared, and initialized
	int y=1;
	printf(" y=%d\n",y);
	// Declared
	extern float x;
	// Initialized
	x=10.1;
	printf("x=%f\n",x);

	// can pass float an int or double (it will convert)
	x=10;
	printf("x=%f\n",x);
	// cannot pass an int a float 
	y=1.01;
	printf("y=%d\n",y);

	for (int i = 10; i > 0; i-=2)
	{
		printf("%d",i);
	}
	
}
