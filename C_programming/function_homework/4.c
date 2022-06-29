/*
 * main.c
 *
 *  Created on: 24 Dec 2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int get_power(int num,int pow);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int number,power;
	printf("enter a base num :");
	scanf("%d",&number);
	printf("enter a power num (positive integer) :");
	scanf("%d",&power);
	printf("%d ^ %d = %d",number,power,get_power(number,power));
	return 0;
}

int get_power(int num,int pow)
{
	if(pow != 0)
	{
		return (num*get_power(num,--pow));
	}
	else
	{
		return 1;
	}
}
