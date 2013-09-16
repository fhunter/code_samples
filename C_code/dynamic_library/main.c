#include <stdio.h>
//Our library
#include <library.h>

int main(int argc, char** argv){
	int i;
	i = 4;
	printf("Square of %d = %d\n",i,square(i));
	printf("Cube of %d = %d\n",i,cube(i));
	return 0;
}
