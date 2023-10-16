#include <stdio.h>

int main() {

    int mark;

    //Add in:
    //Checking that the value is over 60 for a 2:1
    //Checking that the value is over 70 for a first
    //Checking that the value is a valid mark (between 0 and 100)

    printf ("Enter the mark: \n");
    scanf ("%d", &mark);

    if (mark > 100 || mark < 0)
    {
        printf ("The mark of %d is not a valid mark\n", mark);
    }
    else if (mark == 0)
    {
        printf ("The mark of %d is zero\n", mark);
    }
    else if (mark < 40)
    {
        printf ("The mark of %d is a fail\n", mark);
    }
    else if (mark < 60)
    {
        printf("The mark of %d is a pass\n", mark);
    }
    else if (mark < 70)
    {
        printf("The mark of %d is a 2:1\n", mark);
    }
    else if (mark < 100)
    {
        printf ("The mark of %d is a first\n", mark);
    }

    return 0;
}
//It doesn't matter if you do > or <, but you once you choose you need to do all of them in the same format
