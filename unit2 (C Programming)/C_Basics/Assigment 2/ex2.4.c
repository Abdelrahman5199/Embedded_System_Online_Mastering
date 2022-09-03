#include<stdio.h>
int main(){
	float num;
	printf("Enter a number: ");
	scanf("%f",&num);
	if(num<=0)
	{
		if(num==0)
			printf("You Entered Zero.");
		else
			printf("%2f is negative.",num);

	}
	else
		printf("%2f is Positive.",num);
	return 0;
}
