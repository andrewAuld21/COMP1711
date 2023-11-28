// Write a program that reads from the file 'squares.dat' created in the previous exercise and prints to the screen
// the average of all the numbers in the file

#include <stdio.h>
#include <stdlib.h>

int main(){
    char* filename = "squares.dat";
    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    // Just an arbitrary large number to give a size to the num_string array
    int buffer_size = 100;
    // 'num_string' is the string that will hold each line as it is read in
    char num_string[buffer_size];
    // 'string_to_num' will be the variable in which we will hold the integers converted from the string
    int string_to_num[1000];
    // Just a variable so we can iterate over the number of lines in the squares.dat file
    int number_of_lines = 0;

    // 'num_string' is what we have to turn into (atoi) an integer and store it in 'string_to_num'

    while(fgets(num_string, buffer_size, file) != NULL){
        string_to_num[number_of_lines] = atoi(num_string);
        number_of_lines++;
    }

    fclose(file);

    float num_sum;

    // This loop will iterate over the values in string_to_num and add them up and store them in num_sum
    for (int i = 0; i < number_of_lines; i++){
        num_sum += string_to_num[i];
    }

    float num_average = num_sum / number_of_lines;

    printf("The average of all the numbers in the file is %.2f\n", num_average);

    return 0;

}