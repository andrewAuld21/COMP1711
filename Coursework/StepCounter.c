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

    // 'buffer_size' is the maximum amount of characters that can be read in per line
   int buffer_size = 100;
   // This variable is for storing the name of the file being read in
   char filename[buffer_size];
    // 'line_storage_array' will store the lines that are read in and it is set to be the same size as 'buffer_size'
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
   

    // Created a new array 'file_info' and assigned it the 'FITNESS_DATA' structure type
   FITNESS_DATA file_info[1000];

    // Created new arrays to store the 'date', 'time', and 'steps' strings
   char date[11];
   char time[6];
   char steps[100];

    // This while loop keeps the menu system running after a choice has been selected
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

        // This line of code gets the character that the user inputs in order to know which case was chosen
        option = getchar();

        // Initiates a while loop that runs as long as the character does not equal the newline character '(\n)'
        while(getchar() != '\n');

        // Initiates the switch statement to choose the menu options
        switch(option)
        {
            case 'A':
            case 'a':

                // Prompts the user to enter the filename and stores the input (stdin) from the user into 'line_storage_array'
                // And then stores the string in 'line_storage_array' into 'filename'
                printf("Input filename: ");
                fgets(line_storage_array, buffer_size, stdin);
                sscanf(line_storage_array, "%s", filename);

                // Opens the file in 'read' mode and prints an error if the correct file is not selected.
                FILE *input = fopen(filename, "r");
                if (!input)
                {
                    printf("Error: could not find or open file.\n");
                    return 1;
                }

                // Uses the tokeniseRecord function to separate the strings being read in into date, time and steps
                // As well as changing file_info[counter].steps into an int variable 'steps_as_int'
                // 'counter++' reads through every line in the file
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

                // Makes number of records equal to counter
                number_of_records = counter;

                // Prints the statement if the file is successfully accessed and loaded
                printf("File successfully loaded.\n");

                break;
        
            case 'B':
            case 'b':
                // Prints the numebr of records in the file
                printf("Total records: %i\n", number_of_records);
                break;
        
            case 'C':
            case 'c': 

                // Initializes 'least_steps' to 10,000
                least_steps = 10000;
                // Iterates through all the lines of the file
                for(int i = 0; i < number_of_records; i++){
                    // If the steps are lower than least_steps, update the value of least_steps
                    if(file_info[i].steps < least_steps)
                    {
                        least_steps = file_info[i].steps;
                        min_steps_index = i;

                    }
            
                }

                // Prints the date and time of the least steps value
                printf("Fewest steps: %s %s\n", file_info[min_steps_index].date, file_info[min_steps_index].time);

                break;
        
            case 'D':
            case 'd':

                // Initializes 'most_steps' to 0
                most_steps = 0;
                //Iterates through all the lines of the file
                for(int i = 0; i < number_of_records; i++){
                    // If the steps are greater than 'most_steps', update the value of 'most_steps'
                    if(file_info[i].steps > most_steps)
                    {
                        most_steps = file_info[i].steps;
                        most_steps_index = i;
                    }

                }

                // Prints the date and time of the most_steps value
                printf("Largest steps: %s %s\n", file_info[most_steps_index].date, file_info[most_steps_index].time);

                break;
        
            case 'E':
            case 'e':
                
                // Iterates through all the lines in the file
                for(int i = 0; i < number_of_records; i++)
                // Updates the value of 'mean' with every 'steps' value in each line
                {
                    mean += file_info[i].steps;
                }

                // Divides the value of 'mean' by the number of lines in the file
                mean /= counter;
                // Prints the value of 'mean'
                printf("Mean step count: %.0f\n", mean);
                break;
            
            case 'F':
            case 'f':

                // Iterates through all the lines of the file
                for(int i = 0; i < number_of_records; i++)
                {
                    // If the value of file_info[i].steps is greater than 500, it initializes the length of the period to 0
                    // And assigns the line 'i' to the start of the longest period variable 'current_start_index'
                    // And continues increasing the value of the length of the period with 'current_period_length++'
                    if(file_info[i].steps > 500)
                    {
                        if(current_period_length == 0)
                        {
                            current_start_index = i;
                        }

                        current_period_length++;

                    }else{
                        // If current_period_length is longer than longest_period_length (which at the beginning is 0)
                        // then it updates the value of longest_period_length to the value of current_period_length
                        // as well as the value of the starting index of the longest period
                        if(current_period_length > longest_period_length)
                        {
                            longest_period_length = current_period_length;
                            longest_start_index = current_start_index;
                        }

                        // Restarts the value of 'current_period_length' to 0, so that it can accurately find the length
                        // of another continuous period
                        current_period_length = 0;

                    }
                }     
                
                // Prints the date and time of the start of the longest continuous period
                printf("Longest period start: %s %s\n", file_info[longest_start_index].date, file_info[longest_start_index].time);

                // Prints the date and time of the end of the longest period by adding the length to the start of the longest period
                printf("Longest period end: %s %s\n", file_info[longest_start_index + longest_period_length - 1].date, file_info[longest_start_index + longest_period_length - 1].time);

                break;

            // Returns 0 and exits the program
            case 'Q':
            case 'q':
                return 0;
                break;

            // Prints an error message in case an invalid letter is selected for the menu
            default:
                printf("Invalid choice. Try again\n");
                break;
        
        }

    }

}