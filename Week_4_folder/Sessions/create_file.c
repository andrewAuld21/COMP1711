#include <stdio.h>

int main () {
    char* filename = "data.txt";
    FILE *file = fopen (filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
        //If the program returns 1 it means there was an error
    }

    fprintf(file, "Hello world!\n");

    fclose(file); //Always make sure to close your file
    return 0;
    //0 is the value when there are no errors
}