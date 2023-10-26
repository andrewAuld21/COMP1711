#include <stdio.h>

int str_len(char string1){

    char *arr;
    int i;
    int length = 0;

    printf("Enter a string: ");
    scanf("%i", *arr);

    for(i = 0; arr[i] != "\0"; i++)
    {
        length++;
    }

    printf("The length of the string is %d characters!", length);

    return 0;
}
