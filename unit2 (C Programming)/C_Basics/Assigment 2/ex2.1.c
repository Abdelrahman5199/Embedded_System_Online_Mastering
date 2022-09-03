/*

 * ex2.1.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman Kotb
 */
#include "stdio.h"
int main()
{
	int num;
	printf("Enter a number you want check: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("%d is even",num);

	}
	else{
		printf("%d is odd",num);

	}
	return 0;
}

