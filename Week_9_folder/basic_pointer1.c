#include <stdio.h>

int main()
{
    // creates a new integer variable called 'var' and assigns it a value of 10
    int var=10;

    // creates an int pointer called 'var_address' and sets it to the address of 'var'
    // (a pointer is a variable that stores the memory address of another variable as its value)
    int* var_address = &var;

    printf("\n");
    printf("The content of \"var\" = %d\n",var);

    printf ("The content \"var_address\" = %p\n", var_address);

    printf ("Now the magic! Content of \"*var_address\" = %d\n", *var_address);
    
    printf("\n");
}