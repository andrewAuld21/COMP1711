#include <stdio.h>

int calculator(float num1, float num2, char operator){
    switch(operator)
    {
        case '+':  return num1 + num2;
        break;

        case '-':  return num1 - num2;
        break;

        case '*':  return num1 * num2;
        break;

        case '/':  if(num2 != 0) return num1 / num2;
        break; 
    }
    return 0;
}

int main(){
    float num1;
    float num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    printf("Select your operation: ");
    scanf(" %c", &operator);

    float result = calculator(num1, num2, operator);
    
    printf("The result of the operation is: %.2f\n", result);

    return 0;

}