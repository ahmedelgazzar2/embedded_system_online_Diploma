/*
 * main.c
 *
 *  Created on: 24 Dec 2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

void GetPrime_NUM(int num1,int num2);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int number1,number2;
	printf("please enter 2 numbers (intervals) = ");
	scanf("%d %d",&number1,&number2);
	printf("prime numbers between %d and %d are: ",number1,number2);
	GetPrime_NUM(number1,number2);
	return 0;
}
void GetPrime_NUM(int num1,int num2)
{
	int i,j,flag;
	for(i = num1+1; i < num2; i++)
	{
		flag = 0;
		for(j = 2; j < i/2; j++)
		{
			if(i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("%d  ",i);
		}
	}
}
