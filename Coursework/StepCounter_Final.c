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
   int number_of_records;
   int counter = 0;
   float mean = 0;
   int least_steps;
   int most_steps;
   int min_steps_index;
   int most_steps_index;
   int current_start_index;
   int current_period_length;
   int longest_start_index;
   int longest_period_length;
   

   FITNESS_DATA file_info[1000];

   char date[11];
   char time[6];
   char steps[100];

   while(1)
   {

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
                if (!input)
                {
                    printf("Error: could not find or open file.\n");
                    return 1;
                }

                while (fgets(line_storage_array, buffer_size, input) != NULL)
                {
                    tokeniseRecord(line_storage_array, ",", date, time, steps);
                    strcpy(file_info[counter].date, date);
                    strcpy(file_info[counter].time, time);
                    int steps_as_int;
                    steps_as_int = atoi(steps);
                    file_info[counter].steps = steps_as_int;
                    counter++;
                }

                number_of_records = counter;

                printf("File successfully loaded.\n");

                break;
        
            case 'B':
            case 'b':
                printf("Total records: %i\n", number_of_records);
                break;
        
            case 'C':
            case 'c': 

                least_steps = 10000;
                for(int i = 0; i < number_of_records; i++){
                    if(file_info[i].steps < least_steps)
                    {
                        least_steps = file_info[i].steps;
                        min_steps_index = i;

                    }
            
                }

                printf("Fewest steps: %s %s\n", file_info[min_steps_index].date, file_info[min_steps_index].time);

                break;
        
            case 'D':
            case 'd':

                most_steps = 0;
                for(int i = 0; i < number_of_records; i++){
                    if(file_info[i].steps > most_steps)
                    {
                        most_steps = file_info[i].steps;
                        most_steps_index = i;
                    }

                }

                printf("Largest steps: %s %s\n", file_info[most_steps_index].date, file_info[most_steps_index].time);

                break;
        
            case 'E':
            case 'e':
                
                for(int i = 0; i < number_of_records; i++)
                {
                    mean += file_info[i].steps;
                }

                mean /= counter;
                printf("Mean step count: %.0f\n", mean);
                break;
            
            case 'F':
            case 'f':
                for(int i = 0; i < number_of_records; i++)
                {
                    if(file_info[i].steps > 500)
                    {
                        if(current_period_length == 0)
                        {
                            current_start_index = i;
                        }

                        current_period_length++;

                    }else{
                        if(current_period_length > longest_period_length)
                        {
                            longest_period_length = current_period_length;
                            longest_start_index = current_start_index;
                        }

                        current_period_length = 0;

                    }
                }     
                
                printf("Longest period start: %s %s\n", file_info[longest_start_index].date, file_info[longest_start_index].time);
                printf("Longest period end: %s %s\n", file_info[longest_start_index + longest_period_length].date, file_info[longest_start_index + longest_period_length].time);

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