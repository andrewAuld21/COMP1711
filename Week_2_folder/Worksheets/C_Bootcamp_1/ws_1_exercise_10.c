#include <stdio.h>

int main(){

    float principal;
    float rate;
    float time;
    float totalinterest;

    printf("How much principal do you have?: ");
    scanf("%f", &principal);

    printf("What is your interest rate as a decimal?: ");
    scanf("%f", &rate);

    printf("For how many years will you be paying interest?: ");
    scanf("%f", &time);

    totalinterest = principal * rate * time;

    printf("The amount of interest you must pay in that given time is $%.2f\n", totalinterest);

    return 0;
}