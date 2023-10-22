#include <stdio.h>

//Program to tell whether a number is positive, negative or zero

int main(){

    int num1;

    printf("Enter your number: ");
    scanf("%d", &num1);

    switch(num1){

        case 0:    while (num1 < 0){
            printf("Your number is negative.");
        }
        break;

        case 1:     while (num1 = 0){
                    printf("Your number is zero.");
        }
        break;

        case 2:    while (num1 > 0){
            printf("Your number is positive.");
        }
        break;

        default:    printf("Your number is invalid for this program");

    }
}