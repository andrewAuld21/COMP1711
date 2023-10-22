#include <stdio.h>

//Write a program that continuously asks the user for a number until they enter a termination value of -1.
//The program should validate if the number is within the range of 0 to 100 or if it’s the termination value,
//and print a message accordingly

int main(){

    int num1;

    printf("Enter a number: ");
    scanf("%i", &num1);

    while (num1 >= 0 && num1 <= 100)
    {
        printf("Enter a new number: ");
        scanf("%i", &num1);
    }
    if (num1 == -1)
    {
        printf("Termination value input, program stopped.\n");
    }

    return 0;
}