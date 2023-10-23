#include <stdio.h>

int main(){

    int arr[10];
    int i = 0;
    int total = 0;
    float mean;

    for (i = 0; i < 10; i++)
    {
        printf("Enter ten numbers into this array: ");
        scanf("%i", &arr[i]);
        total += arr[i];
    }

    mean = total/10;

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("The average is %f\n", mean);


}