 Author : Abdelrahman Kotb Ahmed
#include<stdio.h>
int main(){
	int a[10][10], trans[10][10], r, c, i, j;
	printf("Enter number of rows and column of matrix: ");
	scanf("%d %d",&r, &c);
/* storing element of matrix in array a[][]*/
	printf("\nEnter element of Matrix:\n ");
	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j){
		printf("Enter elments a%d%d: ",i+1, j+1);
		scanf("%d",&a[i][j]);
	}
/* Display the Matrix */
	printf("\nEntered matrix: \n");
	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j){
		printf("%d ",a[i][j]);
		if(j==c-1)
			printf("\n\n");
	}
/* finding transpose matrix and store it in trans array [][] */
	for(i=0; i<r; ++i)
	for(j=0; j<c; ++j){
		trans[j][i]=a[i][j];
	}
/* Display the transpose matrix */
	printf("\nEntered Transpose: \n");
	for(i=0; i<c; ++i)
	for(j=0; j<r; ++j){
		printf("%d ",trans[i][j]);
		if(j==r-1)
			printf("\n\n");
	}
	return 0;
}
