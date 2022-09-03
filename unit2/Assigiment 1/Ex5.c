/*

 * Ex5.c
 *  Embedded
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman kotb:
 */
#include "stdio.h"
void main()
{
	char i;
	printf("Enter a character:");
	fflush(stdin); fflush(stdout);
	scanf("%c",&i);
	printf("\nAscii value of %c = %d",i,i);
}



