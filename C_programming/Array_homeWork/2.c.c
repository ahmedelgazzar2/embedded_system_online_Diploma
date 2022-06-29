/*
 * main.c
 *
 *  Created on: 6/8/2021
 *      Author: ahmed elgazzar
 */
#include "stdio.h"

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int n,i ,sum = 0, Arr[100];
	float avr;
	//number should be from 0 to 100.
	printf("please enter the number of data: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("enter the %d number :", i+1);
		scanf("%d",&Arr[i]);
		sum += Arr[i];
	}
	avr = sum / n;
	printf("Average = %f", avr);
	return 0;
}

