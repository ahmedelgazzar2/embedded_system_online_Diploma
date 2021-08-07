/*
 * main.c
 *
 *  Created on: 5/8/2021
 *      Author: ELgazzar
 */

#include <stdio.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	float a[2][2], b[2][2], c[2][2];
	int i,j;

	for (i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf(" enter a %d %d:", i+1, j+1);
			scanf("%f",&a[i][j]);
		}
	}

	for (i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf(" enter b %d %d:", i+1, j+1);
			scanf("%f",&b[i][j]);
		}
	}

	for (i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("sum of matrix is : \n");
	for (i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%2f \t",c[i][j]);
			if(j == 1)
				printf("\n");
		}
	}
	return 0;
}


