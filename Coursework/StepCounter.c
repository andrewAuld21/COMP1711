#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {

   int buffer_size = 100;
   char filename[buffer_size];
   char line_storage_array[buffer_size];

   char option;
   int counter = 0;
   float mean = 0;

   FITNESS_DATA file_info[100];

   char date[11];
   char time[6];
   char steps[100];

   while(1){

    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");

    option = getchar();

    while(getchar() != '\n');

    switch(option)
    {
        case 'A':
        case 'a':

            printf("Input filename: ");
            fgets(line_storage_array, buffer_size, stdin);
            sscanf(line_storage_array, "%s", filename);

            FILE *input = fopen(filename, "r");
            if (!input){
                printf("Error: could not find or open file.\n");
                return 1;
            }

            while (fgets(line_storage_array, buffer_size, input) != NULL){
                tokeniseRecord(line_storage_array, ",", date, time, steps);
                strcpy(file_info[counter].date, date);
                strcpy(file_info[counter].time, time);
                int steps_as_int;
                steps_as_int = atoi(steps);
                file_info[counter].steps = steps_as_int;
                counter++;
            }

            printf("File successfully loaded.\n");

            break;
        
        case 'B':
        case 'b':
            printf("Total records: %i\n", counter);
            fclose(input);
            break;
        
        case 'C':
        case 'c':
            
            break;

        case 'Q':
        case 'q':
            return 0;
            break;
        
        default:
            printf("Invalid choice. Try again\n");
            break;
    }

    }

}