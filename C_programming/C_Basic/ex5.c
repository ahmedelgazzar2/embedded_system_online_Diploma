/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#include <stdio.h>

int main(){
	char c;
	printf("Enter a character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&c);
	fflush(stdin);
	fflush(stdout);
	printf("ASCII value of %c = %d",c,c);
	fflush(stdin);
	fflush(stdout);
	return 0;
}

