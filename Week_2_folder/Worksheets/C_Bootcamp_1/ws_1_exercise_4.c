#include <stdio.h>

//Program to calculate the area of a circle given the radius

int main(){

    float radius;
    float area;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = 3.142 * (radius * radius);

    printf("The area of the circle with radius %.3f is %.3f\n cm squared", radius, area);

    return 0;
}