#include <stdio.h>

int main(){
    // setting up 15 slots of memory for a string
    char name[15];

    // prompting the user to enter their name
    printf("Hello, please enter your name: ");

    // take the user input and store it into 'name'
    scanf("%s", name);

    // prints out the user's name
    printf("Your name is %s\n", name);

    return 0;
}