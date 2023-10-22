#include <stdio.h>

int main(){

    int num1;

    printf("Enter your number: ");
    scanf("%i", &num1);

    if (num1 % 4 == 0 && num1 % 5 == 0)
    {
        printf("The number %i is divisible by both 4 and 5!", num1);
    }
    else
    {
        printf("The number %i is not divisible by both 4 and 5.", num1);
    }

    return 0;
}