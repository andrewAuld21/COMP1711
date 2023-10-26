#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

//strcpy (string copy) copies the string in the " " into the structure. Meaning you're telling it to put "Name Surname"
//into the name section (.name) of new_student (which uses the student structure)
int main () {
    struct student new_student;
    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902178");

    printf("Enter the student's mark: ");
    scanf("%u", &new_student.mark);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}