#include <stdio.h>

int isPrime(int n){
    if (n <= 1){
        return 0;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int number;

    printf("Please enter a number: ");
    scanf("%i", &number);

    if (isPrime(number)){
        printf("%i is a prime number\n", number);
    }else{
        printf("%i is not a prime number\n", number);
    }
    return 0;
}