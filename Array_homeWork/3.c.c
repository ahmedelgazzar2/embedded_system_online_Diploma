/*
 * main.c
 *
 *  Created on: 6/8/2021
 *      Author: ahmed elgazzar
 */
#include "stdio.h"
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	int array[10][10] , transpose [10][10], row, column, i, j;
	printf("enter the row:");
	scanf("%d",&row);
	printf("enter the column:");
	scanf("%d",&column);
	for(i = 0; i < row; i++){
		for(j = 0;j < column; j++){
			printf("enter the element of a%d%d :", i ,j);
			scanf("%d", &array[i][j]);
		}
	}
	for(i = 0; i < row; i++){
		for(j = 0;j < column; j++){
			transpose[i][j] = array[j][i];
		}
	}
	printf("the transpose is : \n");
	for(i = 0; i < row; i++){
		for(j = 0;j < column; j++){
			printf("%d",transpose[i][j]);
			printf("\t");
			if(j == (row-1))
				printf("\n");
		}
	}
	return 0;
}

