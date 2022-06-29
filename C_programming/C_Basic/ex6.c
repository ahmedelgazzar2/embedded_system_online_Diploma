//c programing to swap 2 values
#include <stdio.h>
int main(){
	float a, b, temp;
	printf("Enter value of a: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	fflush(stdin);fflush(stdout);
	printf("Enter value of b: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	fflush(stdin);fflush(stdout);
	temp = a;
	a = b;
	b = temp;
	printf("after swapping, value of a = %f\n", a);
	fflush(stdin);fflush(stdout);
	printf("after swapping, value of b = %f", b);
	fflush(stdin);fflush(stdout);
	return 0;
}
