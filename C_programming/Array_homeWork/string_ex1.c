/*
 * main.c
 *
 *  Created on: 7/8/2021
 *      Author: ahmed elgazzar
 */

#include "stdio.h"
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	char str[100], c;
	int i, cnt = 0;
	printf("enter a string :");
	gets(str);
	printf("enter a character to find frequency: ");
	scanf("%c",&c);
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] == c)
			cnt++;
	}
	printf("the frequency of character %c is = %d", c, cnt);
	return 0;
}
