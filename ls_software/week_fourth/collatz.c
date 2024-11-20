#include <stdio.h>
#include <stdbool.h>


void collatz (){
    bool control = true;
    int random;
    scanf("%d", &random);
    while(control){
        if(random == 1){
            printf("The number is %d \n ", random);
            break;
        }
        else if (random %2 == 0){
            random = random / 2;
            printf("The number is odd and value is %d\n ", random);
        }
        else {
            random *= 3+1;
            printf("The number is even amd value is %d\n ", random);
        }
    }
}




int main (){

    collatz ();
    return 0;
}