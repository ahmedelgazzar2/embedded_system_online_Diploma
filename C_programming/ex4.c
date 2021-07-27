/*
 * main.c
 *
 *  Created on: 26/7/2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int main(){
	float a, b, product;
	printf(" enter 2 numbers :");
	fflush(stdin), fflush(stdout);
	scanf("%f", &a);
	scanf("%f", &b);
	product = a * b;
	printf("the product is: %f", product);

}

