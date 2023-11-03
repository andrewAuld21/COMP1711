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
// What I need to do is read in the csv (Comma Separated Values) file, store it in an array with a suitable size and structure
// (size 100 or 1000) and then use the typedef struct which is provided to print out the first three lines
int main() {

    char* filename = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int count = 0;
    int buffer_size = 100;
    char line_storage_array[buffer_size];
    
    FITNESS_DATA file_info[100];
    char date[11];
    char time[6];
    char steps[100];

    while(fgets(line_storage_array, buffer_size, file) != NULL){

        tokeniseRecord(line_storage_array, ",", date, time, steps);

        strcpy(file_info[count].date, date);
        strcpy(file_info[count].time, time);

        int steps_as_int;
        steps_as_int = atoi(steps);

        file_info[count].steps = steps_as_int;

        count++;

    }

    printf("Number of records in file: %i\n", count);
    
    int item;

    for(item = 0; item < 3; item++){

            printf("%s/", file_info[item].date);
            printf("%s/", file_info[item].time);
            printf("%i\n", file_info[item].steps);
            
    }

   fclose(file);
   return 0;

}