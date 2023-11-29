#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here


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

    // This section reads in the FitnessData_2023.csv file and prints an error if it cannot open the file
    // I based the code for this section off 'read_from_file.c' from the Week 4 Sessions
    char* filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Initialized a 'count' variable and set it to 0 to count the number of lines in the csv file
    int count = 0;
    // 'buffer_size' is the maximum amount of characters that can be read in per line
    int buffer_size = 100;
    // 'line_storage_array' will store the lines that are read in and it is set to be the same size as 'buffer_size'
    char line_storage_array[buffer_size];
    
    // Created a new array 'file_info' and assigned it the 'FITNESS_DATA' structure type
    // I based this line on a discussion with ChatGPT
    // Prompt: How can I assign a typedef struct format to an array?
    FITNESS_DATA file_info[100];

    // Created new arrays to store the 'date', 'time', and 'steps' strings
    char date[11];
    char time[6];
    char steps[100];

    // Created a while loop to continue reading in lines from 'FitnessData_2023.csv' until the file ends
    while(fgets(line_storage_array, buffer_size, file) != NULL){

        // Splits the strings in 'line_storage_array' by the commas using the 'tokeniseRecord' function provided
        // and stores the strings in 'date', 'time' and 'steps'
        tokeniseRecord(line_storage_array, ",", date, time, steps);

        // Copies the string from 'date' and 'time' and puts them into the 'file_info' array in their respective
        // fields (.date and .time)
        // 'strcpy' taken from 'records_loop.c' from Week 4 Sessions
        strcpy(file_info[count].date, date);
        strcpy(file_info[count].time, time);

        // Created a 'steps_as_int' variable to store the integer value of the string 'steps'
        int steps_as_int;

        // Uses 'atoi()' to convert the string 'steps' to an integer
        // 'atoi' taken from 'read_from_file.c' from Week 4 Sessions
        steps_as_int = atoi(steps);

        // Stores the 'steps_as_int' value into the 'file_info' array into the '.steps. field
        file_info[count].steps = steps_as_int;

        // 'count++' to move on to the next line
        count++;

    }

    // Prints the number of records in the file
    printf("Number of records in file: %i\n", count);
    
    // Created a new variable 'item' to use in while loop to represent the number of lines
    int item;

    // Prints the first three lines of 'FitnessData.csv'
    for(item = 0; item < 3; item++){

            printf("%s/", file_info[item].date);
            printf("%s/", file_info[item].time);
            printf("%i\n", file_info[item].steps);
            
    }

    // Closes the 'FitnessData.csv' file and returns 0 for no errors
   fclose(file);
   return 0;

}