#include <stdio.h>

//Create a menu system using a SWITCH statement that allows the user to select between 5 options. 
//Include an error message for invalid choices

int main(){
    
    int a;

    printf("Choose your option: ");
    scanf("%i", &a);

    switch(a)
    {
        case 1:     printf("You have selected Option 1\n");
        break;

        case 2:     printf("You have selected Option 2\n");
        break;

        case 3:     printf("You have selected Option 3\n");
        break;

        case 4:     printf("You have selected Option 4\n");
        break;

        case 5:     printf("You have selected Option 5\n");
        break;

        default:        printf("ERROR: NOT AN OPTION\n");
    }
}
