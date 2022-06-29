/*
 * main.c
 *
 *  Created on: 26/7/2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

int main (){
	int a;
	printf("enter an integer:");
	fflush(stdin), fflush(stdout);
	scanf("%d", &a);
	printf("you entered: %d", a);
}


