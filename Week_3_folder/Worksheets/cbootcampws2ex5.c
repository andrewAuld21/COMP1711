#include <stdio.h>

char*  concatStrings(char *str1, char *str2){
    int len1 = 0;
    
    while (str1[len1] != '\0'){
        len1++;
    }

    int len2 = 0;

    while(str2[len2] != '\0'){
        len2++;
    }

    static char result[500];

    for(int i = 0; i < 2; i++){
        result[len1 + i] = str2[i];
    }

    result[len1 + len2] = '\0';

    return result;
}

int main(){
    char *str1 = "Hello ";
    char *str2 = "everybody!";
    char *new_string = concatStrings(str1, str2);

    printf("The concatenated string is %s\n", new_string);

    return 0;
}