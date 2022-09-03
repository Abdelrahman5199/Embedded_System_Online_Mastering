/*

 * Ex7.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman kotb:
 */
#include "stdio.h"
int main()
{
	float a,b;
		printf("Enter valueo of a:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&a);
		printf("Enter valueo of b:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&b);
	    a=a+b;
	    b=a-b;
	    a=a-b;
		printf("After swapping, value of a= %f",a);
		printf("\nAfter swapping, value of b= %f",b);
		return 0;

}


