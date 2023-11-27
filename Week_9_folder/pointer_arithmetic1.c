#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17, 23 , 31};

    int* address = vector;

    printf("\nAddress[0] = %d\n", *address);
    printf("Address[0] = %d\n", address[0]);

    // This section moves the index of the address when doing '*(address + 1 or + 2)' it is not adding to the value
    // but instead adding to the index, basically telling it to move to the next index
    printf("\nAddress[1] = %d\n", *(address+1));
    printf("\nAddress[2] = %d\n", *(address+2));

    printf ( "\nAddress[0] = %d\n", *address);

    printf ( "\nAddress[1] = %d\n", *(address+1));

    printf ("\nAddress[2] = %d\n", *(address+2));

    

}