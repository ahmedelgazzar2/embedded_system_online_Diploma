/*
 * main.c
 *
 *  Created on: 24 Dec 2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int factorial(int num);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int number;
	printf("enter a positive integer number : ");
	scanf("%d",&number);
	printf("Factorial of %d is = %d ",number,factorial(number));
	return 0;
}
int factorial(int num)
{
	if(num != 1)
	{
	return num*factorial(num-1);
	}
}

