// Abdelrahman Kotb
#include<stdio.h>
int main() {

    int a[30], num, location, e, i;
    printf("Enter number of elements: ");
    scanf_s("%d", &num);
    for (i = 0; i < num; i++) {
        scanf_s("%d", &a[i]);
    }
    printf("Enter the elements to be inserted: ");
    scanf_s("%d", &e);
    printf("\nEnter the location: ");
    scanf_s("%d", &location);
    for (i = num; i >= location; i--) {
        a[i] = a[i - 1];
    }
    num++;
    a[location - 1] = e;
    for (i = 0; i < num; i++) {
        printf("%d\t", a[i]);
    }
}
