// Abdelrahman Kotb
#include<stdio.h>
int main() {

    int a[30], num, e, i;
    printf("Enter number of elements: ");
    scanf_s("%d", &num);
    for (i = 0; i < num; i++) {
        scanf_s("%d", &a[i]);
    }
    // Read the element to be searched
    printf("Enter the elements to be searched: ");
    scanf_s("%d", &e);
    // search start from zeroth
    i = 0;
    while (i < num && e != a[i]) {
        i++;
    }
    // if i < num  
    if (i < num) {
        printf("Number found at the location = %d", i + 1);
    }
    else {
        printf("Number not found ");
    }
    return 0;
}