#include<stdio.h>
#include<string.h>


int main (){

    char hello = 'r';
    printf("the ACII value  of hello is %d\n", hello);
    printf("the CHAR value  of hello is %c\n", hello);

    char abc[5] = "Hello";
    // this print the inter value
    printf("the value is %s\n", abc);
    // this print the single char
    printf("the value is %c\n", abc[1]);
    // measure lenght of the string
    printf("the lenght of the string is %ld\n", strlen(abc));
    char override [4] = "w";
    strcpy(override, "aa");
    printf("the value is %s\n", override);

    char msg[] = "hello";
    char other[] = "bye";
    strcpy(other, msg);
    printf("%s\n%s\n", msg, other);
    printf("%ld\n", sizeof(other));
    char compare[6] = "Hello";
    if(!strcmp(compare, "Hello")){
        printf("Equals");
    }   
    // SAFER COPY
    char safe_copy [] = "safe";
    char copy [4] = "cop";
    // YOU CAN ADD A LIMIT
    strlcpy(copy, safe_copy, 2);
    printf("The safe copy is %s\n", copy );
    char str[64];
    // YOU READ FROM A STANDARD KEYBOARD
    //fgets(str, 64, stdin);
    printf("%s\n", str);


    // IT IS NOT SAFE 
    char one[10] = "abc";
    one[4] = 'p';
    printf("%s\n", one);
    char rqw[10] = "abc";
    printf("%s\n", rqw);
    printf("%c\n", (int) 'g');

    // STRANGE ASSIGNEMENT
    char strange [10] = "Str";
    strange [8] = "a";
    printf("%s\n", strange);
    strcat(strange,"ps");
    printf("%s\n", strange);
    






}