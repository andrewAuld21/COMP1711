#include <stdio.h>

//Program to check if a number is positive, negative or zero

int main(){

    int num1;

    printf("Enter your number: ");
    scanf("%i", &num1);

    if (num1 < 0)
    {
        printf("The number %i is negative!", num1);
    }
    else if (num1 == 0)
    {
        printf("The number %i is zero!", num1);
    }
    else if (num1 > 0)
    {
        printf("The number %i is positive!", num1);
    }
    
    return 0;
}
