/*

 * ex6.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman_Kotb
 */
#include "stdio.h"
int main()
{
	float a,b,body;
	printf("Enter valueo of a:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter valueo of b:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
    body=b;
	b=a;
	a=body;
	printf("After swapping, value of a= %f",a);
	printf("\nAfter swapping, value of b= %f",b);
	return 0;


}

