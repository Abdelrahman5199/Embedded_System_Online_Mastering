/************************
 * Learn_in_depth_C_Programing
 * Created on : 23/2/2022
 * Author: Abdelrahman_Kotb
 */

#include <stdio.h>

int main()
{
	int x , y ,sum;
	printf("Enter two integers: ");
	fflush(stdout);fflush(stdin);
	scanf("%d %d",&x,&y);
	sum=x+y;
	printf("\nSum: %d",sum);
	return 0;
}
