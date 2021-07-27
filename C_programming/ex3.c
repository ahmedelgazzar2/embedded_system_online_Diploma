/*
 * main.c
 *
 *  Created on: 26/7/2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int main(){
	int a, b, sum;
	printf(" enter 2 numbers :");
	fflush(stdin), fflush(stdout);
	scanf("%d", &a);
	scanf("%d", &b);
	sum = a + b;
	printf("the sum is: %d", sum);

}

