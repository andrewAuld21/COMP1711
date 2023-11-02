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
        printf("Could not open file\n");
        return 1;
    }

    int count = 0;
    int buffer_size = 100;
    char line_storage_array[buffer_size];

    while(fgets(line_storage_array, buffer_size, file) != NULL){
        count += 1;
    }

    printf("Number of records in file: %i\n", count);

    // First, separate the string by the commas, using the tokenizeRecord function.
    // create another array
    // for loop that starts at 0 and is under 3, i++. Inside the for loop use printf() and assign a new variable name to the
    // typedef struct FITNESS DATA
    // tokenize record has to be in the whileloop for it to go line by line
    // 
    

   fclose(file);
   return 0;

}