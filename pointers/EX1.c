/*
 * main.c
 *
 *  Created on: 21 Feb 2022
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int* ab;
	int m = 29;
	printf("address of m : 0x%p\n",&m);
	printf("value of m : %d\n",m);
	ab = &m;
	printf("\n");
	printf("NOW ab is assigned as address of m...\n");
	printf("address of pointer ab : 0x%p\n",ab);
	printf("value of ab : %d\n",*ab);
	m = 34;
	printf("\n");
	printf("NOW the value of m assigned as 34...\n");
	printf("address of pointer ab : 0x%p\n",ab);
	printf("value of ab : %d\n",*ab);
	*ab = 7;
	printf("\n");
	printf("NOW the pointer value assigned as 7...\n");
	printf("address of m : 0x%p\n",ab);
	printf("value of m : %d\n",*ab);
	return 0;
}
