/*
 * main.c
 *
 *  Created on: 24 Dec 2021
 *      Author: Ahmed ELgazzar
 */

#include "stdio.h"

void reversing(char sentence[],int n);

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	char string[100];
	printf("enter a sentence :");
	gets(string);
	printf("sentence after reversing is :");
	reversing(string,100);
	return 0;
}

void reversing(char sentence[],int n)
{
	int i,j;
	for(i = 0;i < n;i++)
	{
		if(sentence[i] == '\0')
			break;
	}
	for(j = i-1; j >= 0; j--)
	{
		printf("%c",sentence[j]);
	}
}
