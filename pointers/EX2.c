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
	char alphabit[26];
	char* ptr;
	int i = 0;
	ptr = alphabit;
	printf("the alphabit are : \n");
	for(i = 0;i < 26;i++)
	{
		*ptr = i + 'A';
		ptr++;
	}
	ptr = alphabit;
	for(i = 0;i < 26;i++)
	{
		printf("%c ",*ptr);
		ptr++;
	}
	return 0;
}
