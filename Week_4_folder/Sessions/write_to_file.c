#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    printf("How many numbers do you want to input?: ");
    int num_lines;
    char str1[10];
    scanf("%s", str1);
    num_lines = atoi(str1);
    scanf("%d", &num_lines);
    int total = 0;
    float mean;

    char string[100];

    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        total += number;
        fprintf(file, "%d\n", number);
    }

    mean = total/num_lines;
    fprintf("%f\n", mean);

    fclose(file);
    return 0;
}