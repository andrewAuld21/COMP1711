#include <stdio.h>

//Got the idea for this code from https://www.javatpoint.com/c-program-to-print-the-sum-of-all-elements-in-an-array

int main(){

    int a [] = {20, 10, 12, 33, 80};
    int sum = 0;

    int length = sizeof(a)/sizeof(a[0]);
    
    for(int i = 0; i < length; i++)
    {
        sum = sum + a[i];
    }
   
    printf("The sum of all the elements in this array is: %d\n", sum);    
    return 0;    
}