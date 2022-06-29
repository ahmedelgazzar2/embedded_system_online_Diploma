/*
 * main.c
 *
 *  Created on: 7/8/2021
 *      Author: ahmed elgazzar
 */

#include "stdio.h"
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	char str[100];
	int i, cnt = 0;
	printf("enter an string :");
	gets(str);
	for(i = 0; str[i] != '\0'; i++){
		cnt++;
	}
	printf("length of the string = %d", cnt-1);
	return 0;
}
