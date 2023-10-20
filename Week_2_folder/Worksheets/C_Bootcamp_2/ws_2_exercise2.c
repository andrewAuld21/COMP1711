#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[1000];
    int num;

    //Prompts the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%i", &num);

    //Prompts the user to enter the elements in the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i <= num; i++)
    {
        scanf("%i", &arr[i]);
    }

    //Now we reverse the array
    int start = 0;
    int end = num - 1;

    while(start < end){

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    //Prints the reversed array
    printf("The reversed array is: ");
    for (int i = 0; i <= num; i++)
    {
        printf("%i", arr[i]);
    }

    return 0;

}
