#include <stdio.h>

int main(){

    float length;
    float width;
    float area;

    printf("How many units is the length of the rectangle?: ");
    scanf("%f", &length);

    printf("How many units is the width of the rectangle?: ");
    scanf("%f", &width);

    area = length * width;

    //The '.3' after the % in length and width is to tell the program to use 3 decimal places
    printf("The area of the rectangle with length %.3f and width %.3f is %.3f\n", length, width, area);

    return 0;
}
