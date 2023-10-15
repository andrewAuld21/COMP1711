#include <stdio.h>

//Program to determine whether an integer is even or odd

int main(){

    int numb1;
    int finalnum = (numb1 % 2);

    printf("Enter your number: ");
    scanf("%i", &numb1);

    if(finalnum == 0) {

        printf("Your number is even!\n");

    } else {

        printf("Your number is odd!\n");

    }
    
    return 0;
}
