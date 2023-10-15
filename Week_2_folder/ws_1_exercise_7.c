#include <stdio.h>

//Program to change degrees Farenheit to Celsius

int main(){

    float tempF;
    float tempC;

    printf("Enter the temperature in Farenheit: ");
    scanf("%f", &tempF);

    tempC = (tempF - 32) * 5/9;

    printf("The temperature in degrees Celsius is %.2f\n", tempC);

    return 0;
}