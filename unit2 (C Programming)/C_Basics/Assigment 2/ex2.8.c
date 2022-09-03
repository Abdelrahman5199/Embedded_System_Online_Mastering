#include "stdio.h"

void main ()

{

	char a;
	float x,y,output;

	printf ("Enter operator either + or - or * or divide: ");
	fflush (stdin); fflush (stdout);
	scanf ("%c", &a);
	printf ("Enter two operands: ");
	fflush (stdin); fflush (stdout);
	scanf ("%f %f ", &x, &y);
	fflush (stdin); fflush (stdout);

	switch (a)

	{
	case '+':
	{
		output = x + y;
		printf ("%f + %f = %f", x,y,output);
	}break;
	case '-':
	{
		output = x - y;
		printf ("%f - %f = %f", x,y,output);

	}break;
	case '*':
	{
		output = x * y;
		printf ("%f * %f = %f", x,y,output);

	}break;
	case '/':
	{
		output = x / y;
		printf ("%f / %f = %f", x,y,output);
	}break;
	default:
	break;
	}
	return 0;

}
