#include <stdio.h>

//Write a program to check if a studenthas passed, failed, or achieved a distinction based on an input mark 
//(passmark is 50, distinction is 70)

int main(){

    float mark;

    printf("Enter your mark: ");
    scanf("%f", &mark);

    if (mark < 0 || mark > 100)
    {
        printf("This is not a valid mark.\n");
    }
    else if (mark < 50)
    {
        printf("This mark is a fail.\n");
    }
    else if (mark < 70)
    {
        printf("This mark is a pass.\n");
    }
    else if (mark < 100)
    {
        printf("This mark is a distinction.\n");
    }

    return 0;
}
