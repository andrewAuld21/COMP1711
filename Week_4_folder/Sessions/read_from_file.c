#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    //buffer_size is the number of characters which will be read per line
    int buffer_size = 100;
    //making a string which will hold each line as it's read in (making it the same size as buffer_size)
    char line_buffer[buffer_size];

    //an arbitrary large number
    int numbers[1000];

    int number_of_lines = 0;

    //"while there is still data in the file" basically (fgets reads in the line)
    // here the syntax is 'fgets(array/string where you will store the line, amount of characters, from where)
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        //going to take whatever is in data.txt and convert it(atoi) into a number since it is originally a string
        printf("%d\n", atoi(line_buffer));
        numbers[number_of_lines] = atoi(line_buffer);
        number_of_lines++;
    }

    fclose(file);
    return 0;
}