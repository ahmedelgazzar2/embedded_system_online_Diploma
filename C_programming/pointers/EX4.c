/*
 * main.c
 *
 *  Created on: 21 Feb 2022
 *      Author: Ahmed ELgazzar
 */

#include"stdio.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int arr[15],max,i;
	int* ptr = arr;
	printf("enter the element of array max(15) : ");
	scanf("%d",&max);
	for(i = 0;i < max;i++)
	{
		printf("element-%d- is :",i+1);
		scanf("%d",ptr);
		ptr++;
	}
	ptr--;
	printf("array in reverse is.......\n");
	for(i = max-1;i >= 0;i--)
	{
		printf("element -%d- : %d \n",i+1,*ptr);
		ptr--;
	}
	return 0;
}
