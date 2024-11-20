#include <stdio.h>
#include <stdbool.h>


int main () {

    int verification = 2;

    while(verification){
        printf("The verification is %d\n", verification);
        if(verification == 3){
            break;
        }
        verification+=1;
    }
    for(int i =1; i<10; i*=2){
        printf("The value of i is %d\n", i);
        i+=1;
    }

}

