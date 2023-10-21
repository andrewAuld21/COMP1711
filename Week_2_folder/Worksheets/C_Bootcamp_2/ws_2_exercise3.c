// C program to find maximum in arr[] of size n
#include <stdio.h>
 
//I got the code from https://www.geeksforgeeks.org/program-to-find-largest-element-in-an-array/

// Function to find maximum in arr[] of size n
int largest(int arr[], int n)
{
    int i;
 
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from second and
    // compare every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}
 
// Driver code
int main()
{
    int arr[] = { 10, 45, 32, 67, 83 };
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    printf("Largest in given array is %d\n", largest(arr, n));
    return 0;
}
