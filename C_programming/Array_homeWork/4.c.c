/*
 * main.c
 *
 *  Created on: 7/8/2021
 *      Author: ahmed elgazzar
 */

#include "stdio.h"
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int arr[100] ,number, search, i ;
	printf("enter the no of element:");
	scanf("%d",&number);
	printf("enter the  elements: \n");
	for(i = 0; i < number; i++){
		scanf("\n%d", &arr[i]);
	}
	printf("enter the  element to be searched:");
	scanf("%d",&search);
	for(i = 0; i < number ; i++){
		if(arr[i] == search){
			printf("\n number found in location : %d", i+1);
			break;
		}
		else if(arr[i] != search && i == (number-1))
			printf("\n not found");

	}
	return 0;
}
