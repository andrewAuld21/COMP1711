#include <stdio.h>

//TYPEDEF is similar to a structure except it's a template, it is used to define a definition for a struct

//As usual, the size of the array is not needed if entries are initialised
typedef struct {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
} student;

int main () {
    // Data generated using ChatGPT.
    int number_of_students = 10, i;
    student students [] = {
        {"Alice Smith",    "64827593", 67},
        {"Bob Johnson",    "19374650", 89},
        {"Charlie Brown",  "82056914", 76},
        {"David Davis",    "45790182", 44},
        {"Eve Wilson",     "36102478", 91},
        {"Frank Anderson", "93571826", 53},
        {"Grace Lee",      "50249867", 78},
        {"Hannah Clark",   "74820591", 62},
        {"Isaac Harris",   "61093745", 89},
        {"Jack White",     "92847501", 72},
    };

    //in this loop, 'i' represents the row number
    for (i = 0; i < number_of_students; i++) {
        printf("-------------\n");
        printf("Student name: %s\n", students[i].name);
        printf("Student ID: %s\n", students[i].student_id);
        printf("Final mark: %u\n", students[i].mark);
    }
    printf("-------------\n");
    return 0;
}