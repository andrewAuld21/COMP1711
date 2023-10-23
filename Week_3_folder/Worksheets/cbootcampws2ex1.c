#include <stdio.h>

//Write a C program that defines a function circleArea which takes a float radius as a parameter and returns the area of
//the circle. Test this function in your main function

float circleArea(float radius){

    float answer;
    answer = (radius * radius) * 3.142;
    return answer;
}

int main(){

    float rad;

    printf("Enter the radius of the circle: ");
    scanf("%f", &rad);

    float final_answer = circleArea(rad);

    printf("The area of the circle is %.2f.\n", final_answer);

    return 0;
}