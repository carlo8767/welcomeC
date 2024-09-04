#include<stdio.h>
#include<stdlib.h>

int fileScopeStatic = 10;
// static object must initialized 
// with a const value
const int increment =10;

void increamentValue(void){
    fileScopeStatic++;
}


void functionScope (char blockScopeName [] ){
    char blockScope [] = "This is a block scope";
    printf("%s""\n", blockScopeName);
     printf("%s""%d" "\n", "The value file scope is change ", fileScopeStatic);
}


int main (void){
    fileScopeStatic = 9;
    increamentValue();
    printf("%s" "%d""\n", "This is a file scope ",fileScopeStatic);
    char functionScopeArray [] = "Function Scope";
    functionScope(functionScopeArray);
    
}
