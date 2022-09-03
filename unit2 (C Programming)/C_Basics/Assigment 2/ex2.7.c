#include<stdio.h>
int main() {
	int n, count;
	unsigned  long int factorial=1;
	printf("Enter an integer : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&n);
		if(n < 0 )

			printf("Error!!! Factorial of negative number doesn't exist \n");
		else
		{
		for(count = 1 ; count <= n ; ++count)
			{
				factorial *= count;
			}
		printf("Factorial = %lu",factorial);
		}


	return 0;
}
