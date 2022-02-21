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
	char alpha[20];
	char *ptr = alpha;
	int i = 0;
	printf("enter a string :");
	gets(alpha);
	while(*ptr != '\0')
	{
		ptr++;
		i++;
	}

	do{
		printf("%c",*ptr);
		ptr--;
		i--;
	}while(i != 0);

	return 0;
}
