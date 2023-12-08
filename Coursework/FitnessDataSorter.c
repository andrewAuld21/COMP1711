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
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {

    int buffer_size = 100;
    char line_storage_array[buffer_size];
    char filename[buffer_size];
    int counter = 0;

    FitnessData file_info[100];

    char date[11];
    char time[6];
    char steps[100];

    printf("Enter Filename: ");
    fgets(line_storage_array, buffer_size, stdin);
    sscanf(line_storage_array, "%s", filename);

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: invalid file.\n");
        return 1;
    }

    while (fgets(line_storage_array, buffer_size, input) != NULL)
    {
        tokeniseRecord(line_storage_array, ',', date, time, &file_info[counter].steps);
        strcpy(file_info[counter].date, date);
        strcpy(file_info[counter].time, time);
        printf("Original order: ");
        printf("%s %s %i\n", file_info[counter].date, file_info[counter].time, file_info[counter].steps);
        counter++;
    }

    return 0;

}