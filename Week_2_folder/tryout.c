#include <stdio.h>

int main(){

    int numero;
    int answer;

    printf("Enter your number: ");
    scanf("%i", &numero);

    answer = numero % 2;

    printf("The answer is %i\n", answer);

    return 0;
}