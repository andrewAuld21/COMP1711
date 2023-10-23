#include <stdio.h>

//Write a function that takes a float radius and returns the volume of a sphere with that radius

float sphereVolume(float radius){

    float answer;
    answer = (radius * radius * radius) * 3.142 * 4/3;
    return answer;
}

int main(){

    float rad;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &rad);

    float final_answer = sphereVolume(rad);

    printf("The volume of the sphere is %.2f.\n", final_answer);

    return 0;
}