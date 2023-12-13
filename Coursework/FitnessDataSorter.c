#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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

// Function to compare FitnessData records for qsort
// I based this function on a discussion with ChatGPT
// Prompt: How can I compare items in a list in order to sort them?
int compareRecords(const void *a, const void *b) 
{
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}

int main() {

    // Initializes the size of 'buffer_size' to 100
    int buffer_size = 100;
    // 'line_storage_array' will store the lines that are read in and it is set to be the same size as 'buffer_size'
    char line_storage_array[buffer_size];
    // This variable is for storing the name of the file being read in
    char filename[buffer_size];
    // Initializes the 'counter' variable to 0
    int counter = 0;
    // This variable is for storing the name of the file that will be output
    char new_file_filename[buffer_size];

    // Created a new array 'file_info' and assigned it the 'FITNESS_DATA' structure type
    FitnessData file_info[100];

    // Created new arrays to store the 'date', 'time', and 'steps' strings
    char date[11];
    char time[6];
    char steps[100];

    // Asks the user for a filename
    printf("Enter filename: ");
    // Gets the input from the user and stores it in line_storage_array
    fgets(line_storage_array, buffer_size, stdin);
    // Stores string that holds the name of the file into 'filename'
    sscanf(line_storage_array, "%s", filename);

    // Opens the original file
    FILE *input = fopen(filename, "r");
    if (!input) 
    {
        // Prints an error message if the file is not the correct file
        printf("Error: invalid file.\n");
        return 1;
    }

    // Uses the tokeniseRecord function to separate the strings being read in into date, time and steps
    // As well as changing file_info[counter].steps into an int value
    // 'counter++' reads through every line in the file
    while (fgets(line_storage_array, buffer_size, input) != NULL)
    {
        tokeniseRecord(line_storage_array, ",", date, time, steps);
        // I based this line of a discussion with ChatGPT
        // Prompt: How can I check for invalid data in a file?
        if (sscanf(line_storage_array, "%[^,],%[^,],%s", date, time, steps) != 3) {
            // Print an error message for invalid data
            printf("Error: the file contains invalid data.\n");
            fclose(input);
            return 1;
        }
        strcpy(file_info[counter].date, date);
        strcpy(file_info[counter].time, time);
        file_info[counter].steps = atoi(steps);
        counter++;
    }

    // Sorts the data in descending order of steps using the 'compareRecords' function
    qsort(file_info, counter, sizeof(FitnessData), compareRecords);

    // Creates a new filename with .tsv extension
    snprintf(new_file_filename, buffer_size, "%s.tsv", filename);

    // Opens the new file where the sorted lines will go
    FILE *output = fopen(new_file_filename, "w");
    if (!output)
    {
        // Prints an error message if the output file is not the correct name
        printf("Error: could not create file.\n");
        return 1;
    }

    // Iterates through every line in the file
    for (int i = 0; i < counter; i++)
    {
        // Prints the date, time and steps of the line into the new file
        fprintf(output, "%s\t%s\t%d\n", file_info[i].date, file_info[i].time, file_info[i].steps);
    }

    // Closes the input and output file
    fclose(input);
    fclose(output);

    // Prints a message to show the program has been executed successfully
    printf("Data sorted and written to %s.tsv\n", filename);

    return 0;
    
}