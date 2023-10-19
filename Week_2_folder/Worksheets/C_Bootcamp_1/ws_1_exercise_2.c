#include <stdio.h>

int main(){

    int num1;
    int num2;
    int num3;

    printf("Enter the first number you wish to add: ");
    scanf("%i", &num1);

    printf("Enter the second number you wish to add: ");
    scanf("%i", &num2);

    num3 = num1 + num2;

    printf("The sum of %i and %i is %i\n", num1, num2, num3);

    return 0;
}
