/*

 * ex2.2.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Abdelrahman kotb
 */
#include "stdio.h"
int main()
{
	char d;
	printf("Enter an alphabet:");
	fflush(stdin); fflush(stdout);
	scanf("&c,&d");
	if(d=='a',d=='A',d=='e',d=='E',d=='i',d=='I',d=='o',d=='O',d=='u',d=='U')
		printf("%c is a vowel.",d);
	else
		printf("%c is a consonant.",d);
	return 0;
}


