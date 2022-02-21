/*
 * main.c
 *
 *  Created on: 21 Feb 2022
 *      Author: Ahmed ELgazzar
 */

#include"stdio.h"

struct employee{
	char name[10];
	int id;
}employee1;
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);setvbuf(stderr, NULL, _IONBF, 0);
	struct employee employee1 = {"ahmed",1001},employee2 = {"magdy",1002},employee3 = {"kerolos",1003};
	struct employee *employees[] = {&employee1,&employee2,&employee3};
	struct employee (*(*ptr)[3]) = &employees;
	printf("employee -1- name : %s\n",(**ptr)->name);
	printf("enter employee -1- id : %d\n",(**ptr)->id);
	return 0;
}
