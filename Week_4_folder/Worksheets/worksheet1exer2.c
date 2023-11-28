// Write a program that reads from the file 'squares.dat' created in the previous exercise and prints to the screen
// the average of all the numbers in the file

#include <stdio.h>
#include <stdlib.h>

int main(){
    char* filename = "squares.dat";
    FILE *file == fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    // 'num_string' is the string that will hold each line as it is read in
    char num_string[buffer_size];
    // 'num_average' will be the float in which we store the average of all numbers in the file
    float num_average;
}