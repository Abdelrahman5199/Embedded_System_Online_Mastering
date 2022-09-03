/*
 * Ex4.c

 *
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman _ KOtb
 *
 *
 */
#include "stdio.h"
int main()
{
	float x,y,product;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);
	product=x*y;
	printf("Product: %f",product);
	return 0;
}


