#include "utilities.h"

// New code below:
int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    while (1)
    {
        FILE *input = fopen(filename, "r");
        if (!input)
        {
            printf("Error: File could not be opened\n");
            return 1;
        }

        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
                counter++;
            }
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            fclose(input);
            break;

        case 'B':
        case 'b':
            counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
                // using the & operator to pass in a pointer to the bloodIron so it stores it
                tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
                mean += daily_readings[counter].bloodIron;
                counter++;
            }
            mean /= counter;
            printf("Your average blood iron was %.2f\n", mean);
            fclose(input);
            break;

        case 'C':
        case 'c':
            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}




// New code below:
#include <stdio.h>

int isPrime(int num){

    if (num < 2){
        return 0;
    }
    
    for (int i = 2; i < num; i++){
        if (num % i == 0){
            return 0;
        }
    }

    return 1;
    
}

int main(){

    int input_num;

    printf("Please enter a number: ");
    scanf("%i", &input_num);

    if(isPrime(input_num)){
        printf("%i is not a prime number.\n", input_num);
    }
    else{
        printf("%i is a prime number.\n", input_num);
    }

    return 0;

}



// New code below:
#include <stdio.h>

int concatStrings(char string1[], const char string2[]){
    int i = 0;
    int j = 0;

    while (string1[i] != "\0"){
        i++;
    }

    while (string2[j] != "\0"){
        string1[i] = string2[j];
        i++;
        j++;
    }

    string1[i] = "\0";
}

int main(){
    char string1[500] = "Hello ";
    const char string2[] = "everybody!";

    concatStrings(string1, string2);

    printf("The concatenated string is: %s\n", string1);

    return 0;

}




// Code from Week 4 Worksheet 1 Gold Exercise here:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* filename = "numbers.dat";
    FILE *file = fopen(filename, "a+");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    float input_float;
    char input_float_string[100];

    printf("Enter the float you wish to append to the file (or enter a non-numeric value to stop): ");
    if(scanf("%s", input_float_string) != "%s"){
        while(scanf("%s", input_float_string) == 1){
        fprintf(file, "%s", input_float_string);
        printf("Enter an additional float you wish to append to the file (or enter a non-numeric value to stop): ");
        }
    }

    fseek(file, 0, SEEK_SET);

    float sum = 0.0;
    int count;

    while(fscanf(file, "%s", input_float_string) == 1){
        input_float = atof(input_float_string);
        sum += input_float;
        count++;
    }

    float average = sum / count;

    fprintf(file, "The average of the floats in the file is: %f\n", average);

    fclose(file);

    return 0;
    
}


