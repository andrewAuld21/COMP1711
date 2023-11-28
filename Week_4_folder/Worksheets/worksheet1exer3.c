// Write a program that creates a file containing a single floating point number per line, and updates that same file
// by adding a new line at the bottom and printing to it the average of all the floats in the file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* filename = "numbers.dat";
    FILE *file = fopen(filename, "a+");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int counter = 0;
    float sum = 0;

    while(fgets(line_buffer, buffer_size, file) != NULL){
        sum += atof(line_buffer);
        counter++;
        if(line_buffer[strlen(line_buffer-1)] != '\n'){
            fprintf(file, "\n");
        }
    }

    fprintf(file, "%f", sum / counter);

    fclose(file);

    return 0;

}


