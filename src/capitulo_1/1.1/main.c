#include<stdlib.h>
#include<stdio.h>
#include "reciproco.hpp"
int main(int agrc,char** args){
	int i=atoi(args[1]);
	printf("El reciproco de %d es %f",i,reciproco(i));
	return 0;
}

