#include "utilities.h"

int main()
{
    // array of reading structs called daily readings
    reading daily_readings[100];

    // this array will hold each line as it is read in from the file, initialized to the size of buffer size (100)
    char line[buffer_size];

    // this array will store the name of the file, initialized to the size of buffer size (100)
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    // this line basically gets whatever is in the stdinput, gives it size buffer_size, and stores it in array 'line'
    fgets(line, buffer_size, stdin);
    // stringscanf (sscanf) gets whatever is in 'line', makes sure it is in string format, and stores it in 'filename'
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;
    float lowest_blood;


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
            counter = 0;
            lowest_blood = 150;
            while(fgets(line, buffer_size, input)){
                tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
                if(daily_readings[counter].bloodIron < lowest_blood)
                {
                    lowest_blood = daily_readings[counter].bloodIron;
                }

                counter++;

            }

            printf("Your lowest level of blood iron was %.2f\n", lowest_blood);

            fclose(input);
            break;

        case 'D':
        case 'd':

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



// Alternative version of case C in StepCounter.c
if(counter > 0){
                least_steps = file_info[0].steps;
                int something = 0;

                for(int index = 0; index < counter; index++){
                 if(file_info[index].steps < least_steps){
                       least_steps = file_info[index].steps;
                      int something = index;
                    }                
                }
                

            printf("Fewest steps: %s %s\n", file_info[something].date, file_info[something].time);

            break;