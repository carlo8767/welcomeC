#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int signedInteger = 93;

int addition (int a , int b){
    int addition = a+b;
    // VERIFY THAT THE ADDITION
    // DO NOT EXCEED THE MAX
    if(addition > UINT_MAX){
        return 0;
    }
    else {
        return addition;
    }

}

bool positive (int a){
    // CONDITIONAL OPERATOR
    bool result = a>0?true:false;
    return result;
}

float floatSumAssociative (float a, float b){
    return (a * b);
}

int main (){

    signed int giveMeSize = 19;
    float giveFloatSize = 19.19F;
    // ZU YOU HAVE TO USE IN COMBINATION OF SIZE OF
    printf("The size of integer is %zu\n", sizeof(giveMeSize));
    printf("The size of float is is %zu\n", sizeof(giveFloatSize));
    bool verification = positive(giveMeSize);
    // CAST
    int cast = (int)giveFloatSize;
    printf("The int is ""%d\n", cast);

    float first = 20.19F;
    float second = 15.19F;
    float returnFirstSum = floatSumNotAssociative(first, second);
    float returnSecondSum = floatSumNotAssociative(second, first);
    printf("The first sum result in %f\n""and the second sum result in %f\n", returnFirstSum, returnSecondSum);
    return 0;
}