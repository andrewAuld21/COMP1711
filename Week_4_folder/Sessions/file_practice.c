#include <stdio.h>

int main(){

    //Creates a string variable called filename and inserts the name data.txt into the variable
    char *filename = "data.txt";

    //Creates a file and opens it, clarifying that the name is in the variable filename and uses 'w' to overwrite text into\
    that file
    FILE *file = fopen(filename, "w");
    
    //Tells the program what to do if there is any error while opening the file
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int numbers_to_enter;
    int number;

    

    fclose(file);
