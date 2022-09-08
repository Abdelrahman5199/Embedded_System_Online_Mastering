#include<stdio.h>
#include<string.h>
int main() {
	char s[1000], i;
	printf("Enter a string: ");
	scanf_s("%s", s);
	for (i = 0; s[i] != '\0'; ++i);
	printf("Length of string: %d ", i);
	

}