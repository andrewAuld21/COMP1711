#include <stdio.h>

//Write a program to validate if a temperature is within the range of -10 to 40 degrees Celsius

int main(){

    float temp;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    if (temp > -10 && temp < 40)
    {
        printf("That temperature is within the acceptable range.\n");
    }
    else
    {
        printf("That temperature is not within the acceptable range.\n");
    }

    return 0;
}
