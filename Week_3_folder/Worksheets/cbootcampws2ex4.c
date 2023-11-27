#include <stdio.h>

int isPrime(int input_num){

    if (input_num < 2){
        return 0;
    }
    
    for (int i = 2, i < input_num; i++){
        if (input_num % i == 0){
            return 0;
        }
    }

    return 1;
}