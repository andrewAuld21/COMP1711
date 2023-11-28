// Write a programme that creates the file 'squares.dat' and writes to it the squares of the positive integers
// from 1 to n, where n is providedas input by the user

#include <stdio.h>

int main(){
    char* filename = "squares.dat";
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    unsigned input_num;

    printf("Enter the upper boundary of your squares set: ");
    scanf("%u", &input_num);

    printf("Your file has been updated!\n");

    for(int i = 1; i <= input_num;){
        int squares = i * i;
        i++;
        fprintf(file, "%i\n", squares);
    }

    fclose(file);
    return 0;
    
}