#include <stdio.h>
#include <stdbool.h>

bool terminProgram = true;
const char optionFahreneitCelsius [] = "Which conversion do you want?";
const char  askInsertFahrenit [] = "Please enter Fahrenheit";
const char askInsertCelsius [] = "Please enter Fahrenheit";
const char  continueAks [] = "Continue?";


double convertFahrenheit (double *fahrenheit){
    double celsius = (*fahrenheit -32)/1.8;
    return celsius;
}
double convertCelsius (double *celsious){
    double fahrenheit = (*celsious *1.8)+32;
    return fahrenheit;
}


int main (){

  

    printf("value of a_static: %s\n", optionFahreneitCelsius);
    /*

    bool terminProgram = true;
    char continueYesNo = "";
    while(terminProgram){
        printf("%s\n ", optionFahreneitCelsius);
        int answer;
        scanf("%d\n", answer);
        if(answer == 1){
            printf("%s\n ", askInsertFahrenit);
            double fahrenheit;
            scanf("%d\n", fahrenheit);
            convertFahrenheit(*fahrenheit);
        }
        else {
            printf("%s\n ", askInsertCelsius);
            double celsious;
            convertCelsius(*celsious)
        }
           printf("%s\n ", continueAks);
            scanf("%s\n", continueYesNo);
           if(continueYesNo == 'Yes'){
                continue;
           }
           else {
             terminProgram = false;
           }


    }   
*/
    return 0;
}