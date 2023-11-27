#include <stdio.h>

int str_len(char *string1){

    int length = 0;
    
    while(*string1 != "\0"){
        length++;
        string1++;
    }

    return length;
}

int main(){

    int length = str_len("Hello World!");
    printf("The length of the string is %i\n", length);

    return 0;
}