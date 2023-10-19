#include <stdio.h>

//Program to determine whether an integer is even or odd
//The program was not working because I defined finalnum before letting the user input numb1
//I fixed it already tho

int main(){

    int numb1;
    int finalnum;

    printf("Enter your number: ");
    scanf("%i", &numb1);

    finalnum = numb1 % 2;

    if(finalnum == 0) {

        printf("Your number is even!\n");

    }
    else 
    {

        printf("Your number is odd!\n");

    }
    
    return 0;
}
